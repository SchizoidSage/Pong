#include "systems/RenderSystem.hpp"

RenderSystem::RenderSystem()
{
	m_shader->set_active();
	m_shader->set_uniform("proj_matrix", m_proj_matrix);

  const std::vector ball_vertices{ 
    -1.0f, 1.0f, 0.0f, // top left
    1.0f, 1.0f, 0.0f,  // top right
    1.0f, -1.0f, 0.0f, // bottom right
    -1.0f, -1.0f, 0.0f // bottom left
  };

  const std::vector<unsigned int> indices{ 
    0, 1, 2,
    2, 3, 0
  };

  m_vertex_arrays[static_cast<int>(EntityType::BALL)] = std::make_unique<VertexArray>(ball_vertices, indices);

  const std::vector paddle_vertices{ 
    -0.25f, 1.0f, 0.0f, // top left
    0.25f, 1.0f, 0.0f,  // top right
    0.25f, -1.0f, 0.0f, // bottom right
    -0.25f, -1.0f, 0.0f // bottom left
  };

  m_vertex_arrays[static_cast<int>(EntityType::PADDLE)] = std::make_unique<VertexArray>(paddle_vertices, indices);
}

void RenderSystem::render(entt::registry& registry)
{
  auto render_view{ registry.view<Sprite, Position>() };
  view.each([&](const auto& sprite, const auto& pos) {
    m_vertex_arrays[sprite.entity_type()]->set_active();
    m_shader->set_uniform("mv_matrix", 
      m_view_matrix() *
      glm::translate(glm::mat4(1.f), glm::vec3(pos.position().x, pos.position().y, 0.f)) *
      glm::rotate(glm::mat4(1.f), sprite.rotation(), glm::vec3(0.f, 0.f, 1.f)) *
      glm::scale(glm::mat4(1.f), glm::vec3(sprite.scale()))
    );
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
  });
}