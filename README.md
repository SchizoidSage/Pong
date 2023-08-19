# Pong
A Simple Pong Game

This is a simple Pong game as a test project to showcase the use of various game-related libraries, including SDL2, OpenGL and EnTT.

To build and install from source: 
1. mkdir build && cd build
2. cmake ..
3. cmake --build .
4. sudo cmake --install .

This will create the "pong" executable and install it in /usr/local/games. Note: leaving out step 4 will cause errors at runtime, since the program excepts the necessary resource files to be installed in /usr/local.

This program has been built and tested on a Debian-based Linux environment. It has not been tested on Windows, Mac or RPM-based Linux environments, and may not work there.
