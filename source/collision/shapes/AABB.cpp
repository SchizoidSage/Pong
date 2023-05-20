#include "collision/shapes/AABB.h"
#include <glm/vec2.hpp>

void AABB::on_update_mv_matrix(const glm::vec2& position, float scale)
{
  m_min *= scale;
  m_max *= scale;

  m_min += position;
  m_max += position;
}

bool AABB::contains(const glm::vec2& point)
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