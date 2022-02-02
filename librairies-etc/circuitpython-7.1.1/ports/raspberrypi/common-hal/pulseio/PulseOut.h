/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Dave Putz for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_PULSEIO_PULSEOUT_H
#define MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_PULSEIO_PULSEOUT_H

#include "common-hal/microcontroller/Pin.h"
#include "common-hal/pwmio/PWMOut.h"
#include "src/common/pico_time/include/pico/time.h"

#include "py/obj.h"

#define NO_PIN 0xff

typedef struct {
    mp_obj_base_t base;
    uint8_t pin;
    uint8_t slice;
    pwmio_pwmout_obj_t carrier;
    uint16_t *pulse_buffer;
    uint16_t pulse_length;
    uint32_t min_pulse;
    volatile uint16_t pulse_index;
} pulseio_pulseout_obj_t;

void pulseout_reset(void);
int64_t pulseout_interrupt_handler(alarm_id_t id, void *user_data);

#endif // MICROPY_INCLUDED_ATMEL SAMD_COMMON_HAL_PULSEIO_PULSEOUT_H
