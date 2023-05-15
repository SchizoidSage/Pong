#ifndef COMPONENT_202303171710_H
#define COMPONENT_202303171710_H

#include "actors/Actor.h"
#include <cstdint>

class Component
{
public:
  Component(Actor* owner)
    : m_actor{ owner }
  { }
  virtual ~Component(){ }
protected:
  Actor* const m_actor{ };
};

#endif