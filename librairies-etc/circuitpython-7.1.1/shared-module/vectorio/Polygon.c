#include "shared-module/vectorio/__init__.h"
#include "shared-bindings/vectorio/Polygon.h"
#include "shared-module/displayio/area.h"

#include "py/runtime.h"
#include "py/gc.h"

#include "stdlib.h"
#include <stdio.h>


#define VECTORIO_POLYGON_DEBUG(...) (void)0
// #define VECTORIO_POLYGON_DEBUG(...) mp_printf(&mp_plat_print, __VA_ARGS__)


// Converts a list of points tuples to a flat list of ints for speedier internal use.
// Also validates the points.
static void _clobber_points_list(vectorio_polygon_t *self, mp_obj_t points_tuple_list) {
    size_t len = 0;
    mp_obj_t *items;
    mp_obj_list_get(points_tuple_list, &len, &items);
    VECTORIO_POLYGON_DEBUG(" self.len: %d, len: %d, ", self->len, len);

    if (len < 3) {
        mp_raise_TypeError(translate("Polygon needs at least 3 points"));
    }

    if (self->len < 2 * len) {
        if (self->points_list != NULL) {
            VECTORIO_POLYGON_DEBUG("free(%d), ", sizeof(self->points_list));
            gc_free(self->points_list);
        }
        self->points_list = gc_alloc(2 * len * sizeof(uint16_t), false, false);
        VECTORIO_POLYGON_DEBUG("alloc(%p, %d)", self->points_list, 2 * len * sizeof(uint16_t));
    }
    self->len = 2 * len;

    for (uint16_t i = 0; i < len; ++i) {
        size_t tuple_len = 0;
        mp_obj_t *tuple_items;
        mp_obj_tuple_get(items[i], &tuple_len, &tuple_items);

        if (tuple_len != 2) {
            mp_raise_ValueError_varg(translate("%q must be a tuple of length 2"), MP_QSTR_point);
        }
        mp_int_t x;
        mp_int_t y;
        if (!mp_obj_get_int_maybe(tuple_items[ 0 ], &x)
            || !mp_obj_get_int_maybe(tuple_items[ 1 ], &y)
            || x < SHRT_MIN || x > SHRT_MAX || y < SHRT_MIN || y > SHRT_MAX
            ) {
            gc_free(self->points_list);
            self->points_list = NULL;
            mp_raise_ValueError_varg(translate("unsupported %q type"), MP_QSTR_point);
            self->len = 0;
        }
        self->points_list[2 * i    ] = (int16_t)x;
        self->points_list[2 * i + 1] = (int16_t)y;
    }
}



void common_hal_vectorio_polygon_construct(vectorio_polygon_t *self, mp_obj_t points_list) {
    VECTORIO_POLYGON_DEBUG("%p polygon_construct: ", self);
    self->points_list = NULL;
    self->len = 0;
    self->on_dirty.obj = NULL;
    _clobber_points_list(self, points_list);
    VECTORIO_POLYGON_DEBUG("\n");
}


mp_obj_t common_hal_vectorio_polygon_get_points(vectorio_polygon_t *self) {
    VECTORIO_POLYGON_DEBUG("%p common_hal_vectorio_polygon_get_points {len: %d, points_list: %p}\n", self, self->len, self->points_list);
    mp_obj_list_t *list = MP_OBJ_TO_PTR(mp_obj_new_list(0, NULL));

    VECTORIO_POLYGON_DEBUG("  >points\n");
    for (uint16_t i = 0; i < self->len; i += 2) {
        VECTORIO_POLYGON_DEBUG("    (%4d, %4d)\n", self->points_list[i], self->points_list[i + 1]);

        mp_obj_tuple_t *pair = MP_OBJ_TO_PTR(mp_obj_new_tuple(2, NULL));
        pair->items[0] = mp_obj_new_int((mp_int_t)self->points_list[i    ]);
        pair->items[1] = mp_obj_new_int((mp_int_t)self->points_list[i + 1]);

        mp_obj_list_append(
            list,
            pair
            );
    }
    VECTORIO_POLYGON_DEBUG("  <points\n");
    return MP_OBJ_FROM_PTR(list);
}
void common_hal_vectorio_polygon_set_points(vectorio_polygon_t *self, mp_obj_t points_list) {
    VECTORIO_POLYGON_DEBUG("%p common_hal_vectorio_polygon_set_points: ", self);
    _clobber_points_list(self, points_list);
    if (self->on_dirty.obj != NULL) {
        self->on_dirty.event(self->on_dirty.obj);
    }
    VECTORIO_POLYGON_DEBUG("\n");
}

