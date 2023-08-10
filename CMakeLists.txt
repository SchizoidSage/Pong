cmake_minimum_required(VERSION 3.18.4)
project(Pong VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(SDL2 2.0.16 REQUIRED)

if(NOT SDL2_FOUND)
  message (FATAL_ERROR "Cannot find SDL2")
endif()

find_package(OpenGL 1.3.4 REQUIRED)

if(NOT OPENGL_FOUND)
  message (FATAL_ERROR "Cannot find OpenGL")
endif()

find_package(GLEW 2.1.0 REQUIRED)
find_package(glm REQUIRED)

if(NOT GLEW_FOUND)
  message (FATAL_ERROR "Cannot find GLEW")
endif()

find_package(OpenAL 1.19.1 REQUIRED)

if (NOT OPENAL_FOUND)
  message (FATAL_ERROR "Cannot find OpenAL")
endif()

find_package(EnTT 3.12.0 REQUIRED)

if (NOT EnTT_FOUND)
  message (FATAL_ERROR "Cannot find EnTT")
endif()

find_package(effolkronium_random REQUIRED)

add_executable(pong "")

string(TOLOWER "${CMAKE_BUILD_TYPE}" build_type)
if (build_type STREQUAL "release")
  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(pong 
      PRIVATE
        /O2
    )
  else()
    target_compile_options(pong
      PRIVATE 
        -O2 -DNDEBUG
    )
  endif()
else()
  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(pong 
      PRIVATE
        /W4 /w44365 /external:W3 /WX
    )
  else()
    target_compile_options(pong
      PRIVATE 
        -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror
    )
  endif()
endif()

target_link_libraries(pong
  PRIVATE 
    SDL2::SDL2
    GLEW::glew
    OpenGL::GL
    openal
    alure
    EnTT::EnTT
    effolkronium_random
)

target_include_directories(pong
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_definitions(pong
  PRIVATE
    CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/share/pong
)

add_subdirectory(source)

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