#include "fileList.h"

HoneyBadger::Utility::FileList::FileList(Logger& log) : log(log) { }

void HoneyBadger::Utility::FileList::result() {

	if (totalFilesCount != TOTAL_FILES) {

		std::cerr << "\nIncomplete files (" << totalFilesCount << "/" << TOTAL_FILES << "), the program will now terminate" << std::endl;
		//log.warningLog("\nIncomplete files (" << totalFilesCount << "/" << TOTAL_FILES << "), the program will now terminate");

		std::cout << "Press ENTER to exit" << std::endl;
		std::cin.get();

		exit(-1);

	}

	std::cout << "All files validated" << std::endl;
	log.writeLog("All files validated");

}

void HoneyBadger::Utility::FileList::font() {

	// ** FONT FILES ** //

	directory = "asset/font/";

	file = std::ifstream((directory + "consolas.ttf").c_str());
	if (!file.is_open()) {
		std::cerr << "Missing file: " << directory + "consolas.ttf" << std::endl;
		//log.warningLog("Missing file: " << directory + "consolas.ttf");
		totalFilesCount--;
	}

}

void HoneyBadger::Utility::FileList::graphic() {

	// ** GRAPHIC FILES ** //

	directory = "asset/graphic/";

}

void HoneyBadger::Utility::FileList::music() {

	// ** MUSIC FILES ** //

	directory = "asset/music/";

}

void HoneyBadger::Utility::FileList::sound() {

	// ** SOUND FILES ** //

	directory = "asset/sound/";

}