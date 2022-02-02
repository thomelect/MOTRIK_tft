#include "shared-bindings/vectorio/Rectangle.h"
#include "shared-module/displayio/area.h"

#include "py/runtime.h"


void common_hal_vectorio_rectangle_construct(vectorio_rectangle_t *self, uint32_t width, uint32_t height) {
    self->width = width;
    self->height = height;
}


uint32_t common_hal_vectorio_rectangle_get_pixel(void *obj, int16_t x, int16_t y) {
    vectorio_rectangle_t *self = obj;
    if (x >= 0 && y >= 0 && x < self->width && y < self->height) {
        return 1;
    }
    return 0;
}


void common_hal_vectorio_rectangle_get_area(void *rectangle, displayio_area_t *out_area) {
    vectorio_rectangle_t *self = rectangle;
    out_area->x1 = 0;
    out_area->y1 = 0;
    out_area->x2 = self->width;
    out_area->y2 = self->height;
}


mp_obj_t common_hal_vectorio_rectangle_get_draw_protocol(void *rectangle) {
    vectorio_rectangle_t *self = rectangle;
    return self->draw_protocol_instance;
}
