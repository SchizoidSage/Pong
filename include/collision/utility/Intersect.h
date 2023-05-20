#ifndef INTERSECT_202304111828_H
#define INTERSECT_202304111828_H

#include "collision/shapes/AABB.h"
#include "collision/shapes/LineSegment.h"
#include "collision/utility/Side.h"

bool intersect(const AABB& a, const AABB& b);
bool intersect(const LineSegment* line_segment, const AABB* box, float& out_t, Side& out_norm)
bool near_equal(float a, float b, float epsilon = 0.001f);
bool near_zero(float a, float epsilon = 0.001f);

#endif