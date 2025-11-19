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

project(wifi_emu)

set(EXECUTABLE_NAME cci)

file(GLOB_RECURSE MAIN_SRC  "src/utils/*.c"
    "src/tests/*.cpp"
    "src/ui/*.cpp"
    "src/messages/*.cpp"
    "src/utils/*.cpp"
    "src/utils/*.hpp"
    "src/sta/*.cpp"
    "src/bus/common/*.cpp"
    "src/bus/rdkb/*.cpp"
    "src/common/*.cpp")

if (CONFIG_EXT_AGENT_CCI)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/external_agent_cci")
        message(FATAL_ERROR "Critical error! Stopping CMake.")
    endif()
    # Add subdirectory external_agent
    add_subdirectory(src/external_agent_cci)
else()
    # Add subdirectory for gateway
    add_subdirectory(src/gateway_cci)
endif()

# Set include directories for the subproject
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc  ${CMAKE_SOURCE_DIR}/src/utils ${CMAKE_SOURCE_DIR}/src/bus/rdkb)

install(TARGETS cci DESTINATION bin)

set(SOURCES_BINARY2
    src/cci_cli/cci_cli.c
    )

add_executable(cci_cli ${SOURCES_BINARY2})
install(TARGETS cci_cli DESTINATION bin)
