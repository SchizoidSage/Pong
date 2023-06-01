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