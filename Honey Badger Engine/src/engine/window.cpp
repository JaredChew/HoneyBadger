#include "window.h"

HoneyBadger::Window::Window(Logger& log) : log(log) {

	// ** Initialise variables and objects here ** //

	gameloop = true;

	//Frame limiter
	
	frameStart = 0;

	maxFPS = 60;
	frameDelay = 1000 / maxFPS;
	frameTicks = 0;

	limitFrame = true;

	//FPS Counter
	showFPS = true;

	avgFPS = 0.0f;
	countedFrames = 0.0f;
	currentTicks = 0.0f;
	prevTicks = 0.0f;
	frameTimeAverage = 0.0f;

	currentFrame = 0;

	//Window and screen

	width = 1280;
	height = 720;

	windowSetting = SDL_WINDOW_SHOWN;
	renderSetting = SDL_RENDERER_ACCELERATED;

	//Sub-libraries

	imageSetting = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF;
	audioSettings = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG;

	// #################### //

	if (initAll() == -1) {
		gameloop = false;
	}

}

HoneyBadger::Window::~Window() {

	// ** Destroy window object here ** //

	std::cout << "\nClosing sub-libraries" << std::endl;
	log.writeLog("Closing sub-libraries");

	TTF_Quit();
	std::cout << "Font library closed" << std::endl;
	log.writeLog("Font library closed");

	Mix_CloseAudio();
	std::cout << "Audio library closed" << std::endl;
	log.writeLog("Audio library closed");

	IMG_Quit();
	std::cout << "Image library closed" << std::endl;
	log.writeLog("Image library closed");

	std::cout << "Closing SDL libraries" << std::endl;
	log.writeLog("Closing SDL libraries");
	SDL_Quit();

	std::cout << "Destroying renderer" << std::endl;
	log.writeLog("Destroying renderer");
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	std::cout << "Destroying surface" << std::endl;
	log.writeLog("Destroying surface");
	SDL_FreeSurface(backbuffer);
	backbuffer = nullptr;

	std::cout << "Destroying window" << std::endl;
	log.writeLog("Destroying window");
	SDL_DestroyWindow(window);
	window = nullptr;

}

bool HoneyBadger::Window::initSDL() {

	//Initialise SDL drivers
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Failed to intialise SDL drivers" << std::endl;
		log.errorLog("Failed to intialise SDL drivers");
		return false;
	}

	std::cout << "SDL drivers initialised" << std::endl;
	log.writeLog("SDL drivers initialised");

	return true;

}

bool HoneyBadger::Window::initWindow() {

	//Create main window
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowSetting);

	if (window == nullptr) {
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		log.errorLog("Failed to intialise Window");
		return false;
	}

	SDL_SetWindowResizable(window, SDL_TRUE);

	//Apply window into backbuffer/surface
	backbuffer = SDL_GetWindowSurface(window);
	std::cout << "Window initialised" << std::endl;
	log.writeLog("Window initialised");

	return true;

}

bool HoneyBadger::Window::initRenderer() {

	//Initialise renderer
	renderer = SDL_CreateRenderer(window, -1, renderSetting);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	if (renderer == nullptr) {
		std::cerr << "Failed to intialise renderer" << std::endl;
		log.errorLog("Failed to intialise renderer");
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	std::cout << "Renderer initialised" << std::endl;
	log.writeLog("Renderer initialised");

	return true;

}

void HoneyBadger::Window::initFontLib() {

	if (!TTF_WasInit() && TTF_Init() == -1) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Font library failed to initialise", NULL);
		std::cerr << "Failed to initialise font library: " << TTF_GetError() << std::endl;
		log.writeLog("Failed to initialise font library");

		//forceQuit();
		return;

	}

	std::cout << "Font library initialised" << std::endl;
	log.writeLog("Font library initialised");

}

