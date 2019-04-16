#pragma once

#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "logger.h"

#define WINDOW_TITLE "Honey Badger Engine"
#define FPS_NUM_SAMPLES 10

namespace HoneyBadger {

class Window {

	private:
		Logger& log;

	private:

		bool gameloop;

		// Frame limiter

		Uint32 frameStart;

		int maxFPS;
		int frameDelay;
		int frameTicks;

		bool limitFrame;

		//FPS counter

		bool showFPS;

		float frameTimes[FPS_NUM_SAMPLES];

		float avgFPS;
		float countedFrames;
		float currentTicks;
		float prevTicks;
		float frameTimeAverage;

		int currentFrame;

		//Window and screen

		int width;
		int height;

		std::ostringstream dynamicWindowTitle;
		//char dynamicWindowTitle[80]; //C-Style

		SDL_WindowFlags windowSetting;
		SDL_RendererFlags renderSetting;

		SDL_Event event;

		//Sub-libraries
		int imageSetting;
		int audioSettings;

	private:
		SDL_Window* window;
		SDL_Surface* backbuffer;
		SDL_Renderer* renderer;

	private:

		void initFontLib();
		void initAudioLib();
		void initImageLib(int imgFlags);

		bool initSDL();
		bool initWindow();
		bool initRenderer();

		int initAll();

	public:
		Window(Logger& log);
		~Window();

		void popUpWindow(SDL_MessageBoxFlags windowType,char* header, char* message, SDL_Window* parentWindow);

		SDL_Window* getWindow();
		SDL_Surface* getBackBuffer();
		SDL_Renderer* getRenderer();

		void eventHandler();
		void update();
		void fpsCounter();
		void fpsLimiter();
		void forceQuit();

		void setMaxFPS(int maxFPS);
		int getMaxFPS();

		bool getIsFrameLimited();

		void setGameLoop(bool gameloop);
		bool getGameLoop();

		void setResolution(int width, int height);

		void setWidth(int width);
		int getWidth();

		void setHeight(int height);
		int getHeight();

		void setFullScreen(bool fullscreen);
		bool getFullScreen();

		void setRenderType(int renderType);
		int getRenderType();

		void setDisplayFPS(bool showFPS);
		bool getDisplayFPS();

		int getAverageFPS();

};

}