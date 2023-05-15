#ifndef COMPONENT_VISITOR_202304222153_H
#define COMPONENT_VISITOR_202304222153_H

class UpdateComponentVisitor
{
public:
  virtual ~UpdateComponentVisitor(){ }
  virtual void visit_move_component(MoveComponent* move_component) = 0;
  virtual void visit_score_component(ScoreComponent* score_component){ }
};

#endif