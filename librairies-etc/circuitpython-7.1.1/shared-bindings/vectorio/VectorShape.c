
#include "shared-module/vectorio/__init__.h"
#include "shared-bindings/vectorio/VectorShape.h"
#include "shared-bindings/vectorio/Circle.h"
#include "shared-bindings/vectorio/Polygon.h"
#include "shared-bindings/vectorio/Rectangle.h"

#include "shared-bindings/displayio/ColorConverter.h"
#include "shared-bindings/displayio/Palette.h"

#include <stdint.h>

#include "shared/runtime/context_manager_helpers.h"

#include "py/binary.h"
#include "py/objproperty.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "supervisor/shared/translate.h"


// shape: The shape implementation to draw.
// pixel_shader: The pixel shader that produces colors from values. The shader can be a displayio.Palette(1); it will be asked to color pixel value 0.
// x: Initial x position of the center axis of the shape within the parent.
// y: Initial y position of the center axis of the shape within the parent."""
mp_obj_t vectorio_vector_shape_make_new(const mp_obj_t shape, const mp_obj_t pixel_shader, int32_t x, int32_t y) {
    if (!mp_obj_is_type(pixel_shader, &displayio_colorconverter_type) &&
        !mp_obj_is_type(pixel_shader, &displayio_palette_type)) {
        mp_raise_TypeError_varg(translate("unsupported %q type"), MP_QSTR_pixel_shader);
    }

    vectorio_ishape_t ishape;
    // Wire up shape functions
    if (mp_obj_is_type(shape, &vectorio_polygon_type)) {
        ishape.shape = shape;
        ishape.get_area = &common_hal_vectorio_polygon_get_area;
        ishape.get_pixel = &common_hal_vectorio_polygon_get_pixel;
    } else if (mp_obj_is_type(shape, &vectorio_rectangle_type)) {
        ishape.shape = shape;
        ishape.get_area = &common_hal_vectorio_rectangle_get_area;
        ishape.get_pixel = &common_hal_vectorio_rectangle_get_pixel;
    } else if (mp_obj_is_type(shape, &vectorio_circle_type)) {
        ishape.shape = shape;
        ishape.get_area = &common_hal_vectorio_circle_get_area;
        ishape.get_pixel = &common_hal_vectorio_circle_get_pixel;
    } else {
        mp_raise_TypeError_varg(translate("unsupported %q type"), MP_QSTR_shape);
    }

    vectorio_vector_shape_t *self = m_new_obj(vectorio_vector_shape_t);
    self->base.type = &vectorio_vector_shape_type;
    common_hal_vectorio_vector_shape_construct(self,
        ishape, pixel_shader, x, y
        );

    // Wire up event callbacks
    vectorio_event_t on_dirty = {
        .obj = self,
        .event = &common_hal_vectorio_vector_shape_set_dirty
    };

    if (mp_obj_is_type(shape, &vectorio_polygon_type)) {
        common_hal_vectorio_polygon_set_on_dirty(self->ishape.shape, on_dirty);
    } else if (mp_obj_is_type(shape, &vectorio_rectangle_type)) {
    } else if (mp_obj_is_type(shape, &vectorio_circle_type)) {
        common_hal_vectorio_circle_set_on_dirty(self->ishape.shape, on_dirty);
    } else {
        mp_raise_TypeError_varg(translate("unsupported %q type"), MP_QSTR_shape);
    }

    return MP_OBJ_FROM_PTR(self);
}

vectorio_draw_protocol_impl_t vectorio_vector_shape_draw_protocol_impl = {
    .draw_fill_area = (draw_fill_area_fun)vectorio_vector_shape_fill_area,
    .draw_get_dirty_area = (draw_get_dirty_area_fun)vectorio_vector_shape_get_dirty_area,
    .draw_update_transform = (draw_update_transform_fun)vectorio_vector_shape_update_transform,
    .draw_finish_refresh = (draw_finish_refresh_fun)vectorio_vector_shape_finish_refresh,
    .draw_get_refresh_areas = (draw_get_refresh_areas_fun)vectorio_vector_shape_get_refresh_areas,
};


// Stub checker does not approve of these shared properties.
//     x: int
//     """X position of the center point of the shape in the parent."""
//
STATIC mp_obj_t vectorio_vector_shape_obj_get_x(mp_obj_t wrapper_shape) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    return MP_OBJ_NEW_SMALL_INT(common_hal_vectorio_vector_shape_get_x(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(vectorio_vector_shape_get_x_obj, vectorio_vector_shape_obj_get_x);

STATIC mp_obj_t vectorio_vector_shape_obj_set_x(mp_obj_t wrapper_shape, mp_obj_t x_obj) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    mp_int_t x = mp_obj_get_int(x_obj);
    common_hal_vectorio_vector_shape_set_x(self, x);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(vectorio_vector_shape_set_x_obj, vectorio_vector_shape_obj_set_x);

const mp_obj_property_t vectorio_vector_shape_x_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&vectorio_vector_shape_get_x_obj,
              (mp_obj_t)&vectorio_vector_shape_set_x_obj,
              MP_ROM_NONE},
};


