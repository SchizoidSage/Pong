#ifndef BALL_COLLISION_VISITOR_202304231545_H
#define BALL_COLLISION_VISITOR_202304231545_H

class BallCollisionVisitor : public UpdateComponentVisitor
{
public:
  BallCollisionVisitor(Wall wall)
    : m_wall{ wall }
  { }
  void visit_move_component(MoveComponent* move_component) override;
private:
  Wall m_wall{ Wall::NO_WALL };
};

#endif