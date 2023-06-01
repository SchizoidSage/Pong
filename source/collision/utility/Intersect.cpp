#include "collision/utility/Intersect.hpp"
#include "collision/shapes/AABB.hpp"
#include "collision/shapes/LineSegment.hpp"
#include "collision/utility/Side.hpp"
#include <glm/vec2.hpp>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

bool intersect(const AABB& a, const AABB& b) noexcept
{
  bool no_intersection{ 
    a.max().x < b.min().x ||
		a.max().y < b.min().y ||
		b.max().x < a.min().x ||
		b.max().y < a.min().y
  };
	// If none of these are true, they must intersect
	return !no_intersection;
}

bool intersect(const LineSegment& line_segment, const AABB& box, float& out_t, Side& out_norm)
{
	// Vector to save all possible t values, and normals for those sides
	std::vector<std::pair<float, Side>> t_values;
  
	// Test the x planes
	test_side_plane(line_segment.start().x, line_segment.end().x, box.min().x, Side::MIN_X, t_values);
	test_side_plane(line_segment.start().x, line_segment.end().x, box.max().x, Side::MAX_X, t_values);
	// Test the y planes
	test_side_plane(line_segment.start().y, line_segment.end().y, box.min().y, Side::MIN_Y, t_values);
	test_side_plane(line_segment.start().y, line_segment.end().y, box.max().y, Side::MAX_Y, t_values);
	
	// Sort the t values in ascending order
	std::sort(t_values.begin(), t_values.end(), [](const auto& a, const auto& b) {
		return a.first < b.first;
	});
	// Test if the box contains any of these points of intersection
	glm::vec2 point{ };
	for (const auto& t : t_values) {
		point = line_segment.point_on_segment(t.first);
		if (box.contains(point)) {
			out_t = t.first;
			out_norm = t.second;
			return true;
		}
	}

	//None of the intersections are within bounds of box
	return false;
}

bool test_side_plane(float start, float end, float negd, Side norm, std::vector<std::pair<float, Side>>& out)
{
	const float denom{ end - start };
	if (near_zero(denom)) {
		return false;
	} else {
		const float numer{ -start + negd };
		const float t{ numer / denom };
		// Test that t is within bounds
		if (t >= 0.0f && t <= 1.0f) {
			out.emplace_back(t, norm);
			return true;
		}
		return false;
	}
}

bool near_zero(float val, float epsilon)
{
	if (std::abs(val) <= epsilon) {
		return true;
	}
	return false;
}