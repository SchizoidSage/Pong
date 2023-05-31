#ifndef COLLISION_SYSTEM_202305291300_HPP
#define COLLISION_SYSTEM_202305291300_HPP

#include <entt/entt.hpp>

class CollisionSystem
{
public:
  void update(float delta_time, entt::registry& registry) const;
};

#endif