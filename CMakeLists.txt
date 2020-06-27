# Copyright (c) 2020 Abhijit Bose <https://boseji.com>
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
# Re-direct the directory where the 'boards' directory is found from
# $ZEPHYR_BASE to this directory.
set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR})

# This sample is only compatible with stm32f3_disco because it has
# re-directed the 'boards' directory to a directory that only contains
# this board.
set(BOARD stm32f3_disco)

# Get Zephyr using the configured environment variable
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# The Project Name
project(fancier_blinky_stm32f3_disco)

# Collect all the files in the Source Directory for build target
FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})

# Older Method of Grouping
#target_sources(app PRIVATE src/main.c)

