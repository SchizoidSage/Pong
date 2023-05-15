#ifndef SCORE_COMPONENT_202304031950_H
#define SCORE_COMPONENT_202304031950_H

class ScoreComponent : public UpdateComponent
{
public:
  ScoreComponent(Actor* owner)
    : UpdateComponent{ owner }
  { }

  void update(float delta_time) override;
  void set_has_scored() { m_has_scored = true; }
  void accept(UpdateComponentVisitor* visitor) override;
private:
  int m_score{ 0 };
  bool m_has_scored{ false };
};

#endif