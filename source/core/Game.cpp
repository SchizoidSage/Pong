#include "Game.h"
#include "actors/Actor.h"
#include "actors/Ball.h"
#include "actors/Paddle.h"
#include "components/SpriteComponent.h"
#include "Constants.h"
#include "Player.h"
#include <SDL.h>
#include <GL/glew.h>
#include <utility>
#include <algorithm>

Game::Game()
{
	const auto player_paddle{ m_registry->create() };
	const auto ai_paddle{ m_registry->create() };
	const auto ball{ m_registry->create() };

	m_registry->emplace<Sprite>(player_paddle, EntityType::PADDLE, 5.f);
	m_registry->emplace<Position>(player_paddle, Constants::LEFT_WALL + 10.f, 0.f);
	m_registry->emplace<Player>(player_paddle);

	m_registry->emplace<Sprite>(ai_paddle, 5.f);
	m_registry->emplace<Position>(ai_paddle, Constants::RIGHT_WALL - 10.f, 0.f);
	m_registry->emplace<AI>(ai_paddle);

	m_registry->emplace<Sprite>(ball, 2.5f);
	m_registry->emplace<Position>(ball, 0.f, 0.f);
	m_registry->emplace<Ball>(ball);

	m_dispatcher->sink<KeyDown>().connect<&MoveSystem::on_key_down>(m_move_system);
	m_dispatcher->sink<KeyUp>().connect<&MoveSystem::on_key_up>(m_move_system);

	m_collision_holder.player = player_paddle;
	m_collision_holder.ai = ai_paddle;
	m_collision_holder.ball = ball;
	m_collision_holder.registry = m_registry.get();
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
				m_dispatcher->trigger<KeyDown>(event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				m_dispatcher->trigger<KeyUp>(event.key.keysym.sym);
				break;
		}
	}
}

void Game::update_game()
{
	m_io_manager->update_delta_time();
	const auto delta_time{ m_io_manager->delta_time() };
	
	m_move_system->update(delta_time, m_registry);
	m_collision_system->update(delta_time, m_collision_holder);
}

void Game::generate_output() const
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f, 0.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_render_system->render(m_registry);

	m_io_manager->swap_window();
}