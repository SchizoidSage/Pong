#ifndef MOVE_PREDICTION_VISITOR_202304152118_H
#define MOVE_PREDICTION_VISITOR_202304152118_H

class MovePredictionVisitor : public ActorVisitor
{
public:
  MovePredictionVisitor(MoveComponent* move_component)
    : m_move_component{ move_component }
  { }
  void visit_paddle(const Paddle* paddle) override;
  void visit_ball(const Ball* ball) override;
private:
  MoveComponent* m_move_component{ };
};

#endif