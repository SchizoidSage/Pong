/*
* Pong: A Pong Game with OpenGL, SDL2 and EnTT 
* Copyright (C) 2023  SchizoidSage
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "systems/MoveSystem.hpp"
#include "events/KeyDown.hpp"
#include "events/KeyUp.hpp"
#include "components/All.hpp"
#include "utility/Constants.hpp"
#include <entt/entt.hpp>
#include <SDL.h>

void MoveSystem::on_key_down(const KeyDown& key_down) noexcept
{
  switch (key_down.key_code) {
    case SDLK_s:
      m_player_movement = Player::MoveDirection::UP;
      break;

    case SDLK_w:
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

void MoveSystem::update(float delta_time, entt::registry& registry) const
{
  player_update(delta_time, registry);
  ball_update(delta_time, registry);
  ai_update(delta_time, registry);
}

void MoveSystem::player_update(float delta_time, entt::registry& registry) const
{
  const auto player_view{ registry.view<Player, Position, const Sprite, Box>() };
  player_view.each([&](auto& player, auto& pos, const auto& sprite, auto& box) {
    player.set_direction(m_player_movement);

    if (player.direction() == Player::MoveDirection::UP) {
      pos.increment_position({ 0, player.speed() * delta_time });
      box.set_world_box(pos.position(), sprite.scale());
    } else if (player.direction() == Player::MoveDirection::DOWN) {
      pos.increment_position({ 0, -(player.speed() * delta_time) });
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

void MoveSystem::ball_update(float delta_time, entt::registry& registry) const
{
  const auto ball_view{ registry.view<Ball, Position, const Sprite, Box>() };
  ball_view.each([&](auto& ball, auto& pos, const auto& sprite, auto& box) {

    pos.set_position(pos.position() += (ball.direction() * (ball.speed() * delta_time)));
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
      ball.set_direction({ ball.direction().x, -ball.direction().y });
    } else if (pos.position().y + sprite.scale() > Constants::TOP_WALL) {
      pos.set_position({ pos.position().x, Constants::TOP_WALL - sprite.scale() });
      box.set_world_box(pos.position(), sprite.scale());
      ball.set_direction({ ball.direction().x, -ball.direction().y });
    }
  });
}

void MoveSystem::ai_update(float delta_time, entt::registry& registry) const
{
  const auto ai_view{ registry.view<const Ai, Position, const Sprite, Box>() };
  const auto ball_view{ registry.view<const Ball, const Position>() };
  ai_view.each([&](const auto& ai, auto& ai_pos, const auto& ai_sprite, auto& ai_box) {
    ball_view.each([&]([[maybe_unused]]const auto& ball, const auto& ball_pos) {
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