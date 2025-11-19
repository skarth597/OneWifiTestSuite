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

#include "wlan_ext_emu.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int start()
{
    wlan_ext_emu_t *ext_emu;

    ext_emu = new wlan_ext_emu_t();
    if (ext_emu->init() == RETURN_ERR) {
        wlan_emu_print(wlan_emu_log_level_err, "%s:%d init failed\n", __func__, __LINE__);
        return RETURN_ERR;
    }

    return RETURN_OK;
}

void kill_previous_instances(const char *process_name)
{
    FILE *cmd_output;
    char buffer[128] = { 0 };
    char cmd[256] = { 0 };
    int curr_pid = getpid();

    snprintf(cmd, sizeof(cmd), "pgrep %s", process_name);

    cmd_output = popen(cmd, "r");
    if (cmd_output == NULL) {
        wlan_emu_print(wlan_emu_log_level_err, "%s:%d: Error running pgrep cmd : %s\n", __func__,
            __LINE__, cmd);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), cmd_output) != NULL) {
        pid_t pid = atoi(buffer);

        if ((pid > 0) && (pid != curr_pid)) {
            if (kill(pid, SIGTERM) == 0) {
                wlan_emu_print(wlan_emu_log_level_dbg,
                    "%s:%d: Previous instance with PID %d killed.\n", __func__, __LINE__, pid);
            } else {
                wlan_emu_print(wlan_emu_log_level_err, "%s:%d: Error killing process PID : %d\n",
                    __func__, __LINE__, pid);
            }
        }
    }

    pclose(cmd_output);
}

int main(int argc, const char *argv[])
{
    wlan_emu_print(wlan_emu_log_level_err, "%s:%d cci process started\n", __func__, __LINE__);
    // wifi_platform_type_t type;
    kill_previous_instances(argv[0]);
    if (start() == RETURN_ERR) {
        wlan_emu_print(wlan_emu_log_level_err, "%s:%d cci start failed\n", __func__, __LINE__);
        return RETURN_ERR;
    }

    wlan_emu_print(wlan_emu_log_level_err, "%s:%d cci process stopped\n", __func__, __LINE__);

    return RETURN_OK;
}
