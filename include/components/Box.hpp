#ifndef BOX_202305291754_HPP
#define BOX_202305291754_HPP

class Box final
{
public:
  Box(glm::vec2 min, glm::vec2 max)
    : m_object_box{ min, max },
      m_world_box{ min, max }
  { }
  AABB* world_box() const { return m_world_box.get(); }
  void set_world_box(glm::vec2 position, float scale);
private:
  std::unique_ptr<AABB> m_object_box{ std::make_unique<AABB>() };
  std::unique_ptr<AABB> m_world_box{ std::make_unique<AABB>() };
};

#endif