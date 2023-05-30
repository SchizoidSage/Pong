#ifndef VERTEX_ARRAY_202303172019_HPP
#define VERTEX_ARRAY_202303172019_HPP

#include <GL/glew.h>
#include <vector>

class VertexArray final
{
public:
  VertexArray(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
  ~VertexArray();
  void set_active();
private:
  GLuint m_vertex_buffer[1]{ };
  GLuint m_index_buffer[1]{ };
  GLuint m_array_buffer[1]{ };
};

#endif