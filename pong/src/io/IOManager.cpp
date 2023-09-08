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

#include "utility/Constants.hpp"
#include "io/IOManager.hpp"
#include <GL/glew.h>
#include <SDL.h>
#include <stdexcept>
#include <string>
#include <iostream>

IOManager::IOManager()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error{ std::string{ "Unable to initialize SDL! SDL Error: " } + SDL_GetError() };
	}
	
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

	m_window = SDL_CreateWindow(
		"Pong",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Constants::SCREEN_WIDTH,
		Constants::SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	if (!m_window) {
		throw std::runtime_error{ std::string{ "Window could not be created! SDL Error: " } + SDL_GetError() };
	}

  m_context = SDL_GL_CreateContext(m_window);

  if (!m_context) {
		throw std::runtime_error{ std::string{ "OpenGL context could not be created! SDL Error: " } + SDL_GetError() };
  }

  if (auto glewError{ glewInit() }; glewError != GLEW_OK) {
		std::cerr << glewGetErrorString(glewError) + '\n';
		throw std::runtime_error{ "GLEW failed to initialize!\n" };
  }

  if (SDL_GL_SetSwapInterval(1) < 0) {
		throw std::runtime_error{ std::string{ "SDL failed to set VSync! SDL Error: " } + SDL_GetError() };
  }
}

IOManager::~IOManager()
{
  SDL_GL_DeleteContext(m_context);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

bool IOManager::poll_event()
{
	if (SDL_PollEvent(&m_event)) {
		return true;
	}
	return false;
}

void IOManager::update_keyboard_state()
{
	m_state = SDL_GetKeyboardState(NULL);
}

void IOManager::update_delta_time()
{
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticks_count + 16))
		;

	// Delta time is the difference in ticks from last frame
	// (converted to seconds)
	m_delta_time = (SDL_GetTicks() - m_ticks_count) / 1000.f;
	
	// Clamp maximum delta time value
	if (m_delta_time > .05f) {
		m_delta_time = .05f;
	}

	// Update tick counts (for next frame)
	m_ticks_count = SDL_GetTicks();
}

void IOManager::swap_window() const
{
	SDL_GL_SwapWindow(m_window);
}