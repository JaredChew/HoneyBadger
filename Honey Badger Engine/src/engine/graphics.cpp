#include "graphics.h"

HoneyBadger::Graphics::Graphics(Window& wnd) : wnd(wnd) {

	surface = nullptr;
	colour = 0;

}

HoneyBadger::Graphics::~Graphics() {

	surface = nullptr;

	std::cout << "Graphics object cleaned" << std::endl;

}

void HoneyBadger::Graphics::setColour(int colour) {
	this->colour = colour;
	reInit();
}

int HoneyBadger::Graphics::getColour() {
	return colour;
}

void HoneyBadger::Graphics::setOpacity(int opacity) {
	this->opacity = opacity;
	reInit();
}

int HoneyBadger::Graphics::getOpacity() {
	return opacity;
}

void HoneyBadger::Graphics::setX(int x) {
	rect.x = x;
}

void HoneyBadger::Graphics::setY(int y) {
	rect.y = y;
}

void HoneyBadger::Graphics::setW(int w) {
	rect.w = w;
	SDL_FreeSurface(surface);
	reInit();
}

void HoneyBadger::Graphics::setH(int h) {
	rect.h = h;
	SDL_FreeSurface(surface);
	reInit();
}

void HoneyBadger::Graphics::setDimension(int w, int h) {
	rect.w = w;
	rect.h = h;
}

void HoneyBadger::Graphics::setPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
}

int HoneyBadger::Graphics::getX() {
	return rect.x;
}

int HoneyBadger::Graphics::getY() {
	return rect.y;
}

int HoneyBadger::Graphics::getW() {
	return rect.w;
}

int HoneyBadger::Graphics::getH() {
	return rect.h;
}

void HoneyBadger::Graphics::reInit() {
	SDL_FreeSurface(surface);
	surface = SDL_CreateRGBSurface(NULL, rect.w, rect.h, 32, r_Mask, g_Mask, b_Mask, opacity);
}

void HoneyBadger::Graphics::putPixel() {

	SDL_FillRect(surface, NULL, colour);

	SDL_RenderCopy(wnd.getRenderer(), SDL_CreateTextureFromSurface(wnd.getRenderer(), surface), NULL, &rect);

}

void HoneyBadger::Graphics::createPixel(int w, int h, Uint8 r_Mask, Uint8 g_Mask, Uint8 b_Mask, int opacity) {

	rect.w = w;
	rect.h = h;

	this->r_Mask = r_Mask;
	this->g_Mask = g_Mask;
	this->b_Mask = b_Mask;

	this->opacity = opacity;

	surface = SDL_CreateRGBSurface(NULL, w, h, 32, r_Mask, g_Mask, b_Mask, opacity);

}