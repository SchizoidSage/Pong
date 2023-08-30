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

#ifndef MOVE_SYSTEM_202305281428_HPP
#define MOVE_SYSTEM_202305281428_HPP

#include "events/KeyDown.hpp"
#include "events/KeyUp.hpp"
#include "components/Player.hpp"
#include <entt/entt.hpp>

//! \file MoveSystem.hpp

/*! \brief			The movement system
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*   \sa         Game
*/
class MoveSystem final
{
public:
  /*! Action on keydown event
  *
  *   \param key_down The keydown event
  */
  void on_key_down(const KeyDown& key_down) noexcept;

  /*! Action on keyup event
  *
  *   \param key_up The keyup event
  */
  void on_key_up(const KeyUp& key_up) noexcept;

  /*! Updates entities' location based on their movement
  *
  *   \param delta_time The time passed since the last frame
  *   \param registry   The entity registry
  */
  void update(float delta_time, entt::registry& registry) const;

  /*! Set the collision box locations of all entities at start-up
  *
  *   \param registry The entity registry
  *   \sa             Box
  */
  void set_init_world_box(entt::registry& registry) const;
private:
  void player_update(float delta_time, entt::registry& registry)const;
  void ball_update(float delta_time, entt::registry& registry) const;
  void ai_update(float delta_time, entt::registry& registry) const;

  Player::MoveDirection m_player_movement{ Player::MoveDirection::STOPPED };
};

#endif