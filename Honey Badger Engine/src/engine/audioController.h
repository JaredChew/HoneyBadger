#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

#include "window.h"

namespace HoneyBadger {

	namespace AudioController {

		//Sound
		int playSound(Mix_Chunk* playSound, int loop);
		int playSound(Mix_Chunk* playSound, int loop, int channel);

		void pauseSound(int channel);
		void resumeSound(int channel);
		void stopSound(int channel);

		//Music
		void playMusic(Mix_Music* playMusic, int loop);
		void pauseMusic();
		void resumeMusic();
		void stopMusic();

	}

}