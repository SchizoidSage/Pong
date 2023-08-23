/*
* Pong: A Pong Game with OpenGL, SDL2 and EnTT 
* Copyright (C) 2023  SchizoidSage
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef GAME_202303021940_HPP
#define GAME_202303021940_HPP

#include "io/IOManager.hpp"
#include "io/Audio.hpp"
#include "systems/MoveSystem.hpp"
#include "systems/CollisionSystem.hpp"
#include "systems/RenderSystem.hpp"
#include <entt/entt.hpp>
#include <memory>

class Game final
{
public:
	Game();

	void run_loop();
private:
	void process_input();
	void update_game() const;
	void generate_output() const;

	bool m_is_running{ true }; 

	const std::unique_ptr<IOManager> m_io_manager{ std::make_unique<IOManager>() };
	const std::unique_ptr<const Audio> m_audio{ std::make_unique<const Audio>() };

	const std::unique_ptr<entt::registry> m_registry{ std::make_unique<entt::registry>() };
	const std::unique_ptr<entt::dispatcher> m_dispatcher{ std::make_unique<entt::dispatcher>() };

	const std::unique_ptr<const CollisionSystem> m_collision_system{ std::make_unique<const CollisionSystem>() };
	const std::unique_ptr<MoveSystem> m_move_system{ std::make_unique<MoveSystem>() };
	const std::unique_ptr<const RenderSystem> m_render_system{ std::make_unique<const RenderSystem>() };
};

#endif