void common_hal_vectorio_polygon_set_on_dirty(vectorio_polygon_t *self, vectorio_event_t notification) {
    if (self->on_dirty.obj != NULL) {
        mp_raise_TypeError(translate("polygon can only be registered in one parent"));
    }
    self->on_dirty = notification;
}


void common_hal_vectorio_polygon_get_area(void *polygon, displayio_area_t *area) {
    vectorio_polygon_t *self = polygon;
    VECTORIO_POLYGON_DEBUG("%p common_hal_vectorio_polygon_get_area\n");

    area->x1 = SHRT_MAX;
    area->y1 = SHRT_MAX;
    area->x2 = SHRT_MIN;
    area->y2 = SHRT_MIN;
    for (uint16_t i = 0; i < self->len; ++i) {
        int16_t x = self->points_list[i];
        ++i;
        int16_t y = self->points_list[i];
        if (x < area->x1) {
            VECTORIO_POLYGON_DEBUG("          x1: %d\n", x);
            area->x1 = x;
        }
        if (y < area->y1) {
            VECTORIO_POLYGON_DEBUG("          y1: %d\n", y);
            area->y1 = y;
        }
        if (x > area->x2) {
            VECTORIO_POLYGON_DEBUG("          x2: %d\n", x);
            area->x2 = x;
        }
        if (y > area->y2) {
            VECTORIO_POLYGON_DEBUG("          y2: %d\n", y);
            area->y2 = y;
        }
    }
}


// <0 if the point is to the left of the line vector
//  0 if the point is on the line
// >0 if the point is to the right of the line vector
__attribute__((always_inline)) static inline int line_side(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t px, int16_t py) {
    return (px - x1) * (y2 - y1)
           - (py - y1) * (x2 - x1);
}


uint32_t common_hal_vectorio_polygon_get_pixel(void *obj, int16_t x, int16_t y) {
    VECTORIO_POLYGON_DEBUG("%p polygon get_pixel %d, %d\n", obj, x, y);
    vectorio_polygon_t *self = obj;

    if (self->len == 0) {
        return 0;
    }

    int16_t winding_number = 0;
    int16_t x1 = self->points_list[0];
    int16_t y1 = self->points_list[1];
    for (uint16_t i = 2; i <= self->len + 1; ++i) {
        VECTORIO_POLYGON_DEBUG("  {(%3d, %3d),", x1, y1);
        int16_t x2 = self->points_list[i % self->len];
        ++i;
        int16_t y2 = self->points_list[i % self->len];
        VECTORIO_POLYGON_DEBUG(" (%3d, %3d)}\n", x2, y2);
        if (y1 <= y) {
            if (y2 > y && line_side(x1, y1, x2, y2, x, y) < 0) {
                // Wind up, point is to the left of the edge vector
                ++winding_number;
                VECTORIO_POLYGON_DEBUG("    wind:%2d winding_number:%2d\n", 1, winding_number);
            }
        } else if (y2 <= y && line_side(x1, y1, x2, y2, x, y) > 0) {
            // Wind down, point is to the right of the edge vector
            --winding_number;
            VECTORIO_POLYGON_DEBUG("    wind:%2d winding_number:%2d\n", -1, winding_number);
        }

        x1 = x2;
        y1 = y2;
    }
    return winding_number == 0 ? 0 : 1;
}

mp_obj_t common_hal_vectorio_polygon_get_draw_protocol(void *polygon) {
    vectorio_polygon_t *self = polygon;
    return self->draw_protocol_instance;
}
