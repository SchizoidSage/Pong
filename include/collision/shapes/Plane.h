#ifndef PLANE_202304151416_H
#define PLANE_202304151416_H

class Plane
{
public:
  Plane(const glm::vec2& normal, float d)
    : m_normal{ normal },
      m_d{ d }
  { }

  float signed_distance(const glm::vec2& point) const;
private:
  glm::vec2 m_normal{ };
  float m_d{ };
};

#endif