//     y: int
//     """Y position of the center point of the shape in the parent."""
//
STATIC mp_obj_t vectorio_vector_shape_obj_get_y(mp_obj_t wrapper_shape) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    return MP_OBJ_NEW_SMALL_INT(common_hal_vectorio_vector_shape_get_y(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(vectorio_vector_shape_get_y_obj, vectorio_vector_shape_obj_get_y);

STATIC mp_obj_t vectorio_vector_shape_obj_set_y(mp_obj_t wrapper_shape, mp_obj_t y_obj) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    mp_int_t y = mp_obj_get_int(y_obj);
    common_hal_vectorio_vector_shape_set_y(self, y);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(vectorio_vector_shape_set_y_obj, vectorio_vector_shape_obj_set_y);

const mp_obj_property_t vectorio_vector_shape_y_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&vectorio_vector_shape_get_y_obj,
              (mp_obj_t)&vectorio_vector_shape_set_y_obj,
              MP_ROM_NONE},
};


//     location: Tuple[int, int]
//     """location of the center point of the shape in the parent."""
//
STATIC mp_obj_t vectorio_vector_shape_obj_get_location(mp_obj_t wrapper_shape) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    return MP_OBJ_TO_PTR(common_hal_vectorio_vector_shape_get_location(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(vectorio_vector_shape_get_location_obj, vectorio_vector_shape_obj_get_location);

STATIC mp_obj_t vectorio_vector_shape_obj_set_location(mp_obj_t wrapper_shape, mp_obj_t location_obj) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    common_hal_vectorio_vector_shape_set_location(self, location_obj);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(vectorio_vector_shape_set_location_obj, vectorio_vector_shape_obj_set_location);

const mp_obj_property_t vectorio_vector_shape_location_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&vectorio_vector_shape_get_location_obj,
              (mp_obj_t)&vectorio_vector_shape_set_location_obj,
              MP_ROM_NONE},
};


//     pixel_shader: Union[ColorConverter, Palette]
//     """The pixel shader of the shape."""
//
STATIC mp_obj_t vectorio_vector_shape_obj_get_pixel_shader(mp_obj_t wrapper_shape) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    return common_hal_vectorio_vector_shape_get_pixel_shader(self);
}
MP_DEFINE_CONST_FUN_OBJ_1(vectorio_vector_shape_get_pixel_shader_obj, vectorio_vector_shape_obj_get_pixel_shader);

STATIC mp_obj_t vectorio_vector_shape_obj_set_pixel_shader(mp_obj_t wrapper_shape, mp_obj_t pixel_shader) {
    // Relies on the fact that only vector_shape impl gets matched with a VectorShape.
    const vectorio_draw_protocol_t *draw_protocol = mp_proto_get(MP_QSTR_protocol_draw, wrapper_shape);
    vectorio_vector_shape_t *self = MP_OBJ_TO_PTR(draw_protocol->draw_get_protocol_self(wrapper_shape));

    if (!mp_obj_is_type(pixel_shader, &displayio_palette_type) && !mp_obj_is_type(pixel_shader, &displayio_colorconverter_type)) {
        mp_raise_TypeError(translate("pixel_shader must be displayio.Palette or displayio.ColorConverter"));
    }

    common_hal_vectorio_vector_shape_set_pixel_shader(self, pixel_shader);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(vectorio_vector_shape_set_pixel_shader_obj, vectorio_vector_shape_obj_set_pixel_shader);

const mp_obj_property_t vectorio_vector_shape_pixel_shader_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&vectorio_vector_shape_get_pixel_shader_obj,
              (mp_obj_t)&vectorio_vector_shape_set_pixel_shader_obj,
              MP_ROM_NONE},
};


STATIC const mp_rom_map_elem_t vectorio_vector_shape_locals_dict_table[] = {
};
STATIC MP_DEFINE_CONST_DICT(vectorio_vector_shape_locals_dict, vectorio_vector_shape_locals_dict_table);

const mp_obj_type_t vectorio_vector_shape_type = {
    { &mp_type_type },
    .name = MP_QSTR_VectorShape,
    .locals_dict = (mp_obj_dict_t *)&vectorio_vector_shape_locals_dict,
};
