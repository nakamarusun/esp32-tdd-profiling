# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(NRF_BUILD)
add_subdirectory(../main/Sorting-Algorithms)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

target_link_libraries(${PROJECT_NAME} Sorting-Algorithms)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})