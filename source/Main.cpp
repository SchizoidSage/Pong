#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
	Game game;
	try {
		game{ Game() };
	} catch (const std::runtime_error& err) {
		std::cout << err.what() << '\n';
		return EXIT_FAILURE;
	}

	game.run_loop();
	
	return EXIT_SUCCESS;
}
