#ifndef BALL_202305261739_HPP
#define BALL_202305261739_HPP

class Ball final
{
public:
  Ball();
  glm::vec2 direction() const { return m_direction; }
  int speed() const { return m_speed; }
  void set_direction(float direction);
  void set_random_direction();
private:
  glm::vec2 m_direction{ };
  const int m_speed{ 15 };
};

#endif