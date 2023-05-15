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

add_executable(pong 
  Main.cpp 
  Game.cpp
)

target_compile_options(paddleball
  PRIVATE 
    -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror
)

target_include_directories(paddleball
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(paddleball
  PRIVATE 
    SDL2::SDL2
    GLEW::glew
    OpenGL::GL
)