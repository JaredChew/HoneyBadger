#include "game.h"

HoneyBadger::Game::Game(Window& wnd, Logger& log) : wnd(wnd), log(log) {

	// ** Initialise everything here ** //

	std::cout << "\nInitialising essential objects" << std::endl;
	log.writeLog("Initialising essential objects");

	//Initialise essential obbjects
	kbd = new Keyboard();
	std::cout << "Keyboard initialised" << std::endl;
	log.writeLog("Keyboard initialised");

	mse = new Mouse();
	std::cout << "Mouse initialised" << std::endl;
	log.writeLog("Mouse initialised");

	rseLoad = new ResourcesLoader(wnd);
	std::cout << "ResourcesLoader initialised" << std::endl;
	log.writeLog("ResourcesLoader initialised");

	font = new Font(wnd);
	font->setFont(rseLoad->loadFont("asset/font/Consolas.ttf", 100));
	std::cout << "Font Object initialised" << std::endl;
	log.writeLog("Font Object initialised");

}

HoneyBadger::Game::~Game() {

	// ** Destroy all objects' data ** //

	std::cout << "\nDestroying essential objects" << std::endl;
	log.writeLog("Destroying essential objects");

	delete rseLoad;
	rseLoad = nullptr;
	std::cout << "ResourcesLoader destroyed" << std::endl;
	log.writeLog("ResourcesLoader destroyed");

	delete font;
	font = nullptr;
	std::cout << "Font object destroyed" << std::endl;
	log.writeLog("Font object destroyed");

}

void HoneyBadger::Game::displayFPScounter() {

	// ** Displays average fps ** //

	if (wnd.getDisplayFPS()) {
		
		//Display in-game top left

		fpsText << "FPS: " << wnd.getAverageFPS();

		font->displayFont(fpsText.str(), 10, 10, 50, 15, 0, 0, 0);

		fpsText.str("");
		fpsText.clear();

	}

}

void HoneyBadger::Game::gameFlow() {

	// ** Insert game's functions code here ** //

	test = rseLoad->loadTextureImage("asset/graphic/GudDawg.png");
	SDL_QueryTexture(test, NULL, NULL, &testRect.w, &testRect.h); 
	
	soundTest = rseLoad->loadSound("asset/sound/buttonNavigate.wav");
	musicTest = rseLoad->loadMusic("asset/music/menuTest.wav");
	
	SDL_RenderCopy(wnd.getRenderer(), test, NULL, &testRect);

	SDL_DestroyTexture(test);
	test = nullptr;
	
	Mix_FreeChunk(soundTest);
	soundTest = nullptr;

	Mix_FreeMusic(musicTest);
	musicTest = nullptr;
	
	if (kbd->isPressed(KEYBOARD_A)) {
		wnd.setGameLoop(false);
	}

	kbd->update();

	displayFPScounter();
	
}