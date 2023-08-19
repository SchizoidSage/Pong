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

#[=======================================================================[.rst:
FindAlure
-------

Finds the Alure library.

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``Alure::Alure``
  The Alure library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``Alure_FOUND``
  True if the system has the Alure library.
``Alure_VERSION``
  The version of the Alure library which was found.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``Alure_INCLUDE_DIR``
  The directory containing ``alure.h``.
``Alure_LIBRARY``
  The path to the Alure library.

#]=======================================================================]

find_package(PkgConfig QUIET)
pkg_check_modules(PC_Alure QUIET ALURE)

find_path(Alure_INCLUDE_DIR
  NAMES 
    "AL/alure.h"
  PATH_SUFFIXES 
    include
  PATHS 
    /usr
    /usr/local
)

find_library(Alure_LIBRARY
  NAMES
    alure
  PATH_SUFFIXES
    lib
  PATHS
    /usr
    /usr/local
)

set(Alure_VERSION ${PC_Alure_VERSION})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Alure
  FOUND_VAR Alure_FOUND
  REQUIRED_VARS
    Alure_LIBRARY
    Alure_INCLUDE_DIR
  VERSION_VAR Alure_VERSION
)

if (Alure_FOUND AND NOT TARGET Alure::Alure)
  add_library(Alure::Alure SHARED IMPORTED)
  set_target_properties(Alure::Alure PROPERTIES
    IMPORTED_LOCATION "${Alure_LIBRARY}"
    INTERFACE_COMPILE_OPTIONS "${PC_Alure_CFLAGS_OTHER}"
    INTERFACE_INCLUDE_DIRECTORIES "${Alure_INCLUDE_DIR}"
  )
endif()