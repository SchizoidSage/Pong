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

//! \file LineSegment.hpp

/*! \brief			A line segment
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU General Public License
*   \sa         intersect(const LineSegment&, const AABB&, float&, Side&)
*
*		A line representing an entity's movement trajectory.
*/
class LineSegment final
{
public:
  /*! \param start  Starting point of the trajectory
  *   \param end    Endpoint of the trajectory
  */
  LineSegment(const glm::vec2& start, const glm::vec2& end) noexcept
    : m_start{ start },
      m_end{ end }
  { }

  /*! Gets the point on the line that is some percentage along its length
  *   
  *   \param percentage The percentage along the line's length where the point should be found
  *   \return           The 2D point located at some percentage along the line
  */
  glm::vec2 point_on_segment(float percentage) const noexcept;
  
  glm::vec2 start() const noexcept { return m_start; }  //!< Getter for starting point
  glm::vec2 end() const noexcept { return m_end; }      //!< Getter for endpoint
private:
  const glm::vec2 m_start{ };
  const glm::vec2 m_end{ };
};

#endif