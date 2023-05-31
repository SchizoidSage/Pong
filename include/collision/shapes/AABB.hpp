#ifndef AABB_202304111745_HPP
#define AABB_202304111745_HPP

#include <glm/vec2.hpp>

class AABB final
{
public:
	AABB(const glm::vec2& min, const glm::vec2& max)
    : m_min{ min },
      m_max{ max }
  { }

  bool contains(const glm::vec2& point) const;

  glm::vec2 min() const { return m_min; }
  glm::vec2 max() const { return m_max; }

  void set_min(const glm::vec2& min) { m_min = min; }
  void set_max(const glm::vec2& max) { m_max = max; }
private:
	glm::vec2 m_min{ };
	glm::vec2 m_max{ };
};

#endif