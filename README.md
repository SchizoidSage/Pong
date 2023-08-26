# Pong
A Simple Pong Game

This is a simple Pong game as a test project to showcase the use of various game-related libraries, including SDL2, OpenGL and EnTT.

## Building

Before building, install the following dependencies from your package manager:

- On Debian-based distros (like Ubuntu): `sudo apt install cmake libgl1-mesa-dev libopenal-dev libsdl2-dev libglew-dev libglm-dev libalure-dev`
- On RPM-based distros (like Fedora): `sudo dnf install cmake mesa-libGL-devel openal-soft-devel SDL2-devel glew-devel glm-devel alure-devel`

To build and install from source: 
1. mkdir build && cd build
2. cmake ..
3. cmake --build .
4. sudo cmake --install .

This will create the "pong" executable and install it in /usr/local/games. 

Note: leaving out the installl step will cause errors at runtime, since the program expects the necessary resource files to be installed in /usr/local (or the directory specified by CMAKE_INSTALL_PREFIX if you specify it in step 2).

This program has been built and tested on a Debian-based Linux environment. It has not been tested on Windows or Mac, and may not work there.

## Controls

The player controls the left paddle using the S and W keys to go up or down respectively.

## Packaging

The project contains CPack generators for `.deb` and `.rpm` packages, and source generators for `.tar.gz` and `.tar.bz2` archives. To create these, use one of the following methods:

- After performing the build step above: `make package` or `make package_source`
- After performing the configure step above: `cpack --config CPackConfig.cmake` or `cpack --config CPackSourceConfig.cmake`

## License

Code released under [the GPLv3+ License](https://github.com/SchizoidSage/Pong/blob/main/COPYING).
