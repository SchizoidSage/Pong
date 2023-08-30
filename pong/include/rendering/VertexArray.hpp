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

#ifndef VERTEX_ARRAY_202303172019_HPP
#define VERTEX_ARRAY_202303172019_HPP

#include <GL/glew.h>
#include <vector>

//! \file VertexArray.hpp

/*! \brief			An OpenGL vertex array
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*   \sa         RenderSystem
*/
class VertexArray final
{
public:
  /*! \param vertices The vertex buffer objects
  *   \param indices  The indices
  */
  VertexArray(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
  ~VertexArray();

  /*! Activates this vertex array */
  void set_active() const;
private:
  GLuint m_vertex_buffer[1]{ };
  GLuint m_index_buffer[1]{ };
  GLuint m_array_buffer[1]{ };
};

#endif