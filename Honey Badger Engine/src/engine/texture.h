#pragma once

#include <iostream>
#include <SDL.h>

#include "window.h"

namespace HoneyBadger {

class Texture {

private:
	Window& wnd;

protected:

	SDL_Texture* image;

	int imageWidth;
	int imageHeight;

	SDL_Rect imageDimen;
	SDL_Rect frameDimen;

	double angle;
	SDL_Point* centerPoint;

	SDL_RendererFlip flip;

public:

	Texture(Window& wnd);
	~Texture();

	void display();
	void clear();

	//Image position on screen

	void setPosX(int x);
	void setPosY(int y);

	int getPosX();
	int getPosY();

	//Which part of the image will display from top left XY to bottom right XY

	void setImageStartPosition(int x, int y);
	
	void setImageStartX(int x);
	void setImageStartY(int y);

	int getImageStartX();
	int getImageStartY();

	//size of display frame of image

	void setFrameDimension(int x, int h);

	void setFrameW(int w);
	void setFrameH(int h);

	int getFrameW();
	int getFrameH();

	//size of image

	void setImageDimension(int w, int h);

	void setImageSizeW(int w);
	void setImageSizeH(int h);

	int getImageSizeW();
	int getImageSizeH();

	//SDL_Rect of image and display frame

	SDL_Rect getImageRect();
	SDL_Rect getFrameRect();

	void setFrameDimen(int x, int y, int w, int h);
	void setImageDimen(int x, int y, int w, int h);

	//image rotation value
	void setRotationAngle(double angle);
	double getRotationAngle();

	//image center point for rotation and movement (???)
	void setImageCenterPoint(SDL_Point* centerPoint);
	SDL_Point* getImageCenterPoint();

	//Image flip
	SDL_RendererFlip getFlip();
	void setFlip(SDL_RendererFlip flip);

	//Image
	SDL_Texture* getImage();
	void setImage(SDL_Texture* image);

};

}