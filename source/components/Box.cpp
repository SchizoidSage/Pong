#include "components/Box.hpp"
#include <glm/vec2.hpp>

void Box::set_world_box(glm::vec2 position, float scale)
{
  m_world_box->set_min((m_object_box->min() * scale) + position);
  m_world_box->set_max((m_object_box->max() * scale) + position);
}