void AABB::on_update_mv_matrix(glm::vec2 position, float scale)
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

float AABB::minimum_distance_squared(const glm::vec2& point)
{
	// Compute differences for each axis
	float dx{ std::max(std::max(m_min.x - point.x, 0.0f), point.x - m_max.x) };
	float dy{ std::max(std::max(m_min.y - point.y, 0.0f), point.y - m_max.y) };
	// Distance squared formula
	return std::pow(dx, 2) + std::pow(dy, 2);
}