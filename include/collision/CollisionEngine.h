#ifndef COLLISION_ENGINE_202304131738_H
#define COLLISION_ENGINE_202304131738_H

#include "components/BoxComponent.h"
#include <vector>

class CollisionEngine final
{
public:
  CollisionEngine(){ }

  void add_box(BoxComponent* box);
  void remove_box(BoxComponent* box);

  void test_collision();
private:
  std::vector<BoxComponent*> m_box_components{ };
};

#endif