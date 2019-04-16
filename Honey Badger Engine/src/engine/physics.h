#pragma once

#include <iostream>
#include <math.h>
#include <SDL.h>

namespace HoneyBadger {

	namespace Physics {

		void gravity();

		void acceleration();
		void deceleration();

		//Axis aligned bounding box [AABB]
		bool collisionBox(SDL_Rect colidded, SDL_Rect colidder);
		int collisionCircle(int mainPosX, int mainPosY, int clashPosX, int clashPosY);

	}

}