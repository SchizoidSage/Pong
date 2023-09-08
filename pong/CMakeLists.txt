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
project(Pong_core LANGUAGES C CXX)

cmake_policy(SET CMP0005 NEW)

include(FetchContent)

find_package(OpenGL 1.3.4 REQUIRED)
find_package(OpenAL 1.19.1 REQUIRED)
find_package(SDL2 2.0.16 REQUIRED)
find_package(GLEW 2.1.0 REQUIRED)
find_package(glm REQUIRED)
find_package(Alure 1.2 REQUIRED)
find_package(EnTT 3.12.0 REQUIRED)
FetchContent_Declare(effolkronium_random
  GIT_REPOSITORY  https://github.com/effolkronium/random.git
  GIT_TAG         v1.5.0
)
set(FETCHCONTENT_PACKAGES effolkronium_random)

if(PERFORM_TESTS)
  FetchContent_Declare(googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         release-1.10.0
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  list(APPEND FETCHCONTENT_PACKAGES googletest)
endif()

FetchContent_MakeAvailable(${FETCHCONTENT_PACKAGES})

add_executable(pong "")
add_library(pong_lib STATIC "")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  target_compile_options(pong_lib
    PUBLIC 
      -O2 -DNDEBUG
  )
else()
  target_compile_options(pong_lib
    PUBLIC 
      -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror
  )
endif()

target_link_libraries(pong_lib
  PUBLIC 
    SDL2::SDL2
    GLEW::glew
    OpenGL::GL
    openal
    Alure::Alure
    EnTT::EnTT
    effolkronium_random
)

include(GNUInstallDirs)

target_include_directories(pong_lib
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(src)

target_link_libraries(pong
  PRIVATE
    pong_lib
)

# Add testing target

if(PERFORM_TESTS)
  enable_testing()

  add_executable(pong_test "")
  target_link_libraries(pong_test
    PRIVATE
      pong_lib
      gtest_main
  )

  add_subdirectory(tests)

  include(GoogleTest)
  gtest_discover_tests(pong_test)
endif()

# Add documentation target

if(GENERATE_DOCS)
  find_package(Doxygen 1.9.1 QUIET
    OPTIONAL_COMPONENTS dot mscgen dia
  )

  if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX})
    set(DOXYGEN_PROJECT_NAME Pong)
    set(DOXYGEN_EXCLUDE_PATTERNS whereami.h)
    doxygen_add_docs(Pong_docs
      include 
      docs
      ALL
    )
  else()
    message(STATUS "Could not find Doxygen; not generating documentation target.")
  endif()
endif()

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