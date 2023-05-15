#ifndef ACTOR_VISITOR_202304152050_H
#define ACTOR_VISITOR_202304152050_H

class ActorVisitor
{
public:
  virtual ~ActorVisitor(){ }
  virtual void visit_paddle(const Paddle* paddle) = 0;
  virtual void visit_ball(const Ball* ball) = 0;
};

#endif