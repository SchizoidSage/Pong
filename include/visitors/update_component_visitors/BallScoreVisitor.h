#ifndef BALL_SCORE_VISITOR_202304251947_H
#define BALL_SCORE_VISITOR_202304251947_H

class BallScoreVisitor : public BallCollisionVisitor
{
public:
  void visit_score_component(ScoreComponent* score_component) override;
};

#endif