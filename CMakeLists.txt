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
  LANGUAGES CXX
)

include(GNUInstallDirs)

# Set required variables

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(INSTALL_DEPS "Installs dependencies" ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(INSTALL_GAMEDIR games CACHE PATH "Installation directory for games")

set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)
set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

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
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    -DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS}
    -DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
  CMAKE_CACHE_ARGS
    -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
    -DCMAKE_MODULE_PATH:PATH=${CMAKE_MODULE_PATH}
    -DINSTALL_GAMEDIR:PATH=${INSTALL_GAMEDIR}
  BUILD_ALWAYS ON
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

if(INSTALL_DEPS)
  install(
    DIRECTORY 
      ${STAGED_INSTALL_PREFIX}/lib/
    DESTINATION
      lib
    USE_SOURCE_PERMISSIONS
  )

  install(
    DIRECTORY 
      ${STAGED_INSTALL_PREFIX}/include/
    DESTINATION
      include
    USE_SOURCE_PERMISSIONS
  )

  install(
    DIRECTORY 
      ${STAGED_INSTALL_PREFIX}/cmake/
    DESTINATION
      cmake
    USE_SOURCE_PERMISSIONS
  )
endif()

# Configure CPack

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR SchizoidSage)
set(CPACK_PACKAGE_DESCRIPTION_FILE "${PROJECT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Pong: A simple Pong implementation")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_CHECKSUM SHA256)

set(CPACK_SOURCE_GENERATOR "TGZ;TBZ2")
set(CPACK_SOURCE_IGNORE_FILES "\.git*;${PROJECT_BINARY_DIR}")

set(CPACK_GENERATOR "DEB;RPM")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER SchizoidSage)
set(CPACK_DEBIAN_PACKAGE_SECTION "games")
set(CPACK_DEBIAN_PACKAGE_DEPENDS 
  "libsdl2-2.0-0 (>=2.0.16),\
   libgl1 (>=1.3.4),\
   libglew2.1 (>=2.1.0),\
   libopenal1 (>=1.19.1),\
   libalure1 (>=1.2)"
)

set(CPACK_RPM_PACKAGE_RELEASE "1")
set(CPACK_RPM_PACKAGE_LICENSE "GPLv3+")
set(CPACK_RPM_PACKAGE_REQUIRES
  "mesa-libGL >= 21.2.6,\
   SDL2 >= 2.0.16,\
   glew >= 2.1.0,\
   openal-soft >= 1.19.1,\
   alure >= 1.2"
)

include(CPack)