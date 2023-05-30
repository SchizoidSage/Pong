#include "rendering/Shader.h"
#include <GL/glew.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>
#include <string>
#include <memory>
#include <fstream>
#include <cstdlib>

Shader::Shader(const char* vertex_shader, const char* fragment_shader)
{
  auto vertex_shader_source{ read_shader_source(vertex_shader) };
  auto fragment_shader_source{ read_shader_source(fragment_shader) };

	auto vertex_shader_source_str{ vertex_shader_source.c_str() };
	auto fragment_shader_source_str{ fragment_shader_source.c_str() };

  m_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  m_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(m_vertex_shader, 1, &vertex_shader_source_str, NULL);
  glShaderSource(m_fragment_shader, 1, &fragment_shader_source_str, NULL);

  if (!compile_shader(m_vertex_shader)) {
    throw std::runtime_error{ "Vertex shader compilation failed!\n" };
  }
  if (!compile_shader(m_fragment_shader)) {
    throw std::runtime_error{ "Fragment shader compilation failed!\n" };
  }

  m_shader_program = glCreateProgram();
  glAttachShader(m_shader_program, m_vertex_shader);
  glAttachShader(m_shader_program, m_fragment_shader);

  if (!link_program(m_shader_program)) {
    throw std::runtime_error{ "Shader program linking failed!\n" };
  }
}

Shader::~Shader()
{
  glDeleteProgram(m_shader_program);
  glDeleteShader(m_vertex_shader);
  glDeleteShader(m_fragment_shader);
}

void Shader::set_active()
{
  glUseProgram(m_shader_program);
}

void Shader::set_uniform(const char* uniform_name, const glm::mat4& matrix)
{
  glUniformMatrix4fv(glGetUniformLocation(m_shader_program, uniform_name), 1, GL_FALSE, glm::value_ptr(matrix));
}

std::string Shader::read_shader_source(const char* file_path)
{
  std::string content{ };
	auto file_stream{ std::make_unique<std::ifstream>(file_path, std::ios::in) };
	std::string line{ };

	while (!file_stream->eof()) {
		std::getline(*file_stream, line);
		content.append(line + '\n');
	}

	return content;
}

bool Shader::compile_shader(GLuint shader)
{
	glCompileShader(shader);
	check_openGL_error();
  GLint is_compiled{ };
	glGetShaderiv(shader, GL_COMPILE_STATUS, &is_compiled);
	if (is_compiled != 1) {
		print_shader_log(shader);
		return false;
	}
  return true;
}

bool Shader::link_program(GLuint program)
{
	glLinkProgram(program);
	check_openGL_error();
  GLint is_linked{ };
	glGetProgramiv(program, GL_LINK_STATUS, &is_linked);
	if (is_linked != 1) {
		print_program_log(program);
		return false;
	}
  return true;
}

void Shader::check_openGL_error()
{
	GLuint error{ glGetError() };
	while (error != GL_NO_ERROR) {
		std::cout << "OpenGL Error: " << error << '\n';
		error = glGetError();
	}
}

void Shader::print_shader_log(GLuint shader)
{
	int len{ 0 };
	int char_written{ 0 };
	char* log{ };
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)std::malloc(static_cast<size_t>(len));
		glGetShaderInfoLog(shader, len, &char_written, &log);
		std::cout << "Shader info log: " << log << '\n';
		std::free(log);
	}
}

void Shader::print_program_log(GLuint program)
{
	int len{ 0 };
	int char_written{ 0 };
	char* log{ };
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)std::malloc(static_cast<size_t>(len));
		glGetProgramInfoLog(program, len, &char_written, log);
		std::cout << "Program info log: " << log << '\n';
		std::free(log);
	}
}