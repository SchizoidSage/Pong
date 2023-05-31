#ifndef LINE_SEGMENT_202304151254_HPP
#define LINE_SEGMENT_202304151254_HPP

#include <glm/vec2.hpp>

class LineSegment final
{
public:
  LineSegment(const glm::vec2& start, const glm::vec2& end)
    : m_start{ start },
      m_end{ end }
  { }

  glm::vec2 point_on_segment(float percentage) const;
  glm::vec2 start() const { return m_start; }
  glm::vec2 end() const { return m_end; }
private:
  glm::vec2 m_start{ };
  glm::vec2 m_end{ };
};

#endif