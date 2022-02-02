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
#include "shared-bindings/qrio/PixelPolicy.h"
#include "py/obj.h"
#include "py/enum.h"

//| class PixelPolicy:
//|     EVERY_BYTE: PixelPolicy
//|     """The input buffer to `QRDecoder.decode` consists of greyscale values in every byte"""
//|
//|     EVEN_BYTES: PixelPolicy
//|     """The input buffer to `QRDecoder.decode` consists of greyscale values in positions 0, 2, …, and ignored bytes in positions 1, 3, ….  This can decode directly from YUV images where the even bytes hold the Y (luminance) data."""
//|
//|     ODD_BYTES: PixelPolicy
//|     """The input buffer to `QRDecoder.decode` consists of greyscale values in positions 1, 3, …, and ignored bytes in positions 0, 2, ….  This can decode directly from YUV images where the odd bytes hold the Y (luminance) data"""
//|

MAKE_ENUM_VALUE(qrio_pixel_policy_type, qrio_pixel_policy, EVERY_BYTE, QRIO_EVERY_BYTE);
MAKE_ENUM_VALUE(qrio_pixel_policy_type, qrio_pixel_policy, EVEN_BYTES, QRIO_EVEN_BYTES);
MAKE_ENUM_VALUE(qrio_pixel_policy_type, qrio_pixel_policy, ODD_BYTES, QRIO_EVEN_BYTES);

MAKE_ENUM_MAP(qrio_pixel_policy) {
    MAKE_ENUM_MAP_ENTRY(qrio_pixel_policy, EVERY_BYTE),
    MAKE_ENUM_MAP_ENTRY(qrio_pixel_policy, EVEN_BYTES),
    MAKE_ENUM_MAP_ENTRY(qrio_pixel_policy, ODD_BYTES),
};
STATIC MP_DEFINE_CONST_DICT(qrio_pixel_policy_locals_dict, qrio_pixel_policy_locals_table);

MAKE_PRINTER(qrio, qrio_pixel_policy);

MAKE_ENUM_TYPE(qrio, PixelPolicy, qrio_pixel_policy);
