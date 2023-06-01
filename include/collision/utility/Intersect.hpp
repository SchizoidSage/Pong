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

bool intersect(const AABB& a, const AABB& b) noexcept;
bool intersect(const LineSegment& line_segment, const AABB& box, float& out_t, Side& out_norm);
bool test_side_plane(float start, float end, float negd, Side norm, std::vector<std::pair<float, Side>>& out);
bool near_zero(float val, float epsilon = 0.001f);

#endif