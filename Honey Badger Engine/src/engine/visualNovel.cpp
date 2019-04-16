#include "visualNovel.h"

HoneyBadger::Module::VisualNovel::VisualNovel(Window& wnd) : wnd(wnd) {

	font = new HoneyBadger::Font(wnd);

	name = nullptr;
	textToDisplay = nullptr;

	namePosition = 0;

	displayNameFrame = true;

	dialogueFrame = nullptr;
	nameFrame = nullptr;
	wallFrame = nullptr;

}

HoneyBadger::Module::VisualNovel::~VisualNovel() { }

void HoneyBadger::Module::VisualNovel::renderConversation() {

	SDL_RenderCopy(wnd.getRenderer(), dialogueFrame, NULL, &dialogueRect);

	if (displayNameFrame) {
		SDL_RenderCopy(wnd.getRenderer(), nameFrame, NULL, &nameRect);
		//text name
	}

	//text conversation

}

void HoneyBadger::Module::VisualNovel::renderTextWall() {

	SDL_RenderCopy(wnd.getRenderer(), wallFrame, NULL, &wallRect);

	//wall of text

}

void HoneyBadger::Module::VisualNovel::setTextConversation(char* name, char* textToDisplay) {

	this->name = name;
	this->textToDisplay = textToDisplay;

}

void HoneyBadger::Module::VisualNovel::setTextWall(char* textToDisplay) {

	this->textToDisplay;

}

void HoneyBadger::Module::VisualNovel::setDialogueFrame(SDL_Texture* dialogueFrame) {

	this->dialogueFrame = dialogueFrame;

	SDL_QueryTexture(dialogueFrame, NULL, NULL, &dialogueRect.w, &dialogueRect.h);

	dialogueRect.x = (int) 0;
	dialogueRect.y = (int) wnd.getHeight() -dialogueRect.h;

}

void HoneyBadger::Module::VisualNovel::setNameFrame(SDL_Texture* nameFrame) {

	this->nameFrame = nameFrame;

	SDL_QueryTexture(nameFrame, NULL, NULL, &nameRect.w, &nameRect.h);

	nameRect.x = (int) 0.05 * wnd.getWidth();
	nameRect.y = (int) dialogueRect.h - (nameRect.h / 2);

}

void HoneyBadger::Module::VisualNovel::setTextWallFrame(SDL_Texture* wallFrame) {

	this->wallFrame = wallFrame;

	SDL_QueryTexture(wallFrame, NULL, NULL, &wallRect.w, &wallRect.h);

	nameRect.x = (int) 0.05 * wnd.getWidth();
	nameRect.y = (int) 0.05 * wnd.getHeight();

}

void HoneyBadger::Module::VisualNovel::setDialogueFrameDimensions(int w, int h) {

	dialogueRect.w = w;
	dialogueRect.h = h;

}

void HoneyBadger::Module::VisualNovel::setNameFrameDiamensions(int w, int h) {

	nameRect.w = w;
	nameRect.h = h;

}

void HoneyBadger::Module::VisualNovel::setTextWallFrameDiamensions(int w, int h) {

	wallRect.w = w;
	wallRect.h = h;

}

void HoneyBadger::Module::VisualNovel::setDialogueFramePositions(int x, int y) {

	dialogueRect.x = x;
	dialogueRect.y = y;

}

void HoneyBadger::Module::VisualNovel::setNameFrameCustomPosition(int x, int y) {

	nameRect.x = x;
	nameRect.y = y;

}

void HoneyBadger::Module::VisualNovel::setTextWallFrameCustomPosition(int x, int y) {

	wallRect.x = x;
	wallRect.y = y;

}

void HoneyBadger::Module::VisualNovel::setNameFramePosition(bool left, bool right) {

	//Default is left

	if (left) { namePosition = LEFT; }
	else if (right) { namePosition = RIGHT; }
	else { namePosition = NONE; }

	updateNameFramePosition();

}

void HoneyBadger::Module::VisualNovel::updateNameFramePosition() {

	if (namePosition == LEFT) {
		nameRect.x = (int) 0.05 * wnd.getWidth();
		nameRect.y = (int)dialogueRect.h - (nameRect.h / 2);
	}
	else if (namePosition == RIGHT) {
		nameRect.x = (int) 0.05 * wnd.getWidth();
		nameRect.y = (int)dialogueRect.h - (nameRect.h / 2);
	}
	else {
		displayNameFrame = false;
	}

}

void HoneyBadger::Module::VisualNovel::setDisplayNameFrame(bool isplayNameFrame) {
	this->displayNameFrame = displayNameFrame;
}

bool HoneyBadger::Module::VisualNovel::getDisplayNameFrame() {
	return displayNameFrame;
}