# Pong
A Simple Pong Game

This is a simple Pong game as a test project to showcase the use of various game-related libraries, including [SDL2](https://www.libsdl.org/), [OpenGL](https://www.khronos.org/opengl) and [EnTT](https://github.com/skypjack/entt). 
The code is structured according to the [ECS pattern](https://en.wikipedia.org/wiki/Entity_component_system), using the EnTT registry for storing entities and components. SDL2 is used for window management, keyboard input and video output. OpenGL provides the graphics. Audio is provided through [OpenAL](https://github.com/kcat/openal-soft).

![Screenshot_20230826_171912](https://github.com/SchizoidSage/Pong/assets/112087231/0dccc791-38a1-4495-a129-de4152f3ce71)

## Building

Before building, install the following dependencies from your package manager:

- On Debian-based distros (like Ubuntu): `sudo apt install cmake libgl1-mesa-dev libopenal-dev libsdl2-dev libglew-dev libglm-dev libalure-dev`
- On RPM-based distros (like Fedora): `sudo dnf install cmake mesa-libGL-devel openal-soft-devel SDL2-devel glew-devel glm-devel alure-devel`

To build and install from source: 
1. `mkdir build && cd build`
2. `cmake ..`
3. `cmake --build .`
4. `sudo cmake --install .`

This will create the "pong" executable and install it in /usr/local/games (unless you specify another directory with `-DCMAKE_INSTALL_PREFIX` in step 2, see [here](https://cmake.org/cmake/help/latest/manual/cmake.1.html#run-a-script)).

**WARNING**: This program has been built and tested on a Debian-based Linux environment. It has not been tested on Windows or Mac, and may not work there.

## Controls

The player controls the left paddle using the S and W keys to go up or down respectively.

## Testing

To run the tests, use the CMake option `PERFORM_TESTS`: `cmake .. -DPERFORM_TESTS=ON`.

## Documentation

To generate and install Doxygen documentation, use the CMake option `GENERATE_DOCS`: `cmake .. -DGENERATE_DOCS=ON`.

## Packaging

The project contains CPack generators for `.deb` and `.rpm` packages, and source generators for `.tar.gz` and `.tar.bz2` archives. To create these, use one of the following methods:

- After performing the build step above (`cmake --build .`), do the following: `make package` to generate the binary packages; or `make package_source` to generate the source packages.
- After performing the configure step above (`cmake ..`), do the following: `cpack --config CPackConfig.cmake` or `cpack --config CPackSourceConfig.cmake`

## License

Code released under [the GPLv3+ License](https://github.com/SchizoidSage/Pong/blob/main/COPYING).
