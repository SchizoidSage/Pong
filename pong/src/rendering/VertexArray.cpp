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