#include "systems/MoveSystem.hpp"

void MoveSystem::on_key_down(const KeyDown& key_down) noexcept
{
  switch (key_down.key_code) {
    case SDLK_w:
      m_player_movement = Player::MoveDirection::UP;
      break;

    case SDLK_s:
      m_player_movement = Player::MoveDirection::DOWN;
      break;
  }
}

void MoveSystem::on_key_up(const KeyUp& key_up) noexcept
{
  if (key_up.key_code == SDLK_w || key_up.key_code == SDLK_s) {
    m_player_movement = Player::MoveDirection::STOPPED;
  }
}

void MoveSystem::update(double delta_time, entt::registry& registry)
{
  player_update(delta_time, registry);
  ball_update(delta_time, registry);
  ai_update(delta_time, registry);
}

void MoveSystem::player_update(double delta_time, entt::registry& registry)
{
  const auto player_view{ registry.view<Player, Position, Sprite, Box>() };
  player_view.each([&](auto& player, auto& pos, auto& sprite, auto& box) {
    player.set_direction(m_player_movement);

    if (player.direction() == Player::MoveDirection::UP) {
      pos.increment_position({ 0, player.speed() * delta_time });
      box.set_world_box(pos.position(), sprite.scale());
    } else if (player.direction() == Player::MoveDirection::DOWN) {
      pos.increment_position({ 0, -(player.speed() * delta_time ) });
      box.set_world_box(pos.position(), sprite.scale());
    }

    if ((pos.position().y - sprite.scale()) < Constants::BOTTOM_WALL) {
      pos.set_position({ pos.position().x, Constants::BOTTOM_WALL + sprite.scale() });
      box.set_world_box(pos.position(), sprite.scale());
    } else if ((pos.position().y + sprite.scale()) > Constants::TOP_WALL) {
      pos.set_position({ pos.position().x, Constants::TOP_WALL - sprite.scale() });
      box.set_world_box(pos.position(), sprite.scale());
    }
  });
}

void MoveSystem::ball_update(double delta_time, entt::registry& registry)
{
  auto ball_view{ registry.view<Ball, Position, Sprite, Box>() };
  ball_view.each([&](auto& ball, auto& pos, auto& sprite, auto& box) {

    pos.set_position(pos.position() += (ball.direction() * ball.speed() * delta_time));
    box.set_world_box(pos.position(), sprite.scale());

    if (
      (pos.position().x - sprite.scale() <= Constants::LEFT_WALL) ||
      (pos.position().x + sprite.scale() >= Constants::RIGHT_WALL)
    ) {
      pos.set_position({ 0.f, 0.f });
      box.set_world_box(pos.position(), sprite.scale());
      ball.set_random_direction();
    } else if (pos.position().y - sprite.scale() < Constants::BOTTOM_WALL) {
      pos.set_position({ pos.position().x, Constants::BOTTOM_WALL + sprite.scale() });
      box.set_world_box(pos.position(), sprite.scale());
      ball.set_direction(std::atan2(-ball.direction().y, ball.direction().x));
    } else if (pos.position().y + sprite.scale() > Constants::TOP_WALL) {
      pos.set_position({ pos.position().x, Constants::TOP_WALL - sprite.scale() });
      box.set_world_box(pos.position(), sprite.scale());
      ball.set_direction(std::atan2(-ball.direction().y, ball.direction().x));
    }
  });
}

void MoveSystem::ai_update(double delta_time, entt::registry& registry)
{
  auto ai_view{ registry.view<AI, Position, Sprite, Box>() };
  auto ball_view{ registry.view<Ball, Position, Sprite>() };
  ai_view.each([&](auto& ai, auto& ai_pos, auto& ai_sprite, auto& ai_box) {
    ball_view.each([&](auto& ball, auto& ball_pos, auto& ball_sprite) {
      if (ai_pos.position().y < ball_pos.position().y) {
        ai_pos.increment_position({ 0, ai.speed() * delta_time });
        ai_box.set_world_box(ai_pos.position(), ai_sprite.scale());
      } else if (ai_pos.position().y > ball_pos.position().y) {
        ai_pos.increment_position({ 0, -(ai.speed() * delta_time) });
        ai_box.set_world_box(ai_pos.position(), ai_sprite.scale());
      }

      if ((ai_pos.position().y - ai_sprite.scale()) < Constants::BOTTOM_WALL) {
        ai_pos.set_position({ ai_pos.position().x, Constants::BOTTOM_WALL + ai_sprite.scale() });
        ai_box.set_world_box(ai_pos.position(), ai_sprite.scale());
      } else if ((ai_pos.position().y + ai_sprite.scale()) > Constants::TOP_WALL) {
        ai_pos.set_position({ ai_pos.position().x, Constants::TOP_WALL - ai_sprite.scale() });
        ai_box.set_world_box(ai_pos.position(), ai_sprite.scale());
      }
    });
  });
}