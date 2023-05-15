#ifndef VERTEX_ARRAY_202303172019_H
#define VERTEX_ARRAY_202303172019_H

#include <GL/glew.h>
#include <vector>

class VertexArray final
{
public:
  VertexArray(const std::vector<float>& vertices, const std::vector<int>& indices);
  ~VertexArray();
  void set_active();
private:
  GLuint m_vertex_buffer[]{ };
  GLuint m_index_buffer[]{ };
  GLuint m_array_buffer[]{ };
};

#endif