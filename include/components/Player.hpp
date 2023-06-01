#ifndef PLAYER_202305261946_HPP
#define PLAYER_202305261946_HPP

class Player final
{
public:
  enum class MoveDirection
  {
    STOPPED,
    UP,
    DOWN
  };

  int speed() const noexcept { return m_speed; }
  MoveDirection direction() const noexcept { return m_direction; }
  void set_direction(MoveDirection direction) noexcept { m_direction = direction; }
private:  
  MoveDirection m_direction{ MoveDirection::STOPPED };
  const int m_speed{ 15 };
};

#endif