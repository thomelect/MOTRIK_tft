/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Lucian Copeland for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_ESPRESSIF_COMMON_HAL_PARALLELDISPLAY_PARALLELBUS_H
#define MICROPY_INCLUDED_ESPRESSIF_COMMON_HAL_PARALLELDISPLAY_PARALLELBUS_H

#include "common-hal/digitalio/DigitalInOut.h"
#include "i2s_lcd_driver.h"

typedef struct {
    mp_obj_base_t base;
    uint8_t read_pin_number;
    uint8_t reset_pin_number;
    i2s_lcd_config_t config;
    i2s_lcd_handle_t handle;
} paralleldisplay_parallelbus_obj_t;

#endif // MICROPY_INCLUDED_ESPRESSIF_COMMON_HAL_PARALLELDISPLAY_PARALLELBUS_H
