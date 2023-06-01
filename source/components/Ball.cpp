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
  float random{ };
  constexpr float margin{ 0.4f };
  switch (Random::get(1, 4)) {
    case 1:
      random = Random::get(margin, (Constants::PI / 2) - margin);
      break;
    case 2:
      random = Random::get((Constants::PI / 2) + margin, Constants::PI - margin);
      break;
    case 3:
      random = Random::get(Constants::PI + margin, ((Constants::PI / 2) * 3) - margin);
      break;
    case 4:
      random = Random::get(((Constants::PI / 2) * 3) + margin, (Constants::PI * 2) - margin);
      break;
  }

  m_direction = glm::vec2{ std::cos(random), std::sin(random) };
}

bool Ball::is_immune() const noexcept
{
  return m_immunity_ticks > 0;
}