#include "systems/CollisionSystem.hpp"

void CollisionSystem::update(float delta_time, CollisionHolder& holder)
{
  auto ball_view{ registry.view<Ball, Position, Sprite, Box>() };
  auto paddle_view{ registry.view<Position, Sprite, Box>(entt::exclude<Ball>) };

  paddle_view.each([&](auto& paddle_pos, auto& paddle_sprite, auto& paddle_box){
    ball_view.each([&](auto& ball, auto& ball_pos, auto& ball_sprite, auto& ball_box) {
      if (intersect(paddle_box.world_box(), ball_box.world_box())) {
        const LineSegment line{ ball_pos.position() + (-ball.direction() * (ball.speed() * delta_time)), ball_pos.position() };
        float t{ };
        Side side{ };
        intersect(line, paddle_box, t, side);
        switch (side) {
          case Side::MIN_X:
          case Side::MAX_X:
            ball.set_direction(std::atan2(ball.direction().y, -ball.direction().x));
            break;
          case Side::MIN_Y:
          case Side::MAX_Y:
            ball.set_direction(std::atan2(-ball.direction().y, ball.direction().x));
            break;
        }
        ball_pos.set_position(line.point_on_segment(t) + (ball.direction() * ball.speed() * delta_time * (1 - t)));
      }
    });
  });
}