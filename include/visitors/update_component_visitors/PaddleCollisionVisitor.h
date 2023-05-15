#ifndef PADDLE_COLLISION_VISITOR_202304231537_H
#define PADDLE_COLLISION_VISITOR_202304231537_H

class PaddleCollisionVisitor : public UpdateComponentVisitor
{
  void visit_move_component(MoveComponent* move_component) override;
};

#endif