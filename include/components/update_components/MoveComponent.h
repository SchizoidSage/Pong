#ifndef MOVE_COMPONENT_202304031741_H
#define MOVE_COMPONENT_202304031741_H

#include "components/UpdateComponent.h"
#include "actors/Actor.h"
#include <glm/vec2.hpp>
#include <cmath>

class MoveComponent final : public UpdateComponent
{
public:
  MoveComponent(Actor* owner, int speed, float direction, int update_order = 10)
    : UpdateComponent{ owner, update_order },
      m_speed{ speed },
      m_direction{ direction },
      m_forward{ glm::vec2(std::cosf(direction), std::sinf(direction)) }
  { }

  void update(float delta_time) override;

  float direction() const { return m_direction; }
  float frame_speed() const { return m_frame_speed; }
  glm::vec2 forward() const { return m_forward; }
  
  void set_direction(float direction);
  void set_speed(int speed);
private:
  int m_speed{ };
  float m_direction{ };
  glm::vec2 m_forward{ };
  float m_frame_speed{ };
};

#endif