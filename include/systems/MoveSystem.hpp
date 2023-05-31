#ifndef MOVE_SYSTEM_202305281428_HPP
#define MOVE_SYSTEM_202305281428_HPP

#include "events/KeyDown.hpp"
#include "events/KeyUp.hpp"
#include "components/Player.hpp"
#include <entt/entt.hpp>

class MoveSystem final
{
public:
  void on_key_down(const KeyDown& key_down) noexcept;
  void on_key_up(const KeyUp& key_up) noexcept;
  void update(float delta_time, entt::registry& registry) const;
private:
  void player_update(float delta_time, entt::registry& registry)const ;
  void ball_update(float delta_time, entt::registry& registry) const;
  void ai_update(float delta_time, entt::registry& registry) const;

  Player::MoveDirection m_player_movement{ Player::MoveDirection::STOPPED };
};

#endif