# Copyright (C) 2017-2018 Disparity Engine

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

# Adds all runtime header
INCLUDE_DIRECTORIES(${DISPARITY_ENGINE_DIR}/Runtime/Header)

# Disables anoying attributes warning
ADD_DEFINITIONS(-Wno-attributes)

# Compile all tests
ADD_EXECUTABLE(DISPARITY_SDL_UNIT_TEST
        UnitTestSDL.cpp)

# But tests depends on GTEST and GMOCK
ADD_DEPENDENCIES(DISPARITY_SDL_UNIT_TEST gtest SDL2 glew)

# Linking ...
TARGET_LINK_LIBRARIES(DISPARITY_SDL_UNIT_TEST gtest gtest_main glew SDL2 ${PLATFORM_DEPENDENCIES})