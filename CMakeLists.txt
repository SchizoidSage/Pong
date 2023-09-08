#[[
  Pong: A Pong Game with OpenGL, SDL2 and EnTT 
  Copyright (C) 2023  SchizoidSage

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
]]

cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)
project(Pong 
  VERSION 1.0 
  DESCRIPTION "A simple Pong implementation."
  HOMEPAGE_URL "https://github.com/SchizoidSage/Pong"
  LANGUAGES C CXX
)

include(GNUInstallDirs)

# Set required variables

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(INSTALL_GAMEDIR games CACHE PATH "Installation directory for games")

set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)
set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Add optional variables

option(GENERATE_DOCS "Determines whether Doxygen documentation should be generated.")
option(PERFORM_TESTS "Determines whether Pong tests should be run.")

# Add dependencies

add_subdirectory(external/upstream)

# Create Pong executable

include(ExternalProject)
ExternalProject_Add(${PROJECT_NAME}_core
  DEPENDS
    EnTT_external
  SOURCE_DIR
    ${CMAKE_CURRENT_LIST_DIR}/pong
  CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    -DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS}
    -DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
    -DCMAKE_C_STANDARD=${CMAKE_C_STANDARD}
    -DCMAKE_C_EXTENSIONS=${CMAKE_C_EXTENSIONS}
    -DCMAKE_C_STANDARD_REQUIRED=${CMAKE_C_STANDARD_REQUIRED}
    -DGENERATE_DOCS=${GENERATE_DOCS}
    -DPERFORM_TESTS=${PERFORM_TESTS}
  CMAKE_CACHE_ARGS
    -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
    -DCMAKE_MODULE_PATH:PATH=${CMAKE_MODULE_PATH}
    -DINSTALL_GAMEDIR:PATH=${INSTALL_GAMEDIR}
    -DINSTALL_SHAREDIR:PATH=${CMAKE_INSTALL_FULL_DATADIR}
  BUILD_ALWAYS        ON
  TEST_AFTER_INSTALL  ${PERFORM_TESTS}
)

# Create installation targets

install(
  DIRECTORY 
    ${STAGED_INSTALL_PREFIX}/games/
  DESTINATION
    games
  USE_SOURCE_PERMISSIONS
)

install(
  DIRECTORY 
    ${STAGED_INSTALL_PREFIX}/share/
  DESTINATION
    share
  USE_SOURCE_PERMISSIONS
)

if(GENERATE_DOCS)
  install(
    DIRECTORY
      ${STAGED_INSTALL_PREFIX}/html/
    DESTINATION
      share/doc/pong-doc/html
    USE_SOURCE_PERMISSIONS
  )
endif()

# Configure CPack

include(cmake/CMakeCPack.cmake)
