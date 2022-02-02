/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 microDev
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

#include "shared-bindings/microcontroller/Pin.h"
#include "supervisor/board.h"

void board_init(void) {
    // USB
    common_hal_never_reset_pin(&pin_GPIO18);
    common_hal_never_reset_pin(&pin_GPIO19);

    // Debug UART
    #ifdef DEBUG
    common_hal_never_reset_pin(&pin_GPIO20);
    common_hal_never_reset_pin(&pin_GPIO21);
    #endif

    // SPI Flash
    common_hal_never_reset_pin(&pin_GPIO11);
    common_hal_never_reset_pin(&pin_GPIO12);
    common_hal_never_reset_pin(&pin_GPIO13);
    common_hal_never_reset_pin(&pin_GPIO14);
    common_hal_never_reset_pin(&pin_GPIO15);
    common_hal_never_reset_pin(&pin_GPIO16);
    common_hal_never_reset_pin(&pin_GPIO17);
}

bool board_requests_safe_mode(void) {
    return false;
}

void reset_board(void) {
}

#if CIRCUITPY_ALARM
void board_deinit(void) {
}
#endif
