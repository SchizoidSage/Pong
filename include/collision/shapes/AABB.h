#ifndef AABB_202304111745_H
#define AABB_202304111745_H

#include <glm/vec2.hpp>

class AABB final
{
public:
	AABB(const glm::vec2& min, const glm::vec2& max)
      m_min{ min },
      m_max{ max }
  { }

  void on_update_mv_matrix(const glm::vec2& position, float scale);
  bool contains(const glm::vec2& point) const;

  glm::vec2 min() const { return m_min; }
  glm::vec2 max() const { return m_max; }
private:
	glm::vec2 m_min{ };
	glm::vec2 m_max{ };
};

#endif