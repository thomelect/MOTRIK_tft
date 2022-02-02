/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Scott Shawcroft for Adafruit Industries
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

#include "py/obj.h"
#include "py/runtime.h"

#include "shared-bindings/terminalio/__init__.h"
#include "shared-bindings/terminalio/Terminal.h"
#include "supervisor/shared/display.h"

#include "py/runtime.h"

//| """Displays text in a TileGrid
//|
//| The `terminalio` module contains classes to display a character stream on a display. The built
//| in font is available as ``terminalio.FONT``."""
//|
//| FONT: fontio.BuiltinFont
//| """The built in font"""
//|
STATIC const mp_rom_map_elem_t terminalio_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_terminalio) },
    { MP_ROM_QSTR(MP_QSTR_Terminal),   MP_OBJ_FROM_PTR(&terminalio_terminal_type) },
    { MP_ROM_QSTR(MP_QSTR_FONT), MP_ROM_PTR(&supervisor_terminal_font) },
};


STATIC MP_DEFINE_CONST_DICT(terminalio_module_globals, terminalio_module_globals_table);

const mp_obj_module_t terminalio_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&terminalio_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_terminalio, terminalio_module, CIRCUITPY_DISPLAYIO && CIRCUITPY_TERMINALIO);
