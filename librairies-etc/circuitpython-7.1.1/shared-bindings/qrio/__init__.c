/*
 * This file is part of the CircuitPython project, https://github.com/adafruit/circuitpython
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Jeff Epler
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

#include "shared-bindings/qrio/__init__.h"
#include "shared-bindings/qrio/QRDecoder.h"
#include "shared-bindings/qrio/QRInfo.h"
#include "shared-bindings/qrio/PixelPolicy.h"
#include "py/obj.h"
#include "py/enum.h"

//| """`qrio` module.
//|
//| Provides the `QRDecoder` object."""
//|

STATIC const mp_rom_map_elem_t qrio_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_qrio) },
    { MP_ROM_QSTR(MP_QSTR_QRInfo), MP_ROM_PTR(&qrio_qrinfo_type_obj) },
    { MP_ROM_QSTR(MP_QSTR_QRDecoder), MP_ROM_PTR(&qrio_qrdecoder_type_obj) },
    { MP_ROM_QSTR(MP_QSTR_PixelPolicy), MP_ROM_PTR(&qrio_pixel_policy_type) },
};

STATIC MP_DEFINE_CONST_DICT(qrio_module_globals, qrio_module_globals_table);

const mp_obj_module_t qrio_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&qrio_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_qrio, qrio_module, CIRCUITPY_QRIO);
