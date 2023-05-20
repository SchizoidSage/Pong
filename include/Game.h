#ifndef GAME_202303021940_H
#define GAME_202303021940_H

#include "actors/Actor.h"
#include "collision/CollisionEngine.h"
#include "rendering/Shader.h"
#include "Constants.h"
#include "Player.h"
#include "IOManager.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <memory>
#include <vector>

class Game final
{
public:
	Game();

	void run_loop();

	glm::mat4 view_matrix() const { return m_view_matrix; }
	Shader* shader() const { return m_shader.get(); }
	CollisionEngine* collision_engine() const { return m_collision_engine.get(); }

	void game_stopped() { m_is_running = false; }
	void increment_score(Player player);
private:
	void process_input();
	void update_game();
	void generate_output() const;

	void add_actor(Actor& actor);

	const auto m_io_manager{ std::make_unique<IOManager>() };
	bool m_is_running{ true };
	bool m_updating_actors{ false };

	int score_player_one{ 0 };
	int score_player_two{ 0 };

	std::vector<std::unique_ptr<Actor>> m_actors{ };
	std::vector<std::unique_ptr<Actor>> m_pending_actors{ };

	const auto m_shader{ std::make_unique<Shader>("../glsl/vert_shader.glsl", "../glsl/frag_shader.glsl") };
	const auto m_collision_engine{ std::make_unique<CollisionEngine>() };

	const float m_camera_x{ 0.0f };
  const float m_camera_y{ 0.0f };
  const float m_camera_z{ 0.0f };

  const glm::mat4 m_view_matrix{ glm::translate(glm::mat4(1.0f), glm::vec3(-m_camera_x, -m_camera_y, -m_camera_z)) };
	const glm::mat4 m_proj_matrix{ glm::ortho(Constants::LEFT_WALL, Constants::RIGHT_WALL, Constants::BOTTOM_WALL, Constants:: TOP_WALL, -1.0f, 1.0f) };
};

#endif