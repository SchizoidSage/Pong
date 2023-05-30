#ifndef RENDER_SYSTEM_202305281749_HPP
#define RENDER_SYSTEM_202305281749_HPP

class RenderSystem final
{
public:
  RenderSystem();
  void render(entt::registry& registry);
private:
  std::array<std::unique_ptr<VertexArray>, 2> m_vertex_arrays{ };
  const std::unique_ptr<Shader> m_shader{ std::make_unique<Shader>("../glsl/vert_shader.glsl", "../glsl/frag_shader.glsl") };	
  const glm::mat4 m_view_matrix{ glm::translate(glm::mat4(1.0f), glm::vec3(-0.f, -0.f, -0.f)) };
	const glm::mat4 m_proj_matrix{ glm::ortho(Constants::LEFT_WALL, Constants::RIGHT_WALL, Constants::BOTTOM_WALL, Constants:: TOP_WALL, -1.f, 1.f) };
};

#endif