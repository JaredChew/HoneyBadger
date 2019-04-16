#pragma once

#include "window.h"
#include "texture.h"

namespace HoneyBadger {

	class Animation {

	private:

		Window& wnd;

	private:

		Texture& txtr;

		SDL_Rect animDimen;

		int frameCounter; //incremental purpose

		int columns;	  //number of columns in animation sheet
		int maxFrame;     //total sprite in an image
		int currentFrame; //existing frame draw to the screen
		int frameDelay;   //how long to change to next frame

		bool reverseAnim; //play animation forwards or backwards

	public:

		Animation(Window& wnd, Texture& txtr);
		~Animation();

		//use to extract and draw an individual frame to the screen
		bool displayAnimationOnce();
		void displayAnimation();

		//Initialise animation for sprite
		void setAnimationProperties(int maxAnimSegments, int frameDelay, bool reverseAnim);
		void setAnimationProperties(int maxAnimSegments, int frameDelay, int currentFrame, int frameCounter, bool reverseAnim);

		//set animation direction
		void setIsAnimationReverse(bool reverseAnim);
		bool getIsAnimationReverse();

		void setAnimationColumns(int columns);
		int getAnimationColumns();

		void setAnimationMaxFrames(int maxFrames);
		int getAnimationMaxFrames();

		void setAnimationCurrentFrame(int currentFrame);
		int getAnimationCurrentFrame();

		void setAnimationFrameDelay(int frameDelay);
		int getAnimationFrameDelay();



	private:

		//displays actual animation
		void extractImageFrame();

	};

}