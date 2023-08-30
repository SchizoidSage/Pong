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

//! \file IOManager.hpp

/*! \brief			The I/O manager
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*   \sa         Game
* 
*   The I/O Manager is responsible for keyboard input and graphics output
*/
class IOManager final
{
public:
  IOManager();
  ~IOManager();

  /*! Checks for keyboard events
  *
  *   \return Returns true if an event occurred since last check
  */
  bool poll_event();

  /*! Updates keyboard state
  *
  *   The keyboard state is an array showing which keys are currently being pressed.
  */
  void update_keyboard_state();

  /*! Updates delta time
  *
  *   The delta time is the time that has passed since the last check, expressed in seconds.
  */
  void update_delta_time();

  /*! Updates computer window content
  *
  *   When the graphics are rendered at the end of the main game loop, 
  *   they are added to a buffer screen in the background. This function 
  *   switches the buffer screen to the foreground.
  */
  void swap_window() const;

  SDL_Event event() const noexcept { return m_event; }              //!< Getter for the current keyboard event
  const Uint8* keyboard_state() const noexcept { return m_state; }  //!< Getter for the keyboard state
  float delta_time() const noexcept { return m_delta_time; }        //!< Getter for delta time

  IOManager(const IOManager&) = delete;
  IOManager& operator=(const IOManager&) = delete;
private:
	SDL_Window* m_window{ };
  SDL_GLContext m_context{ };
	Uint32 m_ticks_count{ 0 };
  float m_delta_time{ };
	SDL_Event m_event{ };
  const Uint8* m_state{ };
};

#endif