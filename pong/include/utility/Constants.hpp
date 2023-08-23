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

namespace Constants 
{
  inline constexpr int SCREEN_HEIGHT{ 768 };
  inline constexpr float TOP_WALL{ SCREEN_HEIGHT / 2 };
  inline constexpr float BOTTOM_WALL{ -(SCREEN_HEIGHT / 2) };

  inline constexpr int SCREEN_WIDTH{ 1024 };
  inline constexpr float LEFT_WALL{ -(SCREEN_WIDTH / 2) };
  inline constexpr float RIGHT_WALL{ SCREEN_WIDTH / 2 };

  inline constexpr float PI{ 3.141593f };
}

#endif