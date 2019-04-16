#include <iostream>
#include <SDL.h>

#include "logger.h"
#include "Window.h"
#include "../game.h"
#include "utilities.h"

int main(int argc, char* args[]) {

	std::cout << "Initialising logger\n" << std::endl;

	HoneyBadger::Logger* log = new HoneyBadger::Logger();

	HoneyBadger::Utility::fileChecker(*log);

	HoneyBadger::Window* wnd = new HoneyBadger::Window(*log);
	HoneyBadger::Game* game = new HoneyBadger::Game(*wnd, *log);

	std::cout << "\nRunning game loop" << std::endl;
	log->writeLog("Running game loop");

	//Game loop
	while (wnd->getGameLoop()) {

		// ** Direct flow between game and window here ** //

		game->gameFlow();

		wnd->fpsCounter();
		wnd->update();
		wnd->eventHandler();

	}

	delete game;
	game = nullptr;

	delete wnd;
	wnd = nullptr;

	delete log;
	log = nullptr;

	std::cout << "\n\nDone! Press ENTER to exit" << std::endl;
	std::cin.get();

	return 0;

}

/*

					NOTE

	To run the 32bit version of the engine,
	replace the current DLLs with the 32bit
	DLLs from the x86 folder 

*/