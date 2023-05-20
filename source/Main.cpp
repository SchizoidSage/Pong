#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <memory>

int main()
{
	std::unique_ptr<Game> game;
	try {
		game{ std::make_unique<Game>() };
	} catch (const std::runtime_error& err) {
		std::cout << err.what() << '\n';
		return EXIT_FAILURE;
	}

	game->run_loop();
	
	return EXIT_SUCCESS;
}