void HoneyBadger::Window::initAudioLib() {

	if ((Mix_Init(audioSettings) & audioSettings) != audioSettings) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Audio library failed to initialise", NULL);
		std::cerr << "Failed to initialise Audio library: " << Mix_GetError() << std::endl;
		log.writeLog("Failed to initialise Audio library");

		//forceQuit();
		return;

	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Mixer failed to initialise", NULL);
		std::cerr << "Failed to initialise Audio library's Mixer" << std::endl;
		log.writeLog("Failed to initialise Audio library's Mixer");

		//forceQuit();
		return;

	}

	std::cout << "Audio library initialised" << std::endl;
	log.writeLog("Audio library initialised");

}

void HoneyBadger::Window::initImageLib(int imgFlags) {

	if (!(IMG_Init(imgFlags) & imgFlags)) { //(IMG_Init(imgFlags) & imgFlags) != imgFlags

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Failed to initialise Image extension library", NULL);
		std::cerr << "Failed to load Image Extension library: " << IMG_GetError() << std::endl;
		log.writeLog("Failed to load Image Extension library");

		//forceQuit();
		return;

	}

	std::cout << "Image library initialised" << std::endl;
	log.writeLog("Image library initialised");

}

int HoneyBadger::Window::initAll() {

	// ** Initialise window here ** //

	std::cout << "\nInitialising SDL" << std::endl;
	log.writeLog("Initialising SDL");

	if (!initSDL()) { return -1; }
	if (!initWindow()) { return -1; }
	if (!initRenderer()) { return -1; }

	std::cout << "\nInitialising sub libraries" << std::endl;
	log.writeLog("Initialising sub libraries");

	initAudioLib();
	initFontLib();
	initImageLib(imageSetting);

	return 0;

}

void HoneyBadger::Window::eventHandler() {

	// ** Set window event listener here ** //

	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT) { //Listen to 'X' button of window being clicked
			std::cout << "\nPlayer quited game through window exit" << std::endl;
			log.writeLog("Player quited game through window exit");
			gameloop = false;
		}

	}

}

void HoneyBadger::Window::fpsCounter() {

	// ** Calculate average FPS ** //

	countedFrames = 0;
	frameTimeAverage = 0;

	currentFrame++;

	currentTicks = (float) SDL_GetTicks();

	frameTimes[currentFrame % FPS_NUM_SAMPLES] = (float) currentTicks - prevTicks;

	prevTicks = currentTicks;

	if (currentFrame < FPS_NUM_SAMPLES) { countedFrames = (float) currentFrame; }
	else { countedFrames = FPS_NUM_SAMPLES; }

	for (int i = 0; i < countedFrames; i++) {

		frameTimeAverage += frameTimes[i];

	}

	frameTimeAverage /= countedFrames;

	if (frameTimeAverage > 0) { avgFPS = 1000.0f / frameTimeAverage; }
	else { avgFPS = 60.0f; }

	//sprintf_s(dynamicWindowTitle, "Honey Badger Engine | FPS: %d", (int) avgFPS); //C-Style

	dynamicWindowTitle << WINDOW_TITLE << " | FPS: " << (int)avgFPS;

	SDL_SetWindowTitle(window, dynamicWindowTitle.str().c_str());

	dynamicWindowTitle.str("");
	dynamicWindowTitle.clear();

}

void HoneyBadger::Window::fpsLimiter() {

	// ** Limit Frame rate ** //

	frameTicks = SDL_GetTicks() - frameStart;

	if (limitFrame && frameDelay> frameTicks) {
		SDL_Delay(frameDelay - frameTicks);
	}

}

void HoneyBadger::Window::update() {

	// ** Set window updating here ** //

	//Update the window to display changes (texture)
	SDL_RenderPresent(renderer);

	//Update the window to display changes (surface)
	//SDL_UpdateWindowSurface(window);

	//Apply default background colour
	SDL_FillRect(backbuffer, NULL, 0);

	fpsLimiter();

	SDL_RenderClear(renderer);

	frameStart = SDL_GetTicks();

}

