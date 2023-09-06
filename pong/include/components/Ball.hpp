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

#ifndef BALL_202305261739_HPP
#define BALL_202305261739_HPP

#include <glm/vec2.hpp>

//! \file Ball.hpp

/*! \brief			The ball
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*/
class Ball final
{
public:
  Ball();

  glm::vec2 direction() const noexcept { return m_direction; }  //!< Getter for movement direction
  int speed() const noexcept { return m_speed; }                //!< Getter for movement speed
  
  void set_direction(const glm::vec2& direction) noexcept { m_direction = direction; }  //!< Setter for movement direction

  /*! Set a random direction for the ball */
  void set_random_direction();
private:
  glm::vec2 m_direction{ };
  const int m_speed{ 200 };
};

#endif