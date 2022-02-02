/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft for Adafruit Industries
 * Copyright (c) 2019 Jeff Epler for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>

#include "shared/runtime/context_manager_helpers.h"
#include "py/objproperty.h"
#include "py/runtime.h"
#include "shared-bindings/audiomp3/MP3Decoder.h"
#include "shared-bindings/util.h"
#include "supervisor/shared/translate.h"

//| class MP3Decoder:
//|     """Load a mp3 file for audio playback"""
//|
//|     def __init__(self, file: typing.BinaryIO, buffer: WriteableBuffer) -> None:
//|
//|         """Load a .mp3 file for playback with `audioio.AudioOut` or `audiobusio.I2SOut`.
//|
//|         :param typing.BinaryIO file: Already opened mp3 file
//|         :param ~_typing.WriteableBuffer buffer: Optional pre-allocated buffer, that will be split in half and used for double-buffering of the data. If not provided, two buffers are allocated internally.  The specific buffer size required depends on the mp3 file.
//|
//|
//|         Playing a mp3 file from flash::
//|
//|           import board
//|           import audiomp3
//|           import audioio
//|           import digitalio
//|
//|           # Required for CircuitPlayground Express
//|           speaker_enable = digitalio.DigitalInOut(board.SPEAKER_ENABLE)
//|           speaker_enable.switch_to_output(value=True)
//|
//|           data = open("cplay-16bit-16khz-64kbps.mp3", "rb")
//|           mp3 = audiomp3.MP3Decoder(data)
//|           a = audioio.AudioOut(board.A0)
//|
//|           print("playing")
//|           a.play(mp3)
//|           while a.playing:
//|             pass
//|           print("stopped")"""
//|         ...
//|
STATIC mp_obj_t audiomp3_mp3file_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 1, 2, false);

    audiomp3_mp3file_obj_t *self = m_new_obj(audiomp3_mp3file_obj_t);
    self->base.type = &audiomp3_mp3file_type;
    if (!mp_obj_is_type(args[0], &mp_type_fileio)) {
        mp_raise_TypeError(translate("file must be a file opened in byte mode"));
    }
    uint8_t *buffer = NULL;
    size_t buffer_size = 0;
    if (n_args >= 2) {
        mp_buffer_info_t bufinfo;
        mp_get_buffer_raise(args[1], &bufinfo, MP_BUFFER_WRITE);
        buffer = bufinfo.buf;
        buffer_size = bufinfo.len;
    }
    common_hal_audiomp3_mp3file_construct(self, MP_OBJ_TO_PTR(args[0]),
        buffer, buffer_size);

    return MP_OBJ_FROM_PTR(self);
}

//|     def deinit(self) -> None:
//|         """Deinitialises the MP3 and releases all memory resources for reuse."""
//|         ...
//|
STATIC mp_obj_t audiomp3_mp3file_deinit(mp_obj_t self_in) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    common_hal_audiomp3_mp3file_deinit(self);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(audiomp3_mp3file_deinit_obj, audiomp3_mp3file_deinit);

STATIC void check_for_deinit(audiomp3_mp3file_obj_t *self) {
    if (common_hal_audiomp3_mp3file_deinited(self)) {
        raise_deinited_error();
    }
}

//|     def __enter__(self) -> MP3Decoder:
//|         """No-op used by Context Managers."""
//|         ...
//|
//  Provided by context manager helper.

//|     def __exit__(self) -> None:
//|         """Automatically deinitializes the hardware when exiting a context. See
//|         :ref:`lifetime-and-contextmanagers` for more info."""
//|         ...
//|
STATIC mp_obj_t audiomp3_mp3file_obj___exit__(size_t n_args, const mp_obj_t *args) {
    (void)n_args;
    common_hal_audiomp3_mp3file_deinit(args[0]);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(audiomp3_mp3file___exit___obj, 4, 4, audiomp3_mp3file_obj___exit__);

//|     file: typing.BinaryIO
//|     """File to play back."""
//|
STATIC mp_obj_t audiomp3_mp3file_obj_get_file(mp_obj_t self_in) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    return self->file;
}
MP_DEFINE_CONST_FUN_OBJ_1(audiomp3_mp3file_get_file_obj, audiomp3_mp3file_obj_get_file);

STATIC mp_obj_t audiomp3_mp3file_obj_set_file(mp_obj_t self_in, mp_obj_t file) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    if (!mp_obj_is_type(file, &mp_type_fileio)) {
        mp_raise_TypeError(translate("file must be a file opened in byte mode"));
    }
    common_hal_audiomp3_mp3file_set_file(self, file);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(audiomp3_mp3file_set_file_obj, audiomp3_mp3file_obj_set_file);

const mp_obj_property_t audiomp3_mp3file_file_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&audiomp3_mp3file_get_file_obj,
              (mp_obj_t)&audiomp3_mp3file_set_file_obj,
              MP_ROM_NONE},
};



