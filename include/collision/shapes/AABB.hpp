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

#ifndef AABB_202304111745_HPP
#define AABB_202304111745_HPP

#include <glm/vec2.hpp>

class AABB final
{
public:
	AABB(const glm::vec2& min, const glm::vec2& max) noexcept
    : m_min{ min },
      m_max{ max }
  { }

  bool contains(const glm::vec2& point) const noexcept;

  glm::vec2 min() const noexcept { return m_min; }
  glm::vec2 max() const noexcept { return m_max; }

  void set_min(const glm::vec2& min) noexcept { m_min = min; }
  void set_max(const glm::vec2& max) noexcept { m_max = max; }
private:
	glm::vec2 m_min{ };
	glm::vec2 m_max{ };
};

#endif