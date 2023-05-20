#include "collision/CollisionEngine.h"
#include "components/BoxComponent.h"
#include <algorithm>

void CollisionEngine::add_box(BoxComponent* box)
{
  m_box_components.emplace_back(box);
}

void CollisionEngine::remove_box(BoxComponent* box)
{
	auto iter{ std::find(m_box_components.begin(), m_box_components.end(), box) };
	if (iter != m_box_components.end()) {
		std::iter_swap(iter, m_box_components.end() - 1);
		m_box_components.pop_back();
	}
}

void CollisionEngine::test_collision()
{
	for (size_t i{ 0 }; i < m_box_components.size(); i++) {
		for (size_t j{ i + 1 }; j < m_box_components.size(); j++) {
			BoxComponent* a{ m_box_components[i] };
			BoxComponent* b{ m_box_components[j] };
			if (intersect(a->world_shape(), b->world_shape())) {
				a->actor()->handle_collision(b->actor());
				b->actor()->handle_collision(a->actor());
			}
		}
	}
}