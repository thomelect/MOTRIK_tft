/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_SUPERVISOR_STACK_H
#define MICROPY_INCLUDED_SUPERVISOR_STACK_H

#include <stddef.h>

#include "supervisor/memory.h"

void stack_init(void);
void stack_resize(void);
// Actual stack location and size, may be larger than requested.
uint32_t *stack_get_bottom(void);
size_t stack_get_length(void);
// Next/current requested stack size.
void set_next_stack_size(uint32_t size);
uint32_t get_current_stack_size(void);
bool stack_ok(void);

// Use this after any calls into a library which may use a lot of stack. This will raise a Python
// exception when the stack has likely overwritten a portion of the heap.
void assert_heap_ok(void);

#ifndef STACK_CANARY_VALUE
#define STACK_CANARY_VALUE 0x017829ef
#endif

#endif  // MICROPY_INCLUDED_SUPERVISOR_STACK_H
