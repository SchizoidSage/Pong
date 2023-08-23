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

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)
project(Pong_core LANGUAGES CXX)

include(FetchContent)
include(GNUInstallDirs)

cmake_policy(SET CMP0005 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL 1.3.4 REQUIRED)

FetchContent_Declare(SDL2
  GIT_REPOSITORY    https://github.com/libsdl-org/SDL.git
  GIT_TAG           release-2.0.16
  SYSTEM
  FIND_PACKAGE_ARGS 2.0.16
)
FetchContent_Declare(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           release-1.10.0
  SYSTEM
  FIND_PACKAGE_ARGS 1.10.0 NAMES GTest
)
FetchContent_Declare(GLEW
  GIT_REPOSITORY    https://github.com/nigels-com/glew.git
  GIT_TAG           glew-2.1.0
  SYSTEM
  FIND_PACKAGE_ARGS 2.1.0
)
FetchContent_Declare(glm
  GIT_REPOSITORY    https://github.com/g-truc/glm.git
  GIT_TAG           0.9.9.8
  SYSTEM
  FIND_PACKAGE_ARGS 
)
FetchContent_Declare(OpenAL
  GIT_REPOSITORY    https://github.com/kcat/openal-soft.git
  GIT_TAG           openal-soft-1.19.1
  SYSTEM
  FIND_PACKAGE_ARGS 1.19.1
)
FetchContent_Declare(Alure
  GIT_REPOSITORY    https://repo.or.cz/alure.git
  GIT_TAG           alure-1.2
  SYSTEM
  FIND_PACKAGE_ARGS 1.2
)
FetchContent_Declare(EnTT
  GIT_REPOSITORY     https://github.com/skypjack/entt.git
  GIT_TAG            v3.12.0
  SYSTEM
  FIND_PACKAGE_ARGS  3.12.0
)
FetchContent_Declare(effolkronium_random
  GIT_REPOSITORY     https://github.com/effolkronium/random.git
  GIT_TAG            v1.5.0
  SYSTEM
  FIND_PACKAGE_ARGS  1.5.0
)

FetchContent_MakeAvailable(
  SDL2
  googletest
  GLEW
  glm
  OpenAL
  Alure
  EnTT 
  effolkronium_random
)

add_executable(pong "")

message(STATUS "CMAKE_BUILD_TYPE " "${CMAKE_BUILD_TYPE}")
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  target_compile_options(pong
    PRIVATE 
      -O2 -DNDEBUG
  )
else()
  target_compile_options(pong
    PRIVATE 
      -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror
  )
endif()

target_link_libraries(pong
  PRIVATE 
    SDL2::SDL2
    GLEW::glew
    OpenGL::GL
    openal
    Alure::Alure
    EnTT::EnTT
    effolkronium_random
)

target_include_directories(pong
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_definitions(pong
  PRIVATE
    CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_DATADIR}/pong
)

add_subdirectory(src)

# Add install targets for program and resource files

install(TARGETS pong RUNTIME DESTINATION ${INSTALL_GAMEDIR}
        PERMISSIONS
          OWNER_READ OWNER_EXECUTE
          GROUP_READ GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE
)

install(DIRECTORY resources/ DESTINATION ${CMAKE_INSTALL_DATADIR}/pong
        FILE_PERMISSIONS
          OWNER_READ
          GROUP_READ
          WORLD_READ
        DIRECTORY_PERMISSIONS
          OWNER_READ OWNER_WRITE OWNER_EXECUTE
          GROUP_READ GROUP_WRITE GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE
)