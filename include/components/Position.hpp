#ifndef POSITION_202305261949_HPP
#define POSITION_202305261949_HPP

#include <glm/vec2.hpp>

class Position final
{
public:
  Position(double x, double y) noexcept
    : m_position{ x, y }
  { }

  glm::vec2 position() const { return m_position; }
  void set_position(glm::vec2 position) { m_position = position; }
  void increment_position(glm::vec2 increment);
private:
  glm::vec2 m_position{ };
};

#endif