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

#ifndef IO_MANAGER_202303101704_HPP
#define IO_MANAGER_202303101704_HPP

#include <SDL.h>

class IOManager final
{
public:
  IOManager();
  ~IOManager();
  bool poll_event();
  void update_keyboard_state();
  void update_delta_time();
  void swap_window() const;

  SDL_Event event() const noexcept { return m_event; }
  const Uint8* keyboard_state() const noexcept { return m_state; }
  float delta_time() const noexcept { return m_delta_time; }

  IOManager(const IOManager&) = delete;
  IOManager& operator=(const IOManager&) = delete;
private:
	SDL_Window* m_window{ };
  SDL_GLContext m_context{ };
	Uint32 m_ticks_count{ 0 }; // Number of ticks since start of game
  float m_delta_time{ };
	SDL_Event m_event{ };
  const Uint8* m_state{ };
};

#endif