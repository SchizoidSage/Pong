#ifndef PADDLE_202303171903_H
#define PADDLE_202303171903_H

#include "actors/Actor.h"
#include "Game.h"

class Paddle final : public Actor
{
public:
  Paddle(Game* owner, float x, float y, Player player);
  ~Paddle();
  VertexArray* vertex_array() const { return m_vertex_array; }
  void process_input(const uint8_t* key_state) override;
  void component_update(float delta_time) override;
  void actor_update() override;
  void accept(ActorVisitor* visitor) override;
private:
  std::unique_ptr<MoveComponent> m_move_component{ };
  static int m_instances{ 0 };
  static VertexArray* m_vertex_array{ };
  Player m_player{ };
};
#endif