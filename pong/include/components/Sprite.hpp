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

#ifndef SPRITE_202305261956_HPP
#define SPRITE_202305261956_HPP

#include "utility/EntityType.hpp"

//! \file Sprite.hpp

/*! \brief			The sprite of an entity
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*/
class Sprite final
{
public:
  /*! \param entity_type  The type of the associated entity
  *   \param scale        The sprite's size scaling rate
  *   \param rotation     The sprite's rotation rate
  */
  Sprite(EntityType entity_type, float scale = 1.f, float rotation = 0.f) noexcept
    : m_entity_type{ entity_type },
      m_scale{ scale }, 
      m_rotation{ rotation }
  { }

  float scale() const noexcept { return m_scale; }                  //!< Getter for sprite's size scaling rate
  float rotation() const noexcept { return m_rotation; }            //!< Getter for sprite's rotation rate
  EntityType entity_type() const noexcept { return m_entity_type; } //!< Getter for the type of the associated entity
private:
  EntityType m_entity_type{ };
  float m_scale{ 1.f };
  float m_rotation{ 0.f };
};

#endif