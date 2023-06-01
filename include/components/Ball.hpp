#ifndef BALL_202305261739_HPP
#define BALL_202305261739_HPP

#include <glm/vec2.hpp>

class Ball final
{
public:
  Ball();
  glm::vec2 direction() const noexcept { return m_direction; }
  int speed() const noexcept { return m_speed; }
  
  void set_direction(const glm::vec2& direction) noexcept { m_direction = direction; }
  void set_random_direction();

  bool is_immune() const noexcept;
  void decrement_immunity() noexcept { --m_immunity_ticks; }
  void set_immune() noexcept { m_immunity_ticks = 5; }
private:
  glm::vec2 m_direction{ };
  const int m_speed{ 200 };
  int m_immunity_ticks{ 0 };
};

#endif