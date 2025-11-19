/**
 * Copyright 2025 Comcast Cable Communications Management, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef WLAN_BUS_H
#define WLAN_BUS_H

#include "wlan_emu_bus_common.h"
#include "wlan_emu_ui_mgr.h"
#include <rbus.h>

class wlan_emu_bus_t {

public:
    wifi_emu_bus_desc_t desc;
    bus_cb_multiplexing_t bus_cb_mux;
    bus_error_t bus_init();
    wlan_emu_bus_t();
    ~wlan_emu_bus_t();
};

wlan_emu_bus_t *get_emu_bus_obj(void);
wifi_emu_bus_desc_t *get_emu_bus_descriptor(void);
#endif // WLAN_BUS_H
