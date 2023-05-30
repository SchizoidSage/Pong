#ifndef GAME_202303021940_HPP
#define GAME_202303021940_HPP

#include "rendering/Shader.h"
#include "Constants.h"
#include "IOManager.h"
#include "Player.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <entt/entt.hpp>
#include <memory>
#include <vector>

class Game final
{
public:
	Game();

	void run_loop();	
private:
	void process_input();
	void update_game();
	void generate_output() const;

	bool m_is_running{ true }; 

	const std::unique_ptr<IOManager> m_io_manager{ std::make_unique<IOManager>() };

	const std::unique_ptr<entt::registry> m_registry{ std::make_unique<entt::registry>() };
	const std::unique_ptr<entt::dispatcher> m_dispatcher{ std::make_unique<entt::dispatcher>() };

	const std::unique_ptr<CollisionSystem> m_collision_system{ std::make_unique<CollisionSystem>() };
	const std::unique_ptr<MoveSystem> m_move_system{ std::make_unique<MoveSystem>() };
	const std::unique_ptr<RenderSystem> m_render_system{ std::make_unique<RenderSystem>() };
};

#endif