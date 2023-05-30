#ifndef INTERSECT_202304111828_HPP
#define INTERSECT_202304111828_HPP

#include "collision/shapes/AABB.h"
#include "collision/shapes/LineSegment.h"
#include "collision/utility/Side.h"
#include <vector>
#include <utility>

bool intersect(const AABB* a, const AABB* b);
bool intersect(const LineSegment* line_segment, const AABB* box, float& out_t, Side& out_norm);
bool test_side_plane(float start, float end, float negd, Side norm, std::vector<std::pair<float, Side>>& out);

#endif