#ifndef BALL_202303171859_H
#define BALL_202303171859_H

#include "actors/Actor.h"
#include "Game.h"
#include "rendering/VertexArray.h"
#include <memory>

class Ball final : public Actor
{
public:
  Ball(Game* owner);
  ~Ball();
  VertexArray* vertex_array() override const { return m_vertex_array; }
  void component_update(float delta_time) override;
  void actor_update() override;
  void handle_collision(Actor* collider) override;
private:
  std::unique_ptr<MoveComponent> m_move_component{ };
  static int m_instances{ 0 };
  static VertexArray* m_vertex_array{ };
};

#endif