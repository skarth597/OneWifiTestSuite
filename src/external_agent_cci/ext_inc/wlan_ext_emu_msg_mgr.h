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

#ifndef WLAN_EXT_EMU_MSG_MGR_H
#define WLAN_EXT_EMU_MSG_MGR_H

#include "collection.h"
#include "wlan_emu_msg.h"
#include "wlan_emu_msg_hdlr.h"
// #include "wlan_ext_emu_tests.h"
#include <stdbool.h>

class wlan_ext_emu_tests_t;

class wlan_ext_emu_msg_mgr_t : public wlan_emu_msg_hdlr_t {

private:
    queue_t *m_tests;

public:
    int start();
    void stop();

    void subscribe(wlan_ext_emu_tests_t *test);
    void unsubscribe(wlan_ext_emu_tests_t *test);
    void queue_msg(wlan_emu_msg_t *msg);

    wlan_ext_emu_msg_mgr_t *clone();

    wlan_ext_emu_msg_mgr_t();
    ~wlan_ext_emu_msg_mgr_t();
};

#endif // WLAN_EXT_EMU_MSG_MGR_H
