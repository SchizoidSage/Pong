cmake_minimum_required(VERSION 3.18.4)
project(Pong VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(SDL2 2.0.16 REQUIRED)

if(SDL2_FOUND)
  message ("SDL2 found")
else()
  message (FATAL_ERROR "Cannot find SDL2")
endif()

find_package(OpenGL 1.3.4 REQUIRED)

if(OPENGL_FOUND)
  message ("OpenGL found")
else()
  message (FATAL_ERROR "Cannot find OpenGL")
endif()

find_package(GLEW 2.1.0 REQUIRED)

if(GLEW_FOUND)
  message ("GLEW found")
else()
  message (FATAL_ERROR "Cannot find GLEW")
endif()

find_package(OpenAL 1.19.1 REQUIRED)

if (OPENAL_FOUND)
  message ("OpenAL found")
else()
  message (FATAL_ERROR "Cannot find OpenAL")
endif()

find_package(EnTT 3.12.0 REQUIRED)

if (EnTT_FOUND)
  message ("EnTT found")
else()
  message (FATAL_ERROR "Cannot find EnTT")
endif()

find_package(effolkronium_random REQUIRED)

add_executable(pong "")

target_compile_options(pong
  PRIVATE 
    -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror
)

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

add_subdirectory(source)