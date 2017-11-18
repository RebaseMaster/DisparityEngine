# Copyright (C) 2017-2018 DISPARITY Engine, Windfall Studio

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# he Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

# Path
SET(DISPARITY_ROOT_DIR        ${CMAKE_SOURCE_DIR})
SET(DISPARITY_BIN_DIR         ${DISPARITY_ROOT_DIR}/Bin)
SET(DISPARITY_BIN_DIR_DBG     ${DISPARITY_BIN_DIR}/Debug)
SET(DISPARITY_BIN_DIR_REL     ${DISPARITY_BIN_DIR}/Release)
SET(DISPARITY_LIB_DIR         ${DISPARITY_ROOT_DIR}/Lib)
SET(DISPARITY_LIB_DIR_DBG     ${DISPARITY_LIB_DIR}/Debug)
SET(DISPARITY_LIB_DIR_REL     ${DISPARITY_LIB_DIR}/Release)
SET(DISPARITY_ENGINE_DIR      ${DISPARITY_ROOT_DIR}/Engine)
SET(DISPARITY_THIRD_PARTY_DIR ${DISPARITY_ENGINE_DIR}/ThirdParty)
SET(DISPARITY_UNIT_TEST_DIR   ${DISPARITY_THIRD_PARTY_DIR}/UnitTest)
SET(DISPARITY_SDL_DIR         ${DISPARITY_THIRD_PARTY_DIR}/SDL2)

# Include
SET(DISPARITY_GTEST_INC_DIR   ${DISPARITY_UNIT_TEST_DIR}/GoogleTest/include)
SET(DISPARITY_GMOCK_INC_DIR   ${DISPARITY_UNIT_TEST_DIR}/GoogleMock/include)

# Name
SET(DISPARITY_RUNTIME DISPARITYRuntime)
SET(DISPARITY_EDITOR  DISPARITYEditor)