#include "collision/shapes/AABB.hpp"
#include <glm/vec2.hpp>

bool AABB::contains(const glm::vec2& point) const noexcept
{
	bool outside { 
    point.x < m_min.x ||
		point.y < m_min.y ||
		point.x > m_max.x ||
		point.y > m_max.y 
  };
	// If none of these are true, the point is inside the box
	return !outside;
}