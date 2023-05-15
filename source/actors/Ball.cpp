#include "actors/Ball.h"

Ball::Ball(Game* owner)
  : Actor(owner),
    m_move_component{ std::make_unique<MoveComponent>(this) }
{
  if (m_instances == 0 && !m_vertex_array) {
    std::array vertices{ 
      -1.0f, 1.0f, 0.0f, // top left
      1.0f, 1.0f, 0.0f,  // top right
      1.0f, -1.0f, 0.0f, // bottom right
      -1.0f, -1.0f, 0.0f // bottom left
    };

    std::array indices{ 
      0, 1, 2,
      2, 3, 0
    };

    m_vertex_array = new VertexArray{ vertices, indices };
  }

  ++m_instances;

  set_sprite_component(new SpriteComponent(this));
}

Ball::~Ball()
{
  --m_instances;
}

void Ball::accept(ActorVisitor* visitor)
{
  visitor->visit_ball(this);
}

void Ball::component_update(float delta_time)
{
  m_move_component->update(delta_time);
}

void Ball::actor_update()
{
  if (m_position.x - m_scale < Constants::LEFT_WALL) {
    kill();
    m_game->increment_score(Player::PLAYER_ONE);
    m_game->add_actor(new Ball(m_game));
  } else if (m_position.x + m_scale > Constants::RIGHT_WALL) {
    kill();
    m_game->increment_score(Player::PLAYER_TWO);
    m_game->add_actor(new Ball(m_game));
  } else if (m_position.y - m_scale < Constants::BOTTOM_WALL) {
    float direction{ m_move_component->direction() };
    m_move_component->set_direction(std::atan2f(std::sinf(direction) * -1, std::cosf(direction)));
    auto position{ m_position };
    position.y = Constants::BOTTOM_WALL + m_scale;
    set_position(position);
  } else if (m_position.y + m_scale > Constants::TOP_WALL) {
    float direction{ m_move_component->direction() };
    m_move_component->set_direction(std::atan2f(std::sinf(direction) * -1, std::cosf(direction)));
    auto position{ m_position };
    position.y = Constants::TOP_WALL - m_scale;
    set_position(position);
  }
}

void Ball::handle_collision(Actor* collider)
{
  std::unique_ptr<LineSegment> trajectory{ m_position - (m_move_component->forward() * m_move_component->frame_speed()), m_position + (m_scale * m_move_component->forward()) };
  float t{ };
  Plane plane{ };
  intersect(trajectory, box, t, plane);
  switch (plane) {
    case MIN_X:
      if (m_move_component->forward().x > 0) {
        glm::vec2 collision_point{ trajectory->point_on_segment(t) - (forward * m_scale) };
        m_move_component->set_direction(std::atan2f(std::sinf(direction), std::cosf(direction) * -1));
        set_position(collision_point + (m_forward * m_frame_speed * (1 - t)));
      } else {
        glm::vec2 position{ m_position };
        position.x = collider->box_component()->world_shape()->min().x - m_scale;
        set_position(position);
      }
    case MAX_X:
      if (m_move_component->forward().x < 0) {
        glm::vec2 collision_point{ trajectory->point_on_segment(t) - (forward * m_scale) };
        m_move_component->set_direction(std::atan2f(std::sinf(direction), std::cosf(direction) * -1));
        set_position(collision_point + (m_forward * m_frame_speed * (1 - t)));
      } else {
        glm::vec2 position{ m_position };
        position.x = collider->box_component()->world_shape()->max().x + m_scale;
        set_position(position);
      }
    case MIN_Y:
      if (m_move_component->forward().y > 0) {
        glm::vec2 collision_point{ trajectory->point_on_segment(t) - (forward * m_scale) };
        m_move_component->set_direction(std::atan2f(std::sinf(direction) * -1, std::cosf(direction)));
        set_position(m_position + (m_forward * m_frame_speed * (1 - t)));
      } else {
        glm::vec2 position{ m_position };
        position.y = collider->box_component()->world_shape()->min().y - m_scale;
        set_position(position);
      }
    case MAX_Y:
      if (m_move_component->forward().y < 0) {
        glm::vec2 collision_point{ trajectory->point_on_segment(t) - (forward * m_scale) };
        m_move_component->set_direction(std::atan2f(std::sinf(direction) * -1, std::cosf(direction)));
        set_position(m_position + (m_forward * m_frame_speed * (1 - t)));
      } else {
        glm::vec2 position{ m_position };
        position.y = collider->box_component()->world_shape()->max().y + m_scale;
        set_position(position);
      }
  }
}