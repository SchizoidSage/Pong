/*
* Pong: A Pong Game with OpenGL, SDL2 and EnTT 
* Copyright (C) 2023  SchizoidSage
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SHADER_202303171912_HPP
#define SHADER_202303171912_HPP

#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <string>

class Shader final
{
public:
  Shader(const char* vertex_shader, const char* fragment_shader);
  ~Shader();
  void set_active() const;
  void set_uniform(const char* uniform_name, const glm::mat4& matrix) const;
private:
  std::string read_shader_source(const char* file_path) const;
  bool compile_shader(GLuint shader) const;
  bool link_program(GLuint program) const;
  void check_openGL_error() const;
  void print_shader_log(GLuint shader) const;
  void print_program_log(GLuint program) const;
  
  GLuint m_vertex_shader{ };
  GLuint m_fragment_shader{ };
  GLuint m_shader_program{ };
};

#endif