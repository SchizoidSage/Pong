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

#include "utility/GetPath.hpp"
#include "utility/whereami.h"
#include <stdexcept>
#include <cstdlib>
#include <filesystem>

std::filesystem::path get_path(const char* suffix)
{
  char* path{ nullptr };
  int length, dirname_length;

  length = wai_getExecutablePath(nullptr, 0, &dirname_length);
  if (length <= 0) {
    throw std::runtime_error{ "Whereami: Could not get executable path. This program may not support your platform." };
  }

  path = static_cast<char*>(std::malloc(static_cast<size_t>(length + 1)));
  if (!path) {
    throw std::runtime_error{ "Whereami: Could not allocate enough heap memory." };
  }

  wai_getExecutablePath(path, length, &dirname_length);
  path[dirname_length] = '\0';

  std::filesystem::path result{ path };
  std::free(path);
  
  result = result.remove_filename().parent_path();
  result /= suffix;

  return std::filesystem::weakly_canonical(result).make_preferred();
}