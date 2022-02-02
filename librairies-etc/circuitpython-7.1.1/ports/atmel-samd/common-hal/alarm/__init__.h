/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Lucian Copeland for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_ALARM__INIT__H
#define MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_ALARM__INIT__H

#include "common-hal/alarm/SleepMemory.h"

extern const alarm_sleep_memory_obj_t alarm_sleep_memory_obj;

// This is the first byte of the BKUP register bank.
// We use it to store which alarms are set.
#ifndef SAMD_ALARM_FLAG
#define SAMD_ALARM_FLAG      (RTC->MODE0.BKUP[0].reg)
#define SAMD_ALARM_FLAG_TIME (_U_(0x1) << 0)
#define SAMD_ALARM_FLAG_PIN  (_U_(0x1) << 1)
#endif

typedef enum {
    SAMD_WAKEUP_UNDEF,
    SAMD_WAKEUP_GPIO,
    SAMD_WAKEUP_RTC
} samd_sleep_source_t;

extern void alarm_set_wakeup_reason(samd_sleep_source_t reason);
samd_sleep_source_t alarm_get_wakeup_cause(void);
extern void alarm_reset(void);

#endif // MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_ALARM__INIT__H
