#include "core/Game.hpp"
#include "components/All.hpp"
#include "events/KeyDown.hpp"
#include "events/KeyUp.hpp"
#include "systems/MoveSystem.hpp"
#include "utility/EntityType.hpp"
#include "utility/Constants.hpp"
#include <entt/entt.hpp>
#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <SDL.h>

Game::Game()
{
	const auto player_paddle{ m_registry->create() };
	const auto ai_paddle{ m_registry->create() };
	const auto ball{ m_registry->create() };

	m_registry->emplace<Sprite>(player_paddle, EntityType::PADDLE, 10.f);
	m_registry->emplace<Position>(player_paddle, Constants::LEFT_WALL + 15.f, 0.f);
	m_registry->emplace<Box>(player_paddle, glm::vec2{ -.5f, -1.f }, glm::vec2{ .5f, 1.f });
	m_registry->emplace<Player>(player_paddle);

	m_registry->emplace<Sprite>(ai_paddle, EntityType::PADDLE, 10.f);
	m_registry->emplace<Position>(ai_paddle, Constants::RIGHT_WALL - 15.f, 0.f);
	m_registry->emplace<Box>(ai_paddle, glm::vec2{ -.5f, -1.f }, glm::vec2{ .5f, 1.f });
	m_registry->emplace<Ai>(ai_paddle);

	m_registry->emplace<Sprite>(ball, EntityType::BALL, 5.f);
	m_registry->emplace<Position>(ball, 0.f, 0.f);
	m_registry->emplace<Box>(ball, glm::vec2{ -1.f, -1.f }, glm::vec2{ 1.f, 1.f });
	m_registry->emplace<Ball>(ball);

	m_dispatcher->sink<KeyDown>().connect<&MoveSystem::on_key_down>(m_move_system);
	m_dispatcher->sink<KeyUp>().connect<&MoveSystem::on_key_up>(m_move_system);

	m_io_manager->update_delta_time();
}

void Game::run_loop()
{
	while (m_is_running) {
		process_input();
		update_game();
		generate_output();
	}
}

void Game::process_input()
{
	while (m_io_manager->poll_event()) {
		const auto event{ m_io_manager->event() };
		switch (event.type) {
			case SDL_QUIT:
				m_is_running = false;
				break;
			case SDL_KEYDOWN:
				m_dispatcher->trigger(KeyDown{ event.key.keysym.sym });
				break;
			case SDL_KEYUP:
				m_dispatcher->trigger(KeyUp{ event.key.keysym.sym });
				break;
		}
	}
}

void Game::update_game() const
{
	m_io_manager->update_delta_time();
	const auto delta_time{ m_io_manager->delta_time() };
	
	m_move_system->update(delta_time, *(m_registry.get()));
	m_collision_system->update(delta_time, *(m_registry.get()));
}

void Game::generate_output() const
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f, 0.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_render_system->render(*(m_registry.get()));

	m_io_manager->swap_window();
}