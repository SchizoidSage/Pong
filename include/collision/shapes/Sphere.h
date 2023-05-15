#ifndef SPHERE_202304151345_H
#define SPHERE_202304151345_H

class Sphere : public ICollisionShape
{
public:
  Sphere(const glm::vec2& center, float radius)
    : ICollisionShape{ },
      m_center{ center },
      m_radius{ radius }
  { }

  void on_update_mv_matrix(glm::vec2 position, float scale) override;
  bool contains(const glm::vec2& point) const;
private:
  glm::vec2 m_center{ };
  float m_radius{ };
};

#endif