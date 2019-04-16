#include "texture.h"

HoneyBadger::Texture::Texture(Window& wnd) : wnd(wnd) {

	flip = SDL_FLIP_NONE;

	imageWidth = 0;
	imageHeight = 0;

}

HoneyBadger::Texture::~Texture() {

	SDL_DestroyTexture(image);
	image = nullptr;

	centerPoint = nullptr;

}

void HoneyBadger::Texture::display() {

	SDL_RenderCopyEx(wnd.getRenderer(), image, &imageDimen, &frameDimen, angle, centerPoint, flip);

}

void HoneyBadger::Texture::clear() {

	SDL_DestroyTexture(image);

}

void HoneyBadger::Texture::setPosX(int x) {
	frameDimen.x = x;
}

void HoneyBadger::Texture::setPosY(int y) {
	frameDimen.y = y;
}

int HoneyBadger::Texture::getPosX() {
	return frameDimen.x;
}

int HoneyBadger::Texture::getPosY() {
	return frameDimen.y;
}

void HoneyBadger::Texture::setImageStartPosition(int x, int y) {

	imageDimen.x = x;
	imageDimen.y = y;

}

void HoneyBadger::Texture::setImageStartX(int x) {
	imageDimen.x = x;
}

void HoneyBadger::Texture::setImageStartY(int y) {
	imageDimen.y = y;
}

int HoneyBadger::Texture::getImageStartX() {
	return imageDimen.x;
}

int HoneyBadger::Texture::getImageStartY() {
	return imageDimen.y;
}

void HoneyBadger::Texture::setFrameDimension(int w, int h) {

	frameDimen.w = w;
	frameDimen.h = h;

}

void HoneyBadger::Texture::setFrameW(int w) {
	frameDimen.w = w;
}

void HoneyBadger::Texture::setFrameH(int h) {
	frameDimen.h = h;
}

int HoneyBadger::Texture::getFrameW() {
	return frameDimen.w;
}

int HoneyBadger::Texture::getFrameH() {
	return frameDimen.h;
}

void HoneyBadger::Texture::setImageDimension(int w, int h) {

	imageDimen.w = w;
	imageDimen.h = h;

}

void HoneyBadger::Texture::setImageSizeW(int w) {
	imageDimen.w = w;
}

void HoneyBadger::Texture::setImageSizeH(int h) {
	imageDimen.h = h;
}

int HoneyBadger::Texture::getImageSizeW() {
	return imageDimen.w;
}

int HoneyBadger::Texture::getImageSizeH() {
	return imageDimen.h;
}

void HoneyBadger::Texture::setFrameDimen(int x, int y, int w, int h) {

	frameDimen.x = x;
	frameDimen.y = y;
	frameDimen.w = w;
	frameDimen.h = h;

}

SDL_Rect HoneyBadger::Texture::getFrameRect() {
	return frameDimen;
}

void HoneyBadger::Texture::setImageDimen(int x, int y, int w, int h) {

	imageDimen.x = x;
	imageDimen.y = y;
	imageDimen.w = w;
	imageDimen.h = h;

}

SDL_Rect HoneyBadger::Texture::getImageRect() {
	return imageDimen;
}

void HoneyBadger::Texture::setRotationAngle(double angle) {
	this->angle = angle;
}

double HoneyBadger::Texture::getRotationAngle() {
	return angle;
}

void HoneyBadger::Texture::setImageCenterPoint(SDL_Point* centerPoint) {
	this->centerPoint = centerPoint;
}

SDL_Point* HoneyBadger::Texture::getImageCenterPoint() {
	return centerPoint;
}

void HoneyBadger::Texture::setFlip(SDL_RendererFlip flip) {
	this->flip = flip;
}

SDL_RendererFlip HoneyBadger::Texture::getFlip() {
	return flip;
}

void HoneyBadger::Texture::setImage(SDL_Texture* spriteImage) {

	this->image = spriteImage;

	SDL_QueryTexture(spriteImage, NULL, NULL, &imageWidth, &imageHeight);

}

SDL_Texture* HoneyBadger::Texture::getImage() { return image; }