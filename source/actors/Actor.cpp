#include "actors/Actor.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>


void Actor::update(float delta_time)
{
  if (m_state == State::ACTIVE) {
    update_mv_matrix();
    component_update(delta_time);
    actor_update();
    update_mv_matrix();
  }
}

void Actor::draw()
{
  if (m_state == State::ACTIVE && m_sprite_component) {
    m_sprite_component->draw();
  }
}

void Actor::set_position(const glm::vec2& position)
{
  m_position = position;
  m_update_mv_matrix = true;
}

void Actor::set_scale(float scale)
{
  m_scale = scale;
  m_update_mv_matrix = true;
}

void Actor::set_rotation(float rotation)
{
  m_rotation = rotation;
  m_update_mv_matrix = true;
}

void Actor::update_mv_matrix()
{
  if (m_update_mv_matrix) {
    m_update_mv_matrix = false;
    m_mv_matrix = 
      m_game->view_matrix() *
      glm::translate(glm::mat4(1.0f), glm::vec3(m_position.x, m_position.y, 0.0f)) *
      glm::rotate(glm::mat4(1.0f), m_rotation, glm::vec3(0.0f, 0.0f, 1.0f)) *
      glm::scale(glm::mat4(1.0f), glm::vec3(m_scale));
    m_box_component->on_update_mv_matrix();
  }
}