MoveComponent::update(float delta_time)
{
  m_frame_speed = m_speed * delta_time;
  
  glm::vec2 position{ m_actor->position() };
  position += m_forward * m_frame_speed;
  m_actor->set_position(position);
}

MoveComponent::set_direction(float direction)
{
  m_direction = direction;
  m_forward = glm::vec2(std::cosf(direction), std::sinf(direction));
}

MoveComponent::set_speed(int speed)
{
  m_speed = speed;
  m_frame_speed = m_speed * delta_time;
}

void accept(UpdateComponentVisitor* visitor)
{
  visitor->visit_move_component(this);
}