#ifndef ACTOR_202303111839_H
#define ACTOR_202303111839_H

#include "Game.h"
#include "components/InputComponent.h"
#include "components/SpriteComponent.h"
#include "rendering/VertexArray.h"
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include <memory>
#include <cstdint>

class Actor
{
public:
  enum class State {
    ACTIVE,
    PAUSED,
    DEAD
  };

  Actor(Game* game)
    : m_game{ game }
  { }
  virtual ~Actor(){ }

  virtual void process_input(const uint8_t* key_state){ }

  void update(float delta_time);
  virtual void component_update() = 0;
  virtual void actor_update() = 0;

  void draw();

  virtual void handle_collision(Actor* collider){ }

  glm::vec2 position() const { return m_position; }
  float scale() const { return m_scale; }
  float rotation() const { return rotation; }
  virtual VertexArray* vertex_array() = 0;

  void set_position(const glm::vec2& position);
  void set_scale(float scale);
  void set_rotation(float rotation);

  void update_mv_matrix();
  void set_mv_matrix_update_needed() { m_update_mv_matrix = true; }

  void set_state(State state) { m_state = state; }
  glm::mat4 mv_matrix() const { return m_mv_matrix; }

  void set_input_component(InputComponent* component) { m_input_component = component; }
  void set_sprite_component(SpriteComponent* component) { m_sprite_component = component; }

  Game* game() const { return m_game; }
private:
  glm::vec2 m_position{ 0.0f, 0.0f };
  float m_scale{ 1.0f };
  float m_rotation{ 0.0f };
  
  State m_state{ State::ACTIVE };
  
  bool m_update_mv_matrix{ true };
  glm::mat4 m_mv_matrix{ };

  std::unique_ptr<SpriteComponent> m_sprite_component{ };
  std::unique_ptr<BoxComponent> m_box_component{ };

  Game* const m_game{ };
};

#endif