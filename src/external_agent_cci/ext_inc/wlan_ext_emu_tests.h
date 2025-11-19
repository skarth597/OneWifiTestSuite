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

#ifndef WLAN_EXT_EMU_TESTS_H
#define WLAN_EXT_EMU_TESTS_H
#include "collection.h"
#include "wlan_emu_log.h"
#include <pthread.h>

class wlan_ext_emu_msg_mgr_t;
class wlan_ext_emu_t;
class wlan_emu_msg_t;
class wlan_ext_test_step_params_t;
class wlan_ext_emu_sta_mgr_t;

class wlan_ext_emu_tests_t {
private:
    pthread_cond_t m_cond;
    pthread_mutex_t m_lock;
    pthread_t m_tid;
    wlan_ext_emu_msg_mgr_t *m_msg_mgr;
    wlan_ext_emu_sta_mgr_t *m_agent_sta_mgr; // TBD
    wlan_ext_emu_t *m_ext_emu;
    bool m_exit;
    queue_t *m_test_msg_q;
    static void *test_function(void *arg);
    bool agent_test_initialized;
    unsigned int current_step_index;

public:
    wlan_emu_msg_t *pop_msg();
    void process_msg(wlan_emu_msg_t *msg);
    void wlan_emu_handle_agent_msg(wlan_emu_msg_t *msg);

    inline void add_msg_mgr(wlan_ext_emu_msg_mgr_t *mgr)
    {
        m_msg_mgr = mgr;
    }

    inline void add_ext_emu(wlan_ext_emu_t *mgr)
    {
        m_ext_emu = mgr;
    }

    inline void add_agent_sta_mgr(wlan_ext_emu_sta_mgr_t *sta_mgr)
    {
        m_agent_sta_mgr = sta_mgr;
    }

    inline int ext_test_wait(struct timespec *time_to_wait)
    {
        return pthread_cond_timedwait(&m_cond, &m_lock, time_to_wait);
    }

    inline int get_agent_test_initialized()
    {
        return agent_test_initialized;
    }

    void test_stop();
    wlan_ext_test_step_params_t *get_ext_step_from_index(int index);

    void push_msg(wlan_emu_msg_t *msg);
    wlan_ext_emu_tests_t(wlan_ext_emu_msg_mgr_t *msg_mgr, wlan_ext_emu_t *ext_emu,
        wlan_ext_emu_sta_mgr_t *agent_sta_mgr);
    ~wlan_ext_emu_tests_t();
};
#endif
