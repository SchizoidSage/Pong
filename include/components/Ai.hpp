#ifndef AI_202305261732_HPP
#define AI_202305261732_HPP

class Ai final
{
public:
  int speed() const { return m_speed; }
private:
  const int m_speed{ 15 };
};

#endif