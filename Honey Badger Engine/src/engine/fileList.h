#pragma once

#include <iostream>
#include <fstream>

#include "logger.h"
#include "../game.h"

namespace HoneyBadger {

	namespace Utility {

		struct FileList {

			int totalFilesCount = TOTAL_FILES;

			std::string directory;
			std::ifstream file;

			void font();
			void graphic();
			void music();
			void sound();

			void result();

			FileList(Logger& log);

		private:
			Logger& log;

		};

	}

}