//|     sample_rate: int
//|     """32 bit value that dictates how quickly samples are loaded into the DAC
//|     in Hertz (cycles per second). When the sample is looped, this can change
//|     the pitch output without changing the underlying sample."""
//|
STATIC mp_obj_t audiomp3_mp3file_obj_get_sample_rate(mp_obj_t self_in) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    return MP_OBJ_NEW_SMALL_INT(common_hal_audiomp3_mp3file_get_sample_rate(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(audiomp3_mp3file_get_sample_rate_obj, audiomp3_mp3file_obj_get_sample_rate);

STATIC mp_obj_t audiomp3_mp3file_obj_set_sample_rate(mp_obj_t self_in, mp_obj_t sample_rate) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    common_hal_audiomp3_mp3file_set_sample_rate(self, mp_obj_get_int(sample_rate));
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(audiomp3_mp3file_set_sample_rate_obj, audiomp3_mp3file_obj_set_sample_rate);

const mp_obj_property_t audiomp3_mp3file_sample_rate_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&audiomp3_mp3file_get_sample_rate_obj,
              (mp_obj_t)&audiomp3_mp3file_set_sample_rate_obj,
              MP_ROM_NONE},
};

//|     bits_per_sample: int
//|     """Bits per sample. (read only)"""
//|
STATIC mp_obj_t audiomp3_mp3file_obj_get_bits_per_sample(mp_obj_t self_in) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    return MP_OBJ_NEW_SMALL_INT(common_hal_audiomp3_mp3file_get_bits_per_sample(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(audiomp3_mp3file_get_bits_per_sample_obj, audiomp3_mp3file_obj_get_bits_per_sample);

const mp_obj_property_t audiomp3_mp3file_bits_per_sample_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&audiomp3_mp3file_get_bits_per_sample_obj,
              MP_ROM_NONE,
              MP_ROM_NONE},
};

//|     channel_count: int
//|     """Number of audio channels. (read only)"""
//|
STATIC mp_obj_t audiomp3_mp3file_obj_get_channel_count(mp_obj_t self_in) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    return MP_OBJ_NEW_SMALL_INT(common_hal_audiomp3_mp3file_get_channel_count(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(audiomp3_mp3file_get_channel_count_obj, audiomp3_mp3file_obj_get_channel_count);

const mp_obj_property_t audiomp3_mp3file_channel_count_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&audiomp3_mp3file_get_channel_count_obj,
              MP_ROM_NONE,
              MP_ROM_NONE},
};

//|     rms_level: float
//|     """The RMS audio level of a recently played moment of audio. (read only)"""
//|
STATIC mp_obj_t audiomp3_mp3file_obj_get_rms_level(mp_obj_t self_in) {
    audiomp3_mp3file_obj_t *self = MP_OBJ_TO_PTR(self_in);
    check_for_deinit(self);
    return mp_obj_new_float(common_hal_audiomp3_mp3file_get_rms_level(self));
}
MP_DEFINE_CONST_FUN_OBJ_1(audiomp3_mp3file_get_rms_level_obj, audiomp3_mp3file_obj_get_rms_level);

const mp_obj_property_t audiomp3_mp3file_rms_level_obj = {
    .base.type = &mp_type_property,
    .proxy = {(mp_obj_t)&audiomp3_mp3file_get_rms_level_obj,
              MP_ROM_NONE,
              MP_ROM_NONE},
};


STATIC const mp_rom_map_elem_t audiomp3_mp3file_locals_dict_table[] = {
    // Methods
    { MP_ROM_QSTR(MP_QSTR_deinit), MP_ROM_PTR(&audiomp3_mp3file_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__), MP_ROM_PTR(&audiomp3_mp3file___exit___obj) },

    // Properties
    { MP_ROM_QSTR(MP_QSTR_file), MP_ROM_PTR(&audiomp3_mp3file_file_obj) },
    { MP_ROM_QSTR(MP_QSTR_sample_rate), MP_ROM_PTR(&audiomp3_mp3file_sample_rate_obj) },
    { MP_ROM_QSTR(MP_QSTR_bits_per_sample), MP_ROM_PTR(&audiomp3_mp3file_bits_per_sample_obj) },
    { MP_ROM_QSTR(MP_QSTR_channel_count), MP_ROM_PTR(&audiomp3_mp3file_channel_count_obj) },
    { MP_ROM_QSTR(MP_QSTR_rms_level), MP_ROM_PTR(&audiomp3_mp3file_rms_level_obj) },
};
STATIC MP_DEFINE_CONST_DICT(audiomp3_mp3file_locals_dict, audiomp3_mp3file_locals_dict_table);

STATIC const audiosample_p_t audiomp3_mp3file_proto = {
    MP_PROTO_IMPLEMENT(MP_QSTR_protocol_audiosample)
    .sample_rate = (audiosample_sample_rate_fun)common_hal_audiomp3_mp3file_get_sample_rate,
    .bits_per_sample = (audiosample_bits_per_sample_fun)common_hal_audiomp3_mp3file_get_bits_per_sample,
    .channel_count = (audiosample_channel_count_fun)common_hal_audiomp3_mp3file_get_channel_count,
    .reset_buffer = (audiosample_reset_buffer_fun)audiomp3_mp3file_reset_buffer,
    .get_buffer = (audiosample_get_buffer_fun)audiomp3_mp3file_get_buffer,
    .get_buffer_structure = (audiosample_get_buffer_structure_fun)audiomp3_mp3file_get_buffer_structure,
};

const mp_obj_type_t audiomp3_mp3file_type = {
    { &mp_type_type },
    .name = MP_QSTR_MP3Decoder,
    .flags = MP_TYPE_FLAG_EXTENDED,
    .make_new = audiomp3_mp3file_make_new,
    .locals_dict = (mp_obj_dict_t *)&audiomp3_mp3file_locals_dict,
    MP_TYPE_EXTENDED_FIELDS(
        .protocol = &audiomp3_mp3file_proto,
        ),
};
