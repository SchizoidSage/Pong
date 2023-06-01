# Pong
Simple Pong Game with OpenGL, SDL2 and EnTT.

This program requires that SDL2, OpenGL and GLEW are installed. Aditionally, the headers for [EnTT](https://github.com/skypjack/entt) and effolkronium's [Random library](https://github.com/effolkronium/random) need to be installed.

The program only works if you run it from a build directory directly below the root directory. This is because the GLSL files are loaded using relative paths (so they don't need to be installed elsewhere).
