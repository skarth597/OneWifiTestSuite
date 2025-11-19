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

output=$(dmcli eRT getv Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.PartnerId)

json_data='{
  "PhyList": [
    {
      "Index": 0,
      "RadioList": [
        {
          "Index": 0,
          "RadioName": "wlan0",
          "InterfaceList": [
            {
              "InterfaceName": "wlan0",
              "Bridge": "brlan0",
              "vlanId": 0,
              "vapIndex": 0,
              "vapName": "mesh_sta_5g"
            }
          ]
        }
      ]
    }
  ]
}'

echo "$json_data" > /nvram/InterfaceMap.json
if echo "$output" | grep -q "RDKM"; then
	dmcli eRT setv Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.PartnerId string "sky-uk"
	dmcli eRT setv Device.DeviceInfo.X_RDKCENTRAL-COM_Syndication.RDKB_Control.ActivatePartnerId bool true
fi

sleep 2
cci &
brctl delif brlan0 eth1
udhcpc -i eth1 -x hostname:ots_ext_agent -b &

brctl delif brlan0 eth2
udhcpc -i eth2 -x hostname:ots_ext_agent -b &
