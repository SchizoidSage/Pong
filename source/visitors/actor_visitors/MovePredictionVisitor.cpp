void MovePredictionVisitor::visit_paddle(const Paddle* paddle)
{
  glm::vec2 position{ paddle->position() };
  float length{ m_move_component->frame_speed() + paddle->scale() };
  glm::vec2 direction{ m_move_component->forward() };
  glm::vec2 end_position{ position + (direction * length) };
  LineSegment line{ position, end_position };

  Wall wall{ collides_with_wall(line) };
  switch (wall) {
    case Wall::BOTTOM_WALL:
    case Wall::TOP_WALL:
      paddle->handle_collision(std::make_unique<PaddleCollisionVisitor>().get());
      break;
  }
}

void MovePredictionVisitor::visit_ball(const Ball* ball)
{
  glm::vec2 position{ paddle->position() };
  float length{ m_move_component->frame_speed() };
  float radius{ ball->scale() };
  glm::vec2 direction{ m_move_component->forward() };
  glm::vec2 end_position{ position + (direction * length) };
  Capsule capsule{ position, end_position, radius };

  Wall wall{ collides_with_wall(capsule) };
  switch (wall) {
    case Wall::BOTTOM_WALL:
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        if ((capsule.point_on_segment(i).y - radius) < Constants::BOTTOM_WALL) {
          ball->set_position(capsule.point_on_segment(i - 0.1f));
          break;
        }
      }
      ball->handle_collision(std::make_unique<BallCollisionVisitor>(wall).get())
      break;
    case Wall::TOP_WALL:
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        if ((capsule.point_on_segment(i).y + radius) > Constants::TOP_WALL) {
          ball->set_position(capsule.point_on_segment(i - 0.1f));
          break;
        }
      }
      ball->handle_collision(std::make_unique<BallCollisionVisitor>(wall).get())
      break;
    case Wall::LEFT_WALL:
    case Wall::LEFT_TOP_CORNER:
    case Wall::LEFT_BOTTOM_CORNER:
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        if ((capsule.point_on_segment(i).x - radius) < Constants::LEFT_WALL) {
          ball->set_position(capsule.point_on_segment(i - 0.1f));
          break;
        }
      }
      ball->handle_collision(std::make_unique<BallScoreVisitor>(wall).get())
      break;
    case Wall::RIGHT_WALL:
    case Wall::RIGHT_TOP_CORNER:
    case Wall::RIGHT_BOTTOM_CORNER:
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        if ((capsule.point_on_segment(i).x + radius) > Constants::RIGHT_WALL) {
          ball->set_position(capsule.point_on_segment(i - 0.1f));
          break;
        }
      }
      ball->handle_collision(std::make_unique<BallScoreVisitor>(wall).get())
      break;
  }

  // TODO paddle collision
}