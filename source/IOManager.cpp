#include "Constants.h"
#include "IOManager.h"
#include <GL/glew.h>
#include <SDL.h>
#include <stdexcept>

IOManager::IOManager()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error("Unable to initialize SDL! SDL Error: " + SDL_GetError() + '\n');
	}
	
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

	m_window = SDL_CreateWindow(
		"Paddleball",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Constants::SCREEN_WIDTH,
		Constants::SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	if (!m_window) {
		throw std::runtime_error("Window could not be created! SDL Error: " + SDL_GetError() + '\n');
	}

  m_context = SDL_GL_CreateContext(m_window);

  if (!m_context) {
		throw std::runtime_error("OpenGL context could not be created! SDL Error: " + SDL_GetError() + '\n');
  }

  if (auto glewError{ glewInit() }; glewError != GLEW_OK) {
		throw std::runtime_error("GLEW failed to initialize! GLEW Error: " + glewGetErrorString(glewError) + '\n');
  }

  if (SDL_GL_SetSwapInterval(1) < 0) {
		throw std::runtime_error("SDL failed to set VSync! SDL Error: " + SDL_GetError() + '\n');
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
	m_delta_time = (SDL_GetTicks() - m_ticks_count) / 1000.0f;
	
	// Clamp maximum delta time value
	if (m_delta_time > 0.05f) {
		m_delta_time = 0.05f;
	}

	// Update tick counts (for next frame)
	m_ticks_count = SDL_GetTicks();
}

void IOManager::swap_window() const
{
	SDL_GL_SwapWindow(m_window);
}