void HoneyBadger::Window::forceQuit() {

	// ** Use when needed to force quit the program ** //

	std::cerr << "\n\nA critical error has occured, the program will now terminate" << std::endl;
	log.errorLog("A critical error has occured, the program will now terminate");

	TTF_Quit();
	Mix_CloseAudio();
	IMG_Quit();

	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(backbuffer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	std::cout << "Press ENTER to exit" << std::endl;
	std::cin.get();

	exit(-1);

}

// ** Getters ** //

SDL_Window* HoneyBadger::Window::getWindow() { return window; }

SDL_Surface* HoneyBadger::Window::getBackBuffer() { return backbuffer; }

SDL_Renderer* HoneyBadger::Window::getRenderer() { return renderer; }

// ** FPS limiter ** //

void HoneyBadger::Window::setMaxFPS(int maxFPS) {
	
	if (maxFPS != 0) {
		this->maxFPS = maxFPS;
		frameDelay = 1000 / maxFPS;
		limitFrame = true;
	}
	else {
		limitFrame = false;
	}

}

int HoneyBadger::Window::getMaxFPS() { return maxFPS; }

bool HoneyBadger::Window::getIsFrameLimited() { return limitFrame; }

// ** Game loop ** //

void HoneyBadger::Window::setGameLoop(bool gameLoop) { this->gameloop = gameLoop; }

bool HoneyBadger::Window::getGameLoop() { return gameloop; }

// ** Window dimensions ** //

void HoneyBadger::Window::setResolution(int width, int height) {

	this->width = width;
	this->height = height;

	SDL_RenderSetLogicalSize(renderer, width, height);

	SDL_SetWindowSize(window, width, height);

}

void HoneyBadger::Window::setWidth(int width) { this->width = width; }

int HoneyBadger::Window::getWidth() { return width; }

void HoneyBadger::Window::setHeight(int height) { this->height = height; }

int HoneyBadger::Window::getHeight() { return height; }

// ** Screen Settings ** //

void HoneyBadger::Window::setFullScreen(bool fullscreen) {

	if (fullscreen) {
		windowSetting = SDL_WINDOW_FULLSCREEN;
	}
	else {
		windowSetting = SDL_WINDOW_SHOWN;
	}

	if (SDL_SetWindowFullscreen(window, windowSetting) == -1) {
		SDL_Quit();
		std::cerr << "\nSwitching Window Setting Error: " << SDL_GetError() << std::endl;
		log.errorLog("Failed to switch window from either fullscreen or windowed");
		forceQuit();
	}

}

bool HoneyBadger::Window::getFullScreen() {

	if (windowSetting == SDL_WINDOW_FULLSCREEN) {
		return true;
	}
	
	return false;

}

// ** Render type ** //

void HoneyBadger::Window::setRenderType(int renderType) {

	if (renderType == 0) {
		renderSetting = SDL_RENDERER_SOFTWARE;
	}
	else if (renderType == 1) {
		renderSetting = SDL_RENDERER_ACCELERATED;
	}
	else if (renderType == 2) {
		renderSetting = SDL_RENDERER_PRESENTVSYNC;
	}

	std::cout << "\nDestroying old SDL renderer" << std::endl;
	log.writeLog("Destroying old SDL renderer");
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	renderer = SDL_CreateRenderer(window, -1, renderSetting);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	if (renderer == nullptr) {
		SDL_Quit();
		std::cerr << "Failed to re-create SDL renderer" << std::endl;
		log.errorLog("Failed to re-create SDL renderer");
		forceQuit();
	}

	std::cout << "New SDL renderer has been created with switched rendering context" << std::endl;
	log.writeLog("New SDL renderer has been created with switched rendering context");

}

int HoneyBadger::Window::getRenderType() {

	switch (renderSetting) {

		case SDL_RENDERER_SOFTWARE:
			return 0;

		case SDL_RENDERER_ACCELERATED:
			return 1;

		case SDL_RENDERER_PRESENTVSYNC:
			return 2;

		default:
			return -1;

	}

}

// ** In-game FPS counter ** //

void HoneyBadger::Window::setDisplayFPS(bool showFPS) { this->showFPS = showFPS; }

bool HoneyBadger::Window::getDisplayFPS() { return showFPS; }

int HoneyBadger::Window::getAverageFPS() { return (int)avgFPS; }