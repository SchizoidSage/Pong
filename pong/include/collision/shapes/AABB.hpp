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

//! \file AABB.hpp

/*! \brief			An axis-aligned bounding box (AABB) structure
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*   \sa         Box, intersect(const AABB&, const AABB&), intersect(const LineSegment&, const AABB&, float&, Side&)
*
*		The axis-aligned bounding box (AABB) structure is an axis-aligned rectangle surrounding \
*   an entity, used for collision detection.
*/
class AABB final
{
public:
  /*! \param min  The coordinates of the AABB's bottom-left corner
  *   \param max  The coordinates of the AABB's top-right corner
  */
	AABB(const glm::vec2& min, const glm::vec2& max) noexcept
    : m_min{ min },
      m_max{ max }
  { }

  /*! Checks if a given point is located inside the AABB's bounds
  *
  *   \param point  A 2D point
  *   \return       Returns true if the point is inside the AABB's bounds
  */
  bool contains(const glm::vec2& point) const noexcept;

  glm::vec2 min() const noexcept { return m_min; } //!< Getter for bottom-left corner
  glm::vec2 max() const noexcept { return m_max; } //!< Getter for top-right corner

  void set_min(const glm::vec2& min) noexcept { m_min = min; } //!< Setter for bottom-left corner
  void set_max(const glm::vec2& max) noexcept { m_max = max; } //!< Setter for top-right corner
private:
	glm::vec2 m_min{ };
	glm::vec2 m_max{ };
};

#endif