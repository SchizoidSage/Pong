#include "Game.h"
#include "actors/Ball.h"
#include "actors/Paddle.h"
#include "components/SpriteComponent.h"
#include "Constants.h"
#include <SDL.h>
#include <GL/glew.h>
#include <utility>
#include <algorithm>

Game::Game()
{
	m_shader->set_active();
	m_shader->set_uniform("proj_matrix", m_proj_matrix);

	add_actor(new Ball(this));
	add_actor(new Paddle(this, Constants::LEFT_WALL + 10, 0.0f));
	add_actor(new Paddle(this, Constants::RIGHT_WALL - 10, 0.0f));

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
		switch (m_io_manager->event().type) 
		{
			case SDL_QUIT:
				m_is_running = false;
				break;
		}
	}

	m_io_manager->update_keyboard_state();
	if (m_io_manager->keyboard_state()[SDL_SCANCODE_ESCAPE]) {
		m_is_running = false;
	}
	
	m_updating_actors = true;
	for (auto& actor : m_actors) {
		actor->process_input(m_io_manager->keyboard_state());
	}
	m_updating_actors = false;
}

void Game::update_game()
{
	m_io_manager->update_delta_time();
	
	m_updating_actors = true;
	for (auto& actor : m_actors) {
		actor->update(m_io_manager->delta_time());
	}
	m_collision_engine->test_collision();
	m_updating_actors = false;

	for (auto& pending : m_pending_actors) {
		m_actors.emplace_back(std::move(pending));
	}
	m_pending_actors.clear();

	m_actors.erase(std::remove_if(m_actors.begin(), m_actors.end(), [](const auto& actor){ return actor.state() == Actor::State::DEAD }), m_actors.end());
}

void Game::generate_output()
{
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto& actor : m_actors) {
		actor->draw();
	}

	m_io_manager->swap_window();
}

void Game::add_actor(Actor* actor)
{
	if (m_updating_actors) {
		m_pending_actors.emplace_back(actor);
	} else {
		m_actors.emplace_back(actor);
	}
}

void Game::increment_score(Player player)
{

}