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

#ifndef INTERSECT_202304111828_HPP
#define INTERSECT_202304111828_HPP

#include "collision/shapes/AABB.hpp"
#include "collision/shapes/LineSegment.hpp"
#include "collision/utility/Side.hpp"
#include <vector>
#include <utility>

/*! \file       Intersect.hpp
*   \brief			Helper functions for collision detection
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*/

/*! Checks if two AABB's intersect
*
*   \param a  The first AABB
*   \param b  The second AABB
*   \return   Returns true if the two AABB's intersect
*/
bool intersect(const AABB& a, const AABB& b) noexcept;

/*! Checks if a LineSegment and an AABB intersect, and sets the intersection's location
*
*   \param line_segment The line to check
*   \param box          The box to check
*   \param out_t        An out parameter set to the percentage along the line where the intersection occurs
*   \param out_norm     An out parameter set to the side of the box which intersects with the line first
*   \return             Returns true if an intersection occurs
*/
bool intersect(const LineSegment& line_segment, const AABB& box, float& out_t, Side& out_norm);

/*! Tests if X- or Y-coordinate of a box's side lies between X- or Y-coordinates of a line's start and end
*
*   \param start  The X- or Y-coordinate of the line's start
*   \param end    The X- or Y-coordinate of the line's end
*   \param negd   The X- or Y-coordinate of the box's side
*   \param norm   The side of the box which is being checked (also determines whether X- or Y-axis is checked)
*   \param out    An out parameter to save the Side if an intersection occurs, and the percentage along the line where it occurs
*   \return       Returns true if an intersection occurs
*/
bool test_side_plane(float start, float end, float negd, Side norm, std::vector<std::pair<float, Side>>& out);

/*! Tests if a value is too close to zero
*
*   \param val      The value to be checked
*   \param epsilon  The upper limit
*   \returns        Returns true if val's absolute value is between zero and epsilon
*/
bool near_zero(float val, float epsilon = 0.001f);

#endif