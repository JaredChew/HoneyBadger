#pragma once

#include <SDL.h>
#include <iostream>
#include <string>
#include <sstream>

#include "engine/logger.h"
#include "engine/window.h"
#include "engine/keyboard.h"
#include "engine/mouse.h"
#include "engine/resourcesLoader.h"
#include "engine/font.h"
#include "engine/audioController.h"
#include "engine/physics.h"

#define TOTAL_FILES 1

namespace HoneyBadger {

	class Game {

	private:

		Logger& log;
		Window& wnd;
		Keyboard* kbd;
		Mouse* mse;
		ResourcesLoader* rseLoad;
		//AudioController* audio;
		//Physics* physics;

	private:

		//In-game FPS counter

		Font* font;

		float avgFPS;
		int countedFrames;
		std::stringstream fpsText;

		//To test
		SDL_Texture *test;
		SDL_Rect testRect;

		Mix_Chunk *soundTest;
		Mix_Music *musicTest;

	private:

		void displayFPScounter();


	public:

		Game(Window& wnd, Logger& log);
		~Game();

		void gameFlow();

	};

}