#include "utilities.h"

int HoneyBadger::Utility::randAboveNum(int startNum) {

	srand((unsigned)time(NULL)); //srand(unsigned(time(NULL)));

	int rng = 0;

	do {

		rng = rand();

	} while (rng < startNum);

	return rng;

}

int HoneyBadger::Utility::randAboveNum(int startNum, int notMore) {

	srand((unsigned)time(NULL)); //srand(unsigned(time(NULL)));

	int rng = 0;

	do {

		rng = rand() % notMore;

	} while (rng < startNum);

	return rng;

}

void HoneyBadger::Utility::fileChecker(Logger& log) {

	FileList* fl = new FileList(log);

	fl->font();
	fl->graphic();
	fl->music();
	fl->sound();

	fl->result();

	delete fl;

}

void HoneyBadger::Utility::popUpWindow(SDL_MessageBoxFlags windowType, char* header, char* message, SDL_Window* parentWindow) {

	SDL_ShowSimpleMessageBox(windowType, header, message, parentWindow);

}

template<typename custom> bool HoneyBadger::Utility::compareGreather(custom comparingWith, custom toBeComparedWith) {

	return (comparingWith > toBeComparedWith);

}

template<typename custom> bool HoneyBadger::Utility::compareLesser(custom comparingWith, custom toBeComparedWith) {

	return (comparingWith > toBeComparedWith);

}