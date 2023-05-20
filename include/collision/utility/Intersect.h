#ifndef INTERSECT_202304111828_H
#define INTERSECT_202304111828_H

bool intersect(const AABB& a, const AABB& b);
bool intersect(const LineSegment* line_segment, const AABB* box, float& out_t, Plane& out_norm)
Wall collides_with_wall(LineSegment line);
bool near_equal(float a, float b, float epsilon = 0.001f);
bool near_zero(float a, float epsilon = 0.001f);

#endif