#include "animation.h"

HoneyBadger::Animation::Animation(Window& wnd, Texture& txtr) : wnd(wnd), txtr(txtr) {

	frameCounter = 0;

	columns = 0;
	maxFrame = 0;
	frameDelay = 0;
	currentFrame = 0;

	reverseAnim = false;

}

HoneyBadger::Animation::~Animation() { }

bool HoneyBadger::Animation::displayAnimationOnce() {

	//use to extract and draw an individual frame to the screen

	frameCounter++;

	if (frameCounter > frameDelay) {

		frameCounter = 0;

		if (reverseAnim) { currentFrame--; } //backward to previous frame
		else { currentFrame++; } //forward to next frame

	}

	// prevent animation from continueing after running through full animation once
	if (reverseAnim) {

		if (currentFrame < 0) {
			currentFrame = maxFrame - 1;
			return true;
		}

	}
	else {

		if (currentFrame >= currentFrame) {
			currentFrame = 0;
			return true;
		}

	}

	//use algorithm to extract the image out from sprite image
	extractImageFrame();

	return false;

}

void HoneyBadger::Animation::displayAnimation() {

	//use to extract and draw an individual frame to the screen

	frameCounter++;

	if (frameCounter > frameDelay) {

		frameCounter = 0;

		if (reverseAnim) { currentFrame--; } //backward to previous frame
		else { currentFrame++; } //forward to next frame

	}

	//resetting animation to continue loop
	if (reverseAnim) {
		if (currentFrame < 0) { currentFrame = maxFrame - 1; }
	}
	else {
		if (currentFrame > maxFrame - 1) { currentFrame = 0; }
	}

	//use algorithm to extract the image out from sprite image
	extractImageFrame();

}

void HoneyBadger::Animation::extractImageFrame() {

	//get total column from the sprite image
	columns = txtr.getImageSizeW() / txtr.getFrameW();

	//key part to extract the image from sprite sheet
	animDimen.y = (currentFrame / columns) * txtr.getImageSizeH();
	animDimen.x = (currentFrame % columns) * txtr.getImageSizeW();

	animDimen.w = txtr.getImageSizeW();
	animDimen.h = txtr.getImageSizeH();

	SDL_RenderCopyEx(wnd.getRenderer(), txtr.getImage(), &animDimen, &txtr.getFrameRect(), txtr.getRotationAngle(), txtr.getImageCenterPoint(), txtr.getFlip());

}

void HoneyBadger::Animation::setAnimationProperties(int maxFrame, int frameDelay, bool reverseAnim) {

	this->maxFrame = maxFrame;
	this->frameDelay = frameDelay;

	currentFrame = 0; //the first frame
	frameCounter = 0; //starting counter

	this->reverseAnim = reverseAnim;

}

void HoneyBadger::Animation::setAnimationProperties(int maxFrame, int frameDelay, int currentFrame, int frameCounter, bool reverseAnim) {

	this->maxFrame = maxFrame;
	this->frameDelay = frameDelay;
	this->currentFrame = currentFrame;
	this->frameCounter = frameCounter;
	this->reverseAnim = reverseAnim;

}

void HoneyBadger::Animation::setIsAnimationReverse(bool reverseAnim) {
	this->reverseAnim = reverseAnim;
}

bool HoneyBadger::Animation::getIsAnimationReverse() {
	return reverseAnim;
}

void HoneyBadger::Animation::setAnimationColumns(int columns) {
	this->columns = columns;
}

int HoneyBadger::Animation::getAnimationColumns() {
	return columns;
}

void HoneyBadger::Animation::setAnimationMaxFrames(int maxFrame) {
	this->maxFrame = maxFrame;
}

int HoneyBadger::Animation::getAnimationMaxFrames() {
	return maxFrame;
}

void HoneyBadger::Animation::setAnimationCurrentFrame(int currentFrame) {
	this->currentFrame = currentFrame;
}

int HoneyBadger::Animation::getAnimationCurrentFrame() {
	return currentFrame;
}

void HoneyBadger::Animation::setAnimationFrameDelay(int frameDelay) {
	this->frameDelay = frameDelay;
}

int HoneyBadger::Animation::getAnimationFrameDelay() {
	return frameDelay;
}