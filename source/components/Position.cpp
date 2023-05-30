#include "components/Position.hpp"

void Position::increment_position(glm::vec2 increment)
{
  m_position.x += increment.x;
  m_position.y += increment.y;
}