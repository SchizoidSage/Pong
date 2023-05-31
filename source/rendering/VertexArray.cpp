#include "rendering/VertexArray.hpp"
#include <GL/glew.h>
#include <vector>

VertexArray::VertexArray(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
{
  glGenVertexArrays(1, m_array_buffer);
  glGenBuffers(1, m_vertex_buffer);
  glGenBuffers(1, m_index_buffer);

  glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer[0]);
  glBufferData(GL_ARRAY_BUFFER, static_cast<long>(sizeof(float) * vertices.size()), vertices.data(), GL_STATIC_DRAW);
  glBindVertexArray(m_array_buffer[0]);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer[0]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<long>(sizeof(unsigned int) * indices.size()), indices.data(), GL_STATIC_DRAW);
}

VertexArray::~VertexArray()
{
  glDeleteBuffers(1, m_vertex_buffer);
  glDeleteBuffers(1, m_index_buffer);
  glDeleteVertexArrays(1, m_array_buffer);
}

void VertexArray::set_active() const
{
  glBindVertexArray(m_array_buffer[0]);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_index_buffer[0]);
}