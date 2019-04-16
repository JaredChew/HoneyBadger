#include "audioController.h"

// ** SOUND ** //

int HoneyBadger::AudioController::playSound(Mix_Chunk* playSound, int loop) {

	//Plays the audio and returns the channel number
	return Mix_PlayChannel(-1, playSound, loop);

}

int HoneyBadger::AudioController::playSound(Mix_Chunk* playSound, int loop, int channel) {

	//Plays the audio and returns the channel number
	return Mix_PlayChannel(channel, playSound, loop);

}

void HoneyBadger::AudioController::pauseSound(int channel) {
	Mix_Pause(channel);
}

void HoneyBadger::AudioController::resumeSound(int channel) {
	Mix_Resume(channel);
}

void HoneyBadger::AudioController::stopSound(int channel) {
	Mix_HaltChannel(channel);
}

// ** MUSIC ** //

void HoneyBadger::AudioController::playMusic(Mix_Music* playMusic, int loop) {
	Mix_PlayMusic(playMusic, loop);
}

void HoneyBadger::AudioController::pauseMusic() {
	Mix_PauseMusic();
}

void HoneyBadger::AudioController::resumeMusic() {
	Mix_ResumeMusic();
}

void HoneyBadger::AudioController::stopMusic() {
	Mix_HaltMusic();
}