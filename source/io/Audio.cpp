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

#include "io/Audio.hpp"
#include <AL/alure.h>
#include <stdexcept>
#include <string>

Audio::Audio()
{
  if(!alureInitDevice(nullptr, nullptr)) {
    throw std::runtime_error{ std::string{ "Failed to open OpenAL device: " } + alureGetErrorString() + '\n' };
  }
}

Audio::~Audio()
{
  alureShutdownDevice();
}

void Audio::update() const
{
  alureUpdate();
}