#ifndef SPRITE_COMPONENT_202303171738_H
#define SPRITE_COMPONENT_202303171738_H

#include "actors/Actor.h"
#include "components/Component.h"
#include "Shader.h"

class SpriteComponent final : public Component
{
public:
  SpriteComponent(Actor* owner)
    : Component{ owner }
  { }

  void draw();
};

#endif