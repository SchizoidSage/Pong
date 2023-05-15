void ScoreComponent::update(float delta_time)
{
  if (has_scored) {
    ++m_score;
    has_scored = false;
    m_actor->kill();
    if (m_score == 5) {
      m_actor->game()->game_stopped();
    }
  }
}

void accept(UpdateComponentVisitor* visitor)
{
  visitor->visit_score_component(this);
}