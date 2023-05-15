#ifndef I_COLLISION_SHAPE_202304151246_H
#define I_COLLISION_SHAPE_202304151246_H

class ICollisionShape
{
public:
  ICollisionShape(){ }
  virtual void on_update_mv_matrix(glm::vec2 position, float scale) = 0;
};

#endif