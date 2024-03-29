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

#ifndef AI_202305261732_HPP
#define AI_202305261732_HPP

//! \file Ai.hpp

/*! \brief			The CPU-controlled right paddle
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*
*   The right paddle is controlled by the computer and follows the ball.
*/
class Ai final
{
public:
  int speed() const noexcept { return m_speed; } //!< Getter for movement speed
private:
  const int m_speed{ 150 };
};

#endif