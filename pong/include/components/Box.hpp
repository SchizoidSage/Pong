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

#ifndef BOX_202305291754_HPP
#define BOX_202305291754_HPP

#include "collision/shapes/AABB.hpp"
#include <glm/vec2.hpp>
#include <memory>

//! \file Box.hpp

/*! \brief			A collision box
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*
*   A box surrounding an entity for collision detection
*/
class Box final
{
public:
  /*! 
  *   \param min  The coordinates of the box's bottom-left corner
  *   \param max  The coordinates of the box's top-right corner
  */
  Box(const glm::vec2& min, const glm::vec2& max)
    : m_object_box{ std::make_unique<const AABB>(min, max) },
      m_world_box{ std::make_unique<AABB>(min, max) }
  { }

  AABB world_box() const noexcept { return *m_world_box; } //!< Getter for box's world position
  
  /*! Setter for box's world position
  *
  *   \param position The box's new position in the game world
  *   \param scale    The box's size scaling rate
  */
  void set_world_box(const glm::vec2& position, float scale) noexcept;
private:
  const std::unique_ptr<const AABB> m_object_box{ };
  const std::unique_ptr<AABB> m_world_box{ };
};

#endif