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

#ifndef LINE_SEGMENT_202304151254_HPP
#define LINE_SEGMENT_202304151254_HPP

#include <glm/vec2.hpp>

class LineSegment final
{
public:
  LineSegment(const glm::vec2& start, const glm::vec2& end) noexcept
    : m_start{ start },
      m_end{ end }
  { }

  glm::vec2 point_on_segment(float percentage) const noexcept;
  glm::vec2 start() const noexcept { return m_start; }
  glm::vec2 end() const noexcept { return m_end; }
private:
  const glm::vec2 m_start{ };
  const glm::vec2 m_end{ };
};

#endif