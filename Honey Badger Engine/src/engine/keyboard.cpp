#include "keyboard.h"

HoneyBadger::Keyboard::Keyboard() {

	// ** Initialise everything here ** //

	kbdInput = (Uint8*)SDL_GetKeyboardState(NULL);

	lastKeyState = 0;
	lastHoldState = 0;

	pressDelay = 10;
	pressDelayCounter = 0;

}

HoneyBadger::Keyboard::~Keyboard() {

	kbdInput = nullptr;

	std::cout << "Keyboard object cleaned" << std::endl;

}

bool HoneyBadger::Keyboard::isPressedWithAnother(int keyCode) {

	if (kbdInput[keyCode] && pressDelayCounter == 0) {
		lastKeyState = keyCode;
		return true;
	}

	return false;

}

bool HoneyBadger::Keyboard::isPressed(int keyCode) {

	// ** Checks if key is being pressed ** //

	if (kbdInput[keyCode] && pressDelayCounter == 0) {
		lastKeyState = keyCode;
		pressDelayCounter++;
		return true;
	}

	return false;

}

bool HoneyBadger::Keyboard::isHold(int keyCode) {

	// ** Checks if key is being hold ** //

	if (kbdInput[keyCode] && lastHoldState == keyCode && pressDelayCounter == 0) {
		pressDelayCounter++;
		//std::cout << keyCode + "key is being hold" << std::endl;
		return true;
	}

	lastHoldState = keyCode;

	return false;

}

void HoneyBadger::Keyboard::setDelayPress(int delayPress) {

	this->pressDelay = delayPress;

}

int HoneyBadger::Keyboard::getPressDelay() {

	return pressDelay;

}

int HoneyBadger::Keyboard::getLastKeyState() {

	return lastKeyState;

}

int HoneyBadger::Keyboard::getLastHoldState() {

	return lastHoldState;

}

void HoneyBadger::Keyboard::update() {

	if (pressDelayCounter == pressDelay) { pressDelayCounter = 0; }
	else if (pressDelayCounter != 0) { pressDelayCounter++; }

}