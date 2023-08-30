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

#ifndef KEY_UP_202305281420_HPP
#define KEY_UP_202305281420_HPP

//! \file KeyUp.hpp

/*! \brief      A struct defining the "keyboard key up" event
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU General Public License
*   \sa         MoveSystem
*/
struct KeyUp final
{
  int key_code{ -1 };
};

#endif