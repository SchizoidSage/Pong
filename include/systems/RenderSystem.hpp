#ifndef RENDER_SYSTEM_202305281749_HPP
#define RENDER_SYSTEM_202305281749_HPP

#include "rendering/VertexArray.hpp"
#include "rendering/Shader.hpp"
#include "utility/Constants.hpp"
#include <entt/entt.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp>
#include <array>
#include <memory>

class RenderSystem final
{
public:
  RenderSystem();
  void render(const entt::registry& registry) const;
private:
  std::array<std::unique_ptr<const VertexArray>, 2> m_vertex_arrays{ };
  const std::unique_ptr<const Shader> m_shader{ std::make_unique<const Shader>("../glsl/vert_shader.glsl", "../glsl/frag_shader.glsl") };	
  const glm::mat4 m_view_matrix{ glm::translate(glm::mat4(1.f), glm::vec3(-0.f, -0.f, -0.f)) };
	const glm::mat4 m_proj_matrix{ glm::ortho(Constants::LEFT_WALL, Constants::RIGHT_WALL, Constants::BOTTOM_WALL, Constants:: TOP_WALL, -1.f, 1.f) };
};

#endif