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

#include "collision/shapes/AABB.hpp"
#include <glm/vec2.hpp>

bool AABB::contains(const glm::vec2& point) const noexcept
{
	bool outside { 
    point.x < m_min.x ||
		point.y < m_min.y ||
		point.x > m_max.x ||
		point.y > m_max.y 
  };
	// If none of these are true, the point is inside the box
	return !outside;
}