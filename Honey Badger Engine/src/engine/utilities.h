#pragma once

#include <iostream>
#include <ctime>

#include "logger.h"
#include "fileList.h"

namespace HoneyBadger {

	namespace Utility {

		void fileChecker(Logger& log);

		int randAboveNum(int startNum);
		int randAboveNum(int startNum, int notMore);

		void popUpWindow(SDL_MessageBoxFlags windowType, char* header, char* message, SDL_Window* parentWindow);

		template<typename custom> bool compareGreather(custom comparingWith, custom toBeComparedWith);
		template<typename custom> bool compareLesser(custom comparingWith, custom toBeComparedWith);

	}

}