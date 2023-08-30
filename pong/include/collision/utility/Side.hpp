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

#ifndef SIDE_202305211549_HPP
#define SIDE_202305211549_HPP

//! \file Side.hpp

/*! \brief			A side of an AABB
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*   \sa         AABB, intersect(const LineSegment&, const AABB&, float&, Side&), test_side_plane(float, float, float, Side, std::vector<std::pair<float, Side>>&)
*
*   An enum which helps determine which side of an AABB was involved in a collision
*/
enum class Side 
{
  MIN_X,  //!< The left side
  MAX_X,  //!< The right side
  MIN_Y,  //!< The bottom
  MAX_Y   //!< The top
};

#endif