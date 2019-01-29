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

#pragma once

#include <cstddef>
#include <cstdint>

typedef enum {
    HAL_NFC_TAG_TYPE_NONE,
    HAL_NFC_TAG_TYPE_2,
    HAL_NFC_TAG_TYPE_NOT_SURPPORTED
} hal_nfc_tag_type_t;

typedef enum {
    HAL_NFC_EVENT_FIELD_ON,             // NFC tag has detected external NFC field and was selected by an NFC polling device.
    HAL_NFC_EVENT_FIELD_OFF,            // External NFC field has been removed.
    HAL_NFC_EVENT_READ                  // NFC polling device has read all tag data.
} hal_nfc_event_type_t;

typedef struct {
    uint32_t reserved;
} hal_nfc_event_t;

typedef void (*hal_nfc_event_callback_t)(hal_nfc_event_type_t type, hal_nfc_event_t* event, void* ctx);

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int hal_nfc_type2_init(void* reserved);
int hal_nfc_type2_set_payload(const void* msg_buf, size_t msg_len, void* reserved);
int hal_nfc_type2_start_emulation(void* reserved);
int hal_nfc_type2_stop_emulation(void* reserved);
int hal_nfc_type2_set_callback(hal_nfc_event_callback_t callback, void* ctx);

#ifdef __cplusplus
}
#endif // __cplusplus
