#ifndef AI_202305261732_HPP
#define AI_202305261732_HPP

class Ai final
{
public:
  int speed() const noexcept { return m_speed; }
private:
  const int m_speed{ 100 };
};

#endif