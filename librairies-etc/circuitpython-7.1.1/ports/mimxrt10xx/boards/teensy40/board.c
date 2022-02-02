/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Scott Shawcroft for Adafruit Industries
 * Copyright (c) 2019 Artur Pacholec
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

#include "supervisor/board.h"
#include "boards/flash_config.h"
#include "mpconfigboard.h"
#include "shared-bindings/microcontroller/Pin.h"

void board_init(void) {
    // FLEX flash
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_06);
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_07);
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_08);
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_09);
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_10);
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_11);

    // FLEX flash 2
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_04);
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_06);
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_07);
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_08);
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_09);
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_10);
    common_hal_never_reset_pin(&pin_GPIO_EMC_01);
    common_hal_never_reset_pin(&pin_GPIO_B0_13);
    common_hal_never_reset_pin(&pin_GPIO_AD_B0_11);
    // Data strobe needs protection despite being grounded
    common_hal_never_reset_pin(&pin_GPIO_SD_B1_05);
}

bool board_requests_safe_mode(void) {
    return false;
}

void reset_board(void) {
}

void board_deinit(void) {
}
