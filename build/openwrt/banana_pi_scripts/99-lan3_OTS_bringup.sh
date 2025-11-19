#!/bin/sh
#
# Copyright 2025 Comcast Cable Communications Management, LLC

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0
#
#

logger -t hotplug-test "Hotplug triggered for INTERFACE=$INTERFACE ACTION=$ACTION DEVICE=$DEVICE"


[ "$INTERFACE" = "lan3" ] || exit 0

if [ "$ACTION" = "ifup" ]; then
    logger -t lan3-monitor "Device connected to lan3, starting namespace"
    ip netns add ots
    ip link set lan3 netns ots
    ip netns exec ots ip link set lo up
    ip netns exec ots ip link set lan3 up
    mac=$(ip netns exec ots ip link show lan3 | awk '/link\/ether/ {gsub(":", "", $2); print $2}')
    hostname="ots_ext_agent-${mac}"
    ip netns exec ots udhcpc -i lan3 -x hostname:${hostname}
    ip netns exec ots ip addr show lan3
    ip netns exec ots pkill udhcpc

elif [ "$ACTION" = "ifdown" ]; then
    logger -t lan3-monitor "Device disconnected from lan3"
fi

exit
