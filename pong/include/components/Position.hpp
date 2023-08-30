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

#ifndef POSITION_202305261949_HPP
#define POSITION_202305261949_HPP

#include <glm/vec2.hpp>

//! \file Position.hpp

/*! \brief			The 2D position of an entity
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*/
class Position final
{
public:
  /*! \param x The X-coordinate
  *   \param y The Y-coordinate
  */
  Position(double x, double y) noexcept
    : m_position{ x, y }
  { }

  glm::vec2 position() const noexcept { return m_position; }  //!< Getter for position

  void set_position(const glm::vec2& position) noexcept { m_position = position; } //!< Setter for position

  /*! Increases the position's coordinates by the given vector
  *
  *   \param increment  The vector by which the current position must be incremented
  */
  void increment_position(const glm::vec2& increment) noexcept;
private:
  glm::vec2 m_position{ };
};

#endif