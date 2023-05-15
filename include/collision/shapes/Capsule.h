#ifndef CAPSULE_202304151409_H
#define CAPSULE_202304151409_H

class Capsule
{
public:
  Capsule(const glm::vec2& start, const glm::vec2& end, float radius)
    : m_line_segment{ start, end },
      m_radius{ radius }
  { }

  glm::vec2 point_on_segment(float percentage) const;
  bool contains(const glm::vec2& point) const;
  float radius() const { return m_radius; }
  glm::vec2 line_end() const { return m_line_segment.end(); }
private:
  LineSegment m_line_segment{ };
  float m_radius{ };
};

#endif