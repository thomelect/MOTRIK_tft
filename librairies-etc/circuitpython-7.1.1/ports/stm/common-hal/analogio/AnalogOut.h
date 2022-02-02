/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Scott Shawcroft
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

#ifndef MICROPY_INCLUDED_STM32F4_COMMON_HAL_ANALOGIO_ANALOGOUT_H
#define MICROPY_INCLUDED_STM32F4_COMMON_HAL_ANALOGIO_ANALOGOUT_H

#include "common-hal/microcontroller/Pin.h"

#include "py/obj.h"
#if CPY_STM32L4
#include "stm32l4xx_hal.h"
#else
#include "stm32f4xx_hal.h"
#endif
#include "peripherals/periph.h"

typedef struct {
    mp_obj_base_t base;
    #if HAS_DAC
    DAC_ChannelConfTypeDef ch_handle;
    #endif
    const mcu_pin_obj_t *pin;
    uint8_t channel;
    uint8_t dac_index : 1;
} analogio_analogout_obj_t;

void analogout_reset(void);

#endif // MICROPY_INCLUDED_STM32F4_COMMON_HAL_ANALOGIO_ANALOGOUT_H
