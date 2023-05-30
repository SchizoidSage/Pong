#ifndef MOVE_SYSTEM_202305281428_HPP
#define MOVE_SYSTEM_202305281428_HPP

class MoveSystem final
{
public:
  void on_key_down(const KeyDown& key_down) noexcept;
  void on_key_up(const KeyUp& key_up) noexcept;
  void update(double delta_time, entt::registry& registry);
private:
  void player_update(double delta_time, entt::registry& registry);
  void ball_update(double delta_time, entt::registry& registry);
  void ai_update(double delta_time, entt::registry& registry);

  Player::MoveDirection m_player_movement{ Player::MoveDirection::STOPPED };
};

#endif