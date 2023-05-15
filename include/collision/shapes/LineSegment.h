#ifndef LINE_SEGMENT_202304151254_H
#define LINE_SEGMENT_202304151254_H

class LineSegment
{
public:
  LineSegment(const glm::vec2& start, const glm::vec2& end)
    : m_start{ start },
      m_end{ end }
  { }

  glm::vec2 point_on_segment(float percentage) const;
  float minimum_distance_squared(const glm::vec2& point) const;
  glm::vec2 start() const { return m_start; }
  glm::vec2 end() const { return m_end; }
private:
  glm::vec2 m_start{ };
  glm::vec2 m_end{ };
};

float minimum_distance_squared(const LineSegment& l1, const LineSegment& l2);

#endif