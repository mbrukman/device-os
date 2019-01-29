/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "nfc_hal.h"
#include "nfc_t2t_lib.h"
#include "check_nrf.h"

static hal_nfc_event_callback_t s_nfc_event_user_callback = nullptr;
static void* s_nfc_event_user_ctx = nullptr;

static void nfc_type_2_callback(void * p_context, nfc_t2t_event_t event, const uint8_t * p_data, size_t data_length) {
    (void)p_context;
    switch (event) {
        case NFC_T2T_EVENT_FIELD_ON: {
            if (s_nfc_event_user_callback) {
                s_nfc_event_user_callback(HAL_NFC_EVENT_FIELD_ON, nullptr, s_nfc_event_user_ctx);
            }
            break;
        }
        case NFC_T2T_EVENT_FIELD_OFF: {
            if (s_nfc_event_user_callback) {
                s_nfc_event_user_callback(HAL_NFC_EVENT_FIELD_OFF, nullptr, s_nfc_event_user_ctx);
            }
            break;
        }
        case NFC_T2T_EVENT_DATA_READ: {
            if (s_nfc_event_user_callback) {
                s_nfc_event_user_callback(HAL_NFC_EVENT_READ, nullptr, s_nfc_event_user_ctx);
            }
            break;
        }
        default:
            break;
    }
}

int hal_nfc_type2_init(void* reserved) {
    CHECK_NRF(nfc_t2t_setup(nfc_type_2_callback, NULL));

    return 0;
}

int hal_nfc_type2_set_payload(const void* msg_buf, size_t msg_len, void* reserved) {
    CHECK_NRF(nfc_t2t_payload_set((uint8_t*)msg_buf, msg_len));

    return 0;
}

int hal_nfc_type2_start_emulation(void* reserved) {
    CHECK_NRF(nfc_t2t_emulation_start());

    return 0;
}

int hal_nfc_type2_stop_emulation(void* reserved) {
    CHECK_NRF(nfc_t2t_emulation_stop());

    return 0;
}

int hal_nfc_type2_set_callback(hal_nfc_event_callback_t callback, void* ctx) {
    s_nfc_event_user_callback = callback;
    s_nfc_event_user_ctx = ctx;
    return 0;
}
