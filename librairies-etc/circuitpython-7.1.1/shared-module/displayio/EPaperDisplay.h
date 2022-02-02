/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Scott Shawcroft for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_EPAPERDISPLAY_H
#define MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_EPAPERDISPLAY_H

#include "shared-bindings/digitalio/DigitalInOut.h"
#include "shared-bindings/displayio/Group.h"

#include "shared-module/displayio/area.h"
#include "shared-module/displayio/display_core.h"

typedef struct {
    mp_obj_base_t base;
    displayio_display_core_t core;
    digitalio_digitalinout_obj_t busy;
    uint32_t milliseconds_per_frame;
    const uint8_t *start_sequence;
    uint32_t start_sequence_len;
    const uint8_t *stop_sequence;
    uint32_t stop_sequence_len;
    uint16_t refresh_time;
    uint16_t set_column_window_command;
    uint16_t set_row_window_command;
    uint16_t set_current_column_command;
    uint16_t set_current_row_command;
    uint16_t write_black_ram_command;
    uint16_t write_color_ram_command;
    uint8_t refresh_display_command;
    uint8_t hue;
    bool busy_state;
    bool black_bits_inverted;
    bool color_bits_inverted;
    bool refreshing;
    bool grayscale;
    display_chip_select_behavior_t chip_select;
} displayio_epaperdisplay_obj_t;

void displayio_epaperdisplay_change_refresh_mode_parameters(displayio_epaperdisplay_obj_t *self,
    mp_buffer_info_t *start_sequence, float seconds_per_frame);
void displayio_epaperdisplay_background(displayio_epaperdisplay_obj_t *self);
void release_epaperdisplay(displayio_epaperdisplay_obj_t *self);
size_t maybe_refresh_epaperdisplay(void);

void displayio_epaperdisplay_collect_ptrs(displayio_epaperdisplay_obj_t *self);

#endif // MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_EPAPERDISPLAY_H
