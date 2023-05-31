#include "collision/shapes/LineSegment.hpp"
#include <glm/vec2.hpp>

glm::vec2 LineSegment::point_on_segment(float percentage) const
{
  return m_start + ((m_end - m_start) * percentage);
}