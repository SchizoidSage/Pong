/*
* Pong: A Pong Game with OpenGL, SDL2 and EnTT 
* Copyright (C) 2023  SchizoidSage
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "components/Ball.hpp"
#include "utility/Constants.hpp"
#include <effolkronium/random.hpp>
#include <glm/vec2.hpp>
#include <cmath>

Ball::Ball()
{
  set_random_direction();
}

void Ball::set_random_direction()
{
  using Random = effolkronium::random_static;
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