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

#ifndef COLLISION_SYSTEM_202305291300_HPP
#define COLLISION_SYSTEM_202305291300_HPP

#include "io/Audio.hpp"
#include <entt/entt.hpp>
#include <AL/al.h>
#include <memory>

class CollisionSystem
{
public:
  CollisionSystem();
  ~CollisionSystem();
  void update(float delta_time, entt::registry& registry) const;
private:
  static void al_callback([[maybe_unused]] void* unused, [[maybe_unused]] ALuint unused2);

  ALuint m_source{ };
  ALuint m_buffer{ };
  static bool m_sound_playing;
};

#endif