#ifndef SHADER_202303171912_H
#define SHADER_202303171912_H

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

class Shader final
{
public:
  Shader(const char* vertex_shader, const char* fragment_shader);
  ~Shader();
  void set_active();
  void set_uniform(const char* uniform_name, glm::mat4 matrix);
private:
  std::string read_shader_source(const char* file_path);
  bool compile_shader(GLuint shader);
  bool link_program(GLuint program);
  void check_openGL_error();
  void print_shader_log(GLuint shader);
  void print_program_log(GLuint program);
  
  GLuint m_vertex_shader{ };
  GLuint m_fragment_shader{ };
  GLuint m_shader_program{ };
};

#endif