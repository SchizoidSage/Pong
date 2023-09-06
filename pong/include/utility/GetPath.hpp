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

#ifndef GET_PATH_202309051810_HPP
#define GET_PATH_202309051810_HPP

#include <filesystem>

/*! \file       GetPath.hpp
*   \brief			Helper functions for finding folders and executables
*   \author			SchizoidSage
*   \date				2023
*		\copyright	GNU GPLv3+
*/

/*! Finds an absolute path, starting from current program's parent directory
*
*   \param suffix The relative path to search in relation to this program's parent directory
*   \return       The absolute path to the given relative path
*/
std::filesystem::path get_path(const char* suffix);

#endif