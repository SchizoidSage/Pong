#include "components/Ball.hpp"
#include "utility/Constants.hpp"
#include <effolkronium/random.hpp>
#include <glm/vec2.hpp>
#include <cmath>
using Random = effolkronium::random_static;

Ball::Ball()
{
  set_random_direction();
}

void Ball::set_random_direction()
{
  float random{ Random::get(0.f, 2 * Constants::PI) };
  constexpr float upward{ Constants::PI / 2 };
  constexpr float downward{ (Constants::PI / 2) * 3 };
  constexpr float margin{ 0.5f };

  // If random is too vertical, generate new direction
  while (
    (random < (upward + margin) && random > (upward - margin)) ||
    (random < (downward + margin) && random > (downward - margin))
  ) {
    random = Random::get(0.f, 2 * Constants::PI);
  }

  m_direction = glm::vec2{ std::cos(random), std::sin(random) };
}