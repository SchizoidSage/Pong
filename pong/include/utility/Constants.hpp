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

#ifndef CONSTANTS_202303151959_HPP
#define CONSTANTS_202303151959_HPP

//! \file Constants.hpp

/*! \brief			Useful global constants
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*/
namespace Constants 
{
  inline constexpr int SCREEN_HEIGHT{ 768 };                  //!< Screen height
  inline constexpr float TOP_WALL{ SCREEN_HEIGHT / 2 };       //!< Y-coordinate of top wall
  inline constexpr float BOTTOM_WALL{ -(SCREEN_HEIGHT / 2) }; //!< Y-coordinate of bottom wall

  inline constexpr int SCREEN_WIDTH{ 1024 };                  //!< Screen width
  inline constexpr float LEFT_WALL{ -(SCREEN_WIDTH / 2) };    //!< X-coordinate of left wall
  inline constexpr float RIGHT_WALL{ SCREEN_WIDTH / 2 };      //!< X-coordinate of right wall

  inline constexpr float PI{ 3.141593f };                     //!< Pi
}

#endif