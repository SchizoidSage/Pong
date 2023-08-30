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

#ifndef KEY_DOWN_202305281415_HPP
#define KEY_DOWN_202305281415_HPP

//! \file KeyDown.hpp

/*! \brief      A struct defining the "keyboard key down" event
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU General Public License
*   \sa         MoveSystem
*/
struct KeyDown final
{
  int key_code{ -1 };
};

#endif