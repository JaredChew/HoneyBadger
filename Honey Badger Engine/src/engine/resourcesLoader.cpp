#include "resourcesLoader.h"

HoneyBadger::ResourcesLoader::ResourcesLoader(Window& wnd) : wnd(wnd) {  }

HoneyBadger::ResourcesLoader::~ResourcesLoader() { }

SDL_Surface* HoneyBadger::ResourcesLoader::loadSurfaceImage(const char* imageFileDir) {

	//** Load image and apply alpha masking **//

	SDL_Surface* temp_Image = IMG_Load(imageFileDir);

	std::string fileExtension = imageFileDir;

	if (temp_Image == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Failed to load image", NULL);
		std::cerr << "\nSDL failed to load image at: " << imageFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	if (fileExtension.substr(fileExtension.length() - 3) != "png") { // == "bmp"

		//create optimised image using current image
		temp_Image = SDL_ConvertSurface(temp_Image, wnd.getBackBuffer()->format, 0);

		//Set transparency

		Uint32 colourKey = SDL_MapRGB(temp_Image->format, 255, 0, 255);

		//update system with transparency colour
		SDL_SetColorKey(temp_Image, SDL_TRUE, colourKey);

	}

	return temp_Image;

}

SDL_Texture* HoneyBadger::ResourcesLoader::loadTextureImage(const char* imageFileDir) {

	//** Load image and apply alpha masking **//

	SDL_Surface* temp_Surface = IMG_Load(imageFileDir);

	std::string fileExtension = imageFileDir;

	if (temp_Surface == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Failed to load image", NULL);
		std::cerr << "\nSDL failed to load image at: " << imageFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	if (fileExtension.substr(fileExtension.length() - 3) != "png") { // == "bmp"

		//create optimised image using current image
		temp_Surface = SDL_ConvertSurface(temp_Surface, wnd.getBackBuffer()->format, 0);

		//Set transparency

		Uint32 colourKey = SDL_MapRGB(temp_Surface->format, 255, 0, 255);

		//update system with transparency colour
		SDL_SetColorKey(temp_Surface, SDL_TRUE, colourKey);

		fileExtension = "";
		
	}

	SDL_Texture *textureToPass = SDL_CreateTextureFromSurface(wnd.getRenderer(), temp_Surface);

	SDL_FreeSurface(temp_Surface);

	return textureToPass;

}

Mix_Chunk* HoneyBadger::ResourcesLoader::loadSound(char* soundFileDir) {

	Mix_Chunk* soundToPass = Mix_LoadWAV(soundFileDir);

	if (soundToPass == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Fail to load Sound Files!", NULL);
		std::cerr << "\nSDL failed to load sound at: " << soundFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	return soundToPass;

}

Mix_Music* HoneyBadger::ResourcesLoader::loadMusic(char* MusicFileDir) {

	Mix_Music* musicToPass = Mix_LoadMUS(MusicFileDir);

	if (musicToPass == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "Fail to load music Files!", NULL);
		std::cerr << "\nSDL failed to load music at: " << MusicFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	return musicToPass;

}

TTF_Font* HoneyBadger::ResourcesLoader::loadFont(char* fontFileDir, int fontSize) {

	TTF_Font* fontToPass = TTF_OpenFont(fontFileDir, fontSize);

	if (fontToPass == nullptr) {

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error", "SDL Font failed to load font", NULL);
		std::cerr << "\nSDL failed to load font at: " << fontFileDir << std::endl;

		wnd.forceQuit();
		//return NULL;

	}

	return fontToPass;

}