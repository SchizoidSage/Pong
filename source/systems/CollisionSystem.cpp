#include "systems/CollisionSystem.hpp"
#include "collision/utility/Intersect.hpp"
#include "collision/utility/Side.hpp"
#include "collision/shapes/LineSegment.hpp"
#include "components/Ball.hpp"
#include "components/Position.hpp"
#include "components/Sprite.hpp"
#include "components/Box.hpp"
#include <entt/entt.hpp>

void CollisionSystem::update(float delta_time, entt::registry& registry) const
{
  const auto ball_view{ registry.view<Ball, Position, const Sprite, Box>() };
  const auto paddle_view{ registry.view<const Box>(entt::exclude<Ball>) };

  ball_view.each([&](auto& ball, auto& ball_pos, const auto& ball_sprite, auto& ball_box) {
    if (ball.is_immune()) {
      ball.decrement_immunity();
    } else {
      paddle_view.each([&](const auto& paddle_box) {
        if (intersect(paddle_box.world_box(), ball_box.world_box())) {
          const LineSegment line{ ball_pos.position() + (-ball.direction() * (ball.speed() * delta_time)), ball_pos.position() };
          float t{ };
          Side side{ };
          intersect(line, paddle_box.world_box(), t, side);
          switch (side) {
            case Side::MIN_X:
            case Side::MAX_X:
              ball.set_direction({ -ball.direction().x, ball.direction().y });
              break;
            case Side::MIN_Y:
            case Side::MAX_Y:
              ball.set_direction({ ball.direction().x, -ball.direction().y }); 
              break;
          }
          ball_pos.set_position(line.point_on_segment(t) + (ball.direction() * (ball.speed() * delta_time * (1 - t))));
          ball_box.set_world_box(ball_pos.position(), ball_sprite.scale());
          ball.set_immune();
        }
      });
    }
  });
}