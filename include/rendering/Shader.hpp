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