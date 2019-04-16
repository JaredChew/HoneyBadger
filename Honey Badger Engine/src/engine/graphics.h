#pragma once

#include <SDL.h>

#include "window.h"

namespace HoneyBadger {

	class Graphics {

		private:
			Window& wnd;

		private:

			SDL_Surface* surface;
			SDL_Rect rect;

			Uint8 r_Mask;
			Uint8 g_Mask;
			Uint8 b_Mask;

			int colour;
			int opacity;

		public:
			Graphics(Window& wnd);
			~Graphics();

			void setColour(int colour);
			int getColour();

			void setOpacity(int opacity);
			int getOpacity();

			void setX(int x);
			void setY(int y);
			void setW(int w);
			void setH(int h);

			int getX();
			int getY();
			int getW();
			int getH();

			void setPosition(int x, int y);
			void setDimension(int w, int h);

			void reInit();
			void putPixel();
			void createPixel(int w, int h, Uint8 r_Mask, Uint8 g_Mask, Uint8 b_Mask, int opacity);

		};

}