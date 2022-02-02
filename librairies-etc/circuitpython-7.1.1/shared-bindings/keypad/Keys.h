/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Dan Halbert for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_SHARED_BINDINGS_KEYPAD_KEYS_H
#define MICROPY_INCLUDED_SHARED_BINDINGS_KEYPAD_KEYS_H

#include "py/objlist.h"
#include "shared-module/keypad/Keys.h"

extern const mp_obj_type_t keypad_keys_type;

void common_hal_keypad_keys_construct(keypad_keys_obj_t *self, mp_uint_t num_pins, const mcu_pin_obj_t *pins[], bool value_when_pressed,  bool pull, mp_float_t interval, size_t max_events);

void common_hal_keypad_keys_deinit(keypad_keys_obj_t *self);
bool common_hal_keypad_keys_deinited(keypad_keys_obj_t *self);

mp_obj_t common_hal_keypad_keys_get_events(keypad_keys_obj_t *self);
size_t common_hal_keypad_keys_get_key_count(keypad_keys_obj_t *self);
void common_hal_keypad_keys_reset(keypad_keys_obj_t *self);

#endif  // MICROPY_INCLUDED_SHARED_BINDINGS_KEYPAD_KEYS_H
