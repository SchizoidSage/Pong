#ifndef BOX_COMPONENT_202304111625_H
#define BOX_COMPONENT_202304111625_H

#include "components/Component.h"
#include "actors/Actor.h"
#include "collision/shapes/AABB.h"
#include <memory>

class BoxComponent : public Component
{
public:
  BoxComponent(Actor* owner, AABB& object_box);
  ~BoxComponent();

  AABB* world_shape() const { return m_world_shape.get(); }

  void on_update_mv_matrix();
private:
  std::unique_ptr<AABB> m_object_shape{ };
  std::unique_ptr<AABB> m_world_shape{ };
};

#endif