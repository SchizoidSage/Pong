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

#include "systems/CollisionSystem.hpp"
#include "collision/utility/Intersect.hpp"
#include "collision/utility/Side.hpp"
#include "collision/shapes/LineSegment.hpp"
#include "components/Ball.hpp"
#include "components/Position.hpp"
#include "components/Sprite.hpp"
#include "components/Box.hpp"
#include <entt/entt.hpp>
#include <AL/al.h>
#include <AL/alure.h>
#include <stdexcept>
#include <string>

bool CollisionSystem::m_sound_playing{ false };

CollisionSystem::CollisionSystem()
{
  alGenSources(1, &m_source);
  if(alGetError() != AL_NO_ERROR) {
    throw std::runtime_error{ "Failed to create OpenAL source!\n" };
  }

  m_buffer = alureCreateBufferFromFile("../audio/beep.wav");
  if(!m_buffer) {
    alDeleteSources(1, &m_source);
    throw std::runtime_error{ std::string{ "Failed to create OpenAL buffer: " } + alureGetErrorString() + '\n' };
  }

  alSourcei(m_source, AL_BUFFER, static_cast<ALint>(m_buffer));
}

CollisionSystem::~CollisionSystem()
{
  alDeleteSources(1, &m_source);
  alDeleteBuffers(1, &m_buffer);
}

void CollisionSystem::al_callback([[maybe_unused]] void* unused, [[maybe_unused]] ALuint unused2)
{
  m_sound_playing = false;
}

void CollisionSystem::update(float delta_time, entt::registry& registry) const
{
  const auto ball_view{ registry.view<Ball, Position, const Sprite, Box>() };
  const auto paddle_view{ registry.view<const Box>(entt::exclude<Ball>) };

  ball_view.each([&](auto& ball, auto& ball_pos, const auto& ball_sprite, auto& ball_box) {
    paddle_view.each([&](const auto& paddle_box) {
      if (intersect(paddle_box.world_box(), ball_box.world_box())) {
        const LineSegment line{ ball_pos.position() + (-ball.direction() * (ball.speed() * delta_time)), ball_pos.position() };
        float t{ };
        Side side{ };
        intersect(line, paddle_box.world_box(), t, side);
        switch (side) {
          case Side::MIN_X:
          case Side::MAX_X:
            ball.set_direction({ -ball.direction().x, ball.direction().y });
            break;
          case Side::MIN_Y:
          case Side::MAX_Y:
            ball.set_direction({ ball.direction().x, -ball.direction().y });
            break;
        }
        ball_pos.set_position(line.point_on_segment(t) + (ball.direction() * (ball.speed() * delta_time * (1 - t))));
        ball_box.set_world_box(ball_pos.position(), ball_sprite.scale());
        
        if (m_sound_playing) {
          alureStopSource(m_source, true);
        }
        alurePlaySource(m_source, CollisionSystem::al_callback, NULL);
        m_sound_playing = true;
      }
    });
  });
}