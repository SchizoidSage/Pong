# Pong: A Pong Game with OpenGL, SDL2 and EnTT 
# Copyright (C) 2023  SchizoidSage
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.18.4)
project(Pong VERSION 1.0 LANGUAGES CXX)

cmake_policy(SET CMP0005 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 2.0.16 REQUIRED)
find_package(OpenGL 1.3.4 REQUIRED)
find_package(GLEW 2.1.0 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenAL 1.19.1 REQUIRED)
find_package(Alure 1.2 REQUIRED)
find_package(EnTT 3.12.0 REQUIRED)
find_package(effolkronium_random REQUIRED)
find_package(GTest 1.10.0 REQUIRED)

add_executable(pong "")

string(TOLOWER "${CMAKE_BUILD_TYPE}" build_type)
if (build_type STREQUAL "release")
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
)

target_include_directories(pong
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(source)

target_compile_definitions(pong
  PRIVATE
    CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/share/pong
)

install(TARGETS pong RUNTIME DESTINATION games
        PERMISSIONS
          OWNER_READ OWNER_EXECUTE
          GROUP_READ GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE
)

install(DIRECTORY audio glsl DESTINATION share/pong
        FILE_PERMISSIONS
          OWNER_READ
          GROUP_READ
          WORLD_READ
        DIRECTORY_PERMISSIONS
          OWNER_READ OWNER_WRITE OWNER_EXECUTE
          GROUP_READ GROUP_WRITE GROUP_EXECUTE
          WORLD_READ WORLD_EXECUTE
)