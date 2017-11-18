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

# CMake project settings
PROJECT(DisparityEngine)
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

# Checking project structure
INCLUDE(CMake/CMakeConfigDirectory.cmake)

# Defines the game engine version and name
SET (CMAKE_ENGINE_VERSION_MAJOR 0)
SET (CMAKE_ENGINE_VERSION_MINOR 1)
SET (CMAKE_ENGINE_VERSION_PATCH 0)

# Displays engine version
MESSAGE(STATUS "Engine : ${ENGINE_NAME} "
         "${CMAKE_ENGINE_VERSION_MAJOR}."
         "${CMAKE_ENGINE_VERSION_MINOR}."
         "${CMAKE_ENGINE_VERSION_PATCH} ")

# Compiler detection
IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    # Using GNU GCC
    SET(DISPARITY_USE_GCC 1)
    ADD_DEFINITIONS(-D DISPARITY_USE_GCC)
    MESSAGE(STATUS "Detected Compiler : GCC")

    # For GCC, setting flags
    SET(CXX_RELEASE_FLAGS "-Wall -O3")
    SET(CXX_DEBUG_FLAGS   "-Wall -Wextra -g -Wdouble-promotion -Wno-attributes")

ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    # Using Visual Studio C++
    SET(DISPARITY_USE_MSVC 1)
    ADD_DEFINITIONS(-D DISPARITY_USE_MSVC)
    MESSAGE(STATUS "Detected Compiler : MSVC")

    # No flags for MVSC
    # For GCC, setting flags
    # SET(CXX_RELEASE_FLAGS "")
    # SET(CXX_DEBUG_FLAGS   "")

ELSE()

    # TODO
    MESSAGE(FATAL_ERROR "Detected Compiler : Unknown, please use GCC or MSVC.")

ENDIF()

SET(CMAKE_CXX_STANDARD 11)
MESSAGE(STATUS "Compilation debug   flags : " ${CXX_DEBUG_FLAGS})
MESSAGE(STATUS "Compilation release flags : " ${CXX_RELEASE_FLAGS})

SET(WIN32_DEPENDENCIES "opengl32")
SET(APPLE_DEPENDENCIES "")
SET(UNIX_DEPENDENCIES  "GL")

# Platform detection and settings
IF(WIN32)

    # Windows operating system
    SET(DISPARITY_WINDOWS 1)
    SET(PLATFORM_DEPENDENCIES ${WIN32_DEPENDENCIES})
    ADD_DEFINITIONS(-D DISPARITY_WINDOWS)
    MESSAGE(STATUS "Detected platform : Windows")

ELSEIF(UNIX)

    # Unix operating system
    SET(DISPARITY_UNIX 1)
    SET(PLATFORM_DEPENDENCIES ${UNIX_DEPENDENCIES})
    ADD_DEFINITIONS(-D DISPARITY_UNIX)
    MESSAGE(STATUS "Detected platform : Unix")

ELSEIF(APPLE)

    # Mac os operating system
    SET(DISPARITY_APPLE 1)
    SET(PLATFORM_DEPENDENCIES ${APPLE_DEPENDENCIES})
    ADD_DEFINITIONS(-D DISPARITY_APPLE)
    MESSAGE(STATUS "Detected platform : Apple")

ELSE()

    # Not supported
    SET(PLATFORM_NOT_SUPORTED 0)
    SET(PLATFORM_DEPENDENCIES)
    ADD_DEFINITIONS(-D PLATFORM_NOT_SUPORTED)
    MESSAGE(FATAL_ERROR "This plateform is currently not supported")

ENDIF()

# Compilation mode
IF(${CMAKE_BUILD_TYPE} MATCHES Debug)

    # Debug mode
    ADD_DEFINITIONS(-D DISPARITY_DEBUG)
    SET(DISPARITY_BIN_OUTPUT ${DISPARITY_BIN_DIR_DBG})
    SET(DISPARITY_LIB_OUTPUT ${DISPARITY_LIB_DIR_DBG})

    MESSAGE(STATUS "Compilation mode  : Debug")
    MESSAGE(STATUS "Project binary  output : ${DISPARITY_BIN_OUTPUT}")
    MESSAGE(STATUS "Project library output : ${DISPARITY_LIB_OUTPUT}")

    # Setting flags
    IF(COMPILER_GCC)
        # Only for GCC
        set(CMAKE_CXX_FLAGS_DEBUG ${CXX_DEBUG_FLAGS} CACHE STRING "DBG" FORCE)
    ENDIF()

ELSEIF(${CMAKE_BUILD_TYPE} MATCHES Release)

    # Release mode
    ADD_DEFINITIONS(-D DISPARITY_RELEASE)
    SET(DISPARITY_BIN_OUTPUT ${DISPARITY_BIN_DIR_REL})
    SET(DISPARITY_LIB_OUTPUT ${DISPARITY_LIB_DIR_REL})

    MESSAGE(STATUS "Compilation mode  : Release")
    MESSAGE(STATUS "Project binary  output : ${DISPARITY_BIN_OUTPUT}")
    MESSAGE(STATUS "Project library output : ${DISPARITY_LIB_OUTPUT}")

    # Setting flags
    IF(COMPILER_GCC)
        # Only for GCC
        set(CMAKE_CXX_FLAGS_DEBUG ${CXX_RELEASE_FLAGS} CACHE STRING "REL" FORCE)
    ENDIF()

ELSE()

    # No mode
    MESSAGE(FATAL_ERROR "No build type, please configure it")

ENDIF()

# Avoiding the Release/Debug subdirectories
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${DISPARITY_BIN_OUTPUT})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${DISPARITY_BIN_OUTPUT})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${DISPARITY_LIB_OUTPUT})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${DISPARITY_LIB_OUTPUT})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${DISPARITY_LIB_OUTPUT})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${DISPARITY_LIB_OUTPUT})

# Obsolete, configured in CMakeSettings.json
# SET(gtest_force_shared_crt ON CACHE BOOL FORCE "Always use msvcrt.dll" )

# Include directories
INCLUDE_DIRECTORIES(
        ${DISPARITY_ENGINE_DIR}
        ${DISPARITY_THIRD_PARTY_DIR})

ADD_SUBDIRECTORY(Engine)