/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 microDev
 * Copyright (c) 2021 skieast/Bruce Segal
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

// Board setup
#define MICROPY_HW_BOARD_NAME       "AITHinker ESP32-C3S_Kit"
#define MICROPY_HW_MCU_NAME         "ESP32-C3FN4"

// Status LED
#define MICROPY_HW_LED_STATUS       (&pin_GPIO19)

// Default bus pins
#define DEFAULT_UART_BUS_RX         (&pin_GPIO20)
#define DEFAULT_UART_BUS_TX         (&pin_GPIO21)

// Serial over UART
#define DEBUG_UART_RX               DEFAULT_UART_BUS_RX
#define DEBUG_UART_TX               DEFAULT_UART_BUS_TX

// For entering safe mode
#define CIRCUITPY_BOOT_BUTTON       (&pin_GPIO9)

// Explanation of how a user got into safe mode
#define BOARD_USER_SAFE_MODE_ACTION translate("pressing boot button at start up.\n")
