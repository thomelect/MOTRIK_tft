/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Dan Halbert for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_NRF_COMMON_HAL_BLEIO_INIT_H
#define MICROPY_INCLUDED_NRF_COMMON_HAL_BLEIO_INIT_H

void bleio_background(void);
void bleio_reset(void);

typedef struct {
    ble_gap_enc_key_t own_enc;
    ble_gap_enc_key_t peer_enc;
    ble_gap_id_key_t peer_id;
} bonding_keys_t;

// We assume variable length data.
// 20 bytes max (23 - 3).
#define GATT_MAX_DATA_LENGTH (BLE_GATT_ATT_MTU_DEFAULT - 3)

// These helpers raise the appropriate exceptions if the code doesn't equal success.
void check_nrf_error(uint32_t err_code);
void check_gatt_status(uint16_t gatt_status);
void check_sec_status(uint8_t sec_status);

#endif // MICROPY_INCLUDED_NRF_COMMON_HAL_BLEIO_INIT_H
