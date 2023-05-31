#ifndef BOX_202305291754_HPP
#define BOX_202305291754_HPP

#include "collision/shapes/AABB.hpp"
#include <glm/vec2.hpp>
#include <memory>

class Box final
{
public:
  Box(const glm::vec2& min, const glm::vec2& max)
    : m_object_box{ std::make_unique<const AABB>(min, max) },
      m_world_box{ std::make_unique<AABB>(min, max) }
  { }
  const AABB& world_box() const { return *(m_world_box.get()); }
  void set_world_box(glm::vec2 position, float scale);
private:
  const std::unique_ptr<const AABB> m_object_box{ };
  const std::unique_ptr<AABB> m_world_box{ };
};

#endif