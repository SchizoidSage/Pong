#ifndef INTERSECT_202304111828_H
#define INTERSECT_202304111828_H

bool Intersect(const AABB& a, const AABB& b);
Wall collides_with_wall(LineSegment line);
Wall collides_with_wall(Capsule capsule);

#endif