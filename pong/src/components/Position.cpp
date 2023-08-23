#include "components/Position.hpp"
#include <glm/vec2.hpp>

void Position::increment_position(const glm::vec2& increment) noexcept
{
  m_position.x += increment.x;
  m_position.y += increment.y;
}