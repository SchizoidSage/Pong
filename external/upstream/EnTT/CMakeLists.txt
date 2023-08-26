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

find_package(EnTT 3.12.0 CONFIG QUIET)

if(EnTT_FOUND)
  add_library(EnTT_external INTERFACE)
else()
  include(ExternalProject)
  ExternalProject_Add(EnTT_external
    GIT_REPOSITORY  https://github.com/skypjack/entt.git
    GIT_TAG         v3.12.0
    UPDATE_COMMAND  ""
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
      -DENTT_BUILD_TESTING=OFF
  )

  include(GNUInstallDirs)
  
  set(
    ENTT_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/EnTT/cmake
    CACHE PATH "Path to internally built EnTTConfig.cmake"
    FORCE
  )
endif()