/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Scott Shawcroft for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_RASPBERRYPI_COMMON_HAL_BUSIO_I2C_H
#define MICROPY_INCLUDED_RASPBERRYPI_COMMON_HAL_BUSIO_I2C_H

#include "common-hal/microcontroller/Pin.h"
#include "shared-module/bitbangio/I2C.h"

#include "py/obj.h"

#include "src/rp2_common/hardware_i2c/include/hardware/i2c.h"

typedef struct {
    mp_obj_base_t base;
    i2c_inst_t *peripheral;
    bitbangio_i2c_obj_t bitbangio_i2c;
    bool has_lock;
    uint baudrate;
    uint8_t scl_pin;
    uint8_t sda_pin;
} busio_i2c_obj_t;

void reset_i2c(void);

#endif // MICROPY_INCLUDED_RASPBERRYPI_COMMON_HAL_BUSIO_I2C_H
