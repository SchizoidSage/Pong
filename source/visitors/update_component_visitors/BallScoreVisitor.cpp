void BallScoreVisitor::visit_score_component(ScoreComponent* score_component)
{
  score_component->set_has_scored();
}