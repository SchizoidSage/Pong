void BallCollisionVisitor::visit_move_component(MoveComponent* move_component)
{
  switch (m_wall) {
    case Wall::TOP_WALL:
    case Wall::BOTTOM_WALL:
      float direction{ move_component->direction() };
      move_component->set_direction(std::atan2f(std::sinf(direction) * -1, std::cosf(direction)));
      break;
    case Wall::LEFT_WALL:
    case Wall::RIGHT_WALL:
      float direction{ move_component->direction() };
      move_component->set_direction(std::atan2f(std::sinf(direction), std::cosf(direction) * -1));
      break;
    case Wall::LEFT_BOTTOM_CORNER:
    case Wall::RIGHT_BOTTOM_CORNER:
    case Wall::LEFT_TOP_CORNER:
    case Wall::RIGHT_TOP_CORNER:
      float direction{ move_component->direction() };
      move_component->set_direction(std::atan2f(std::sinf(direction) * -1, std::cosf(direction) * -1));
      break;
  }
}