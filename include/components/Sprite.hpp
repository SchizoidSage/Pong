#ifndef SPRITE_202305261956_HPP
#define SPRITE_202305261956_HPP

#include "utility/EntityType.hpp"

class Sprite final
{
public:
  Sprite(EntityType entity_type, float scale = 1.f, float rotation = 0.f) noexcept
    : m_entity_type{ entity_type },
      m_scale{ scale }, 
      m_rotation{ rotation }
  { }

  float scale() const noexcept { return m_scale; }
  float rotation() const noexcept { return m_rotation; }
  EntityType entity_type() const noexcept { return m_entity_type; }
private:
  EntityType m_entity_type{ };
  float m_scale{ 1.f };
  float m_rotation{ 0.f };
};

#endif