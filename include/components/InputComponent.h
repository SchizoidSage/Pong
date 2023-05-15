#ifndef INPUT_COMPONENT_202303171833_H
#define INPUT_COMPONENT_202303171833_H

#include "actors/Actor.h"
#include "components/Component.h"
#include <cstdint>

class InputComponent : public Component
{
public:
  InputComponent(Actor* owner, int update_order = 10)
    : Component(owner, update_order)
  { }
  void process_input(const uint8_t* key_state);
private:
  int m_forward_key{ };
  int m_backward_key{ };
  int m_clockwise_key{ };
  int m_counterclockwise_key{ };
};

#endif