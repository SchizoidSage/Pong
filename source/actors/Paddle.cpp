#include "actors/Paddle.h"

Paddle::Paddle(Game* owner, float x, float y, Player player)
  : Actor{ owner },
    m_position{ x, y },
    m_player{ player }
{
  if (m_instances == 0 && !m_vertex_array) {
    std::array vertices{ 
      -0.25f, 1.0f, 0.0f, // top left
      0.25f, 1.0f, 0.0f,  // top right
      0.25f, -1.0f, 0.0f, // bottom right
      -0.25f, -1.0f, 0.0f // bottom left
    };

    std::array indices{ 
      0, 1, 2,
      2, 3, 0
    };

    m_vertex_array = new VertexArray{ vertices, indices };
  }

  ++m_instances;

  set_sprite_component(new SpriteComponent(this));
  set_input_component(new InputComponent(this));
  add_update_component(new MoveComponent(this));
  add_update_component(new ScoreComponent(this));
}

Paddle::~Paddle()
{
  --m_instances;
}

void process_input(const uint8_t* key_state)
{
  switch (m_player) {
    case Player::PLAYER_ONE:
      if (key_state[SDL_SCANCODE_Z] && key_state[SDL_SCANCODE_S]) {
        m_move_component->set_speed(0);
      } else if (key_state[SDL_SCANCODE_Z]) {
        m_move_component->set_direction(Constants::PI / 2);
        m_move_component->set_speed(15);
      } else if (key_state[SDL_SCANCODE_S]) {
        m_move_component->set_direction((Constants::PI / 2) * 3);
        m_move_component->set_speed(15);
      } else {
        m_move_component->set_speed(0);
      }
      break;
    case Player::PLAYER_TWO:
      if (key_state[SDL_SCANCODE_UP] && key_state[SDL_SCANCODE_DOWN]) {
        m_move_component->set_speed(0);
      } else if (key_state[SDL_SCANCODE_UP]) {
        m_move_component->set_direction(Constants::PI / 2);
        m_move_component->set_speed(15);
      } else if (key_state[SDL_SCANCODE_DOWN]) {
        m_move_component->set_direction((Constants::PI / 2) * 3);
        m_move_component->set_speed(15);
      } else {
        m_move_component->set_speed(0);
      }
      break;
  }
}

void Paddle::accept(ActorVisitor* visitor)
{
  visitor->visit_paddle(this);
}

void Paddle::component_update(float delta_time)
{
  m_move_component->update(delta_time);
}

void Paddle::actor_update()
{
  if ((m_position - m_scale) < Constants::BOTTOM_WALL) {
    auto position{ m_position };
    position.y = Constants::BOTTOM_WALL + m_scale;
    set_position(position);
  } else if ((m_position + m_scale) > Constants::TOP_WALL) {
    auto position{ m_position };
    position.y = Constants::TOP_WALL - m_scale;
    set_position(position);
  }
}