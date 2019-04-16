#include "font.h"

HoneyBadger::Font::Font(Window& wnd) : wnd(wnd) {

	font = nullptr;
	renderedText = nullptr;
	text = nullptr;

}

HoneyBadger::Font::~Font() {

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

	//Window close causes error, VS close does not
	if (font == nullptr) {
		std::cin.get();
	}
	TTF_CloseFont(font);
	font = nullptr;

}

void HoneyBadger::Font::setFont(TTF_Font* font) {
	this->font = font;
}

void HoneyBadger::Font::setFontProperties(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte
	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

}

void HoneyBadger::Font::setFontColour(Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

}

void HoneyBadger::Font::setFontSizeAndDimension(int x, int y, int w, int h) {

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte
	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

}
void HoneyBadger::Font::setFontPosition(int x, int y) {

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte

}
void HoneyBadger::Font::setFontDimensions(int w, int h) {

	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

}

void HoneyBadger::Font::displayFont(std::string msg) {

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	text = SDL_CreateTextureFromSurface(wnd.getRenderer(), renderedText);

	SDL_RenderCopy(wnd.getRenderer(), text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

void HoneyBadger::Font::displayFont(std::string msg, int x, int y, int w, int h) {

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte

	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

	text = SDL_CreateTextureFromSurface(wnd.getRenderer(), renderedText);

	SDL_RenderCopy(wnd.getRenderer(), text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

void HoneyBadger::Font::displayFont(std::string msg, Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	text = SDL_CreateTextureFromSurface(wnd.getRenderer(), renderedText);

	SDL_RenderCopy(wnd.getRenderer(), text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}

void HoneyBadger::Font::displayFont(std::string msg, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {

	color.r = r;
	color.g = g;
	color.b = b;

	renderedText = TTF_RenderText_Solid(font, msg.c_str(), color);

	textRect.x = x;  //controls the rect's x coordinate 
	textRect.y = y; // controls the rect's y coordinte
	textRect.w = w; // controls the width of the rect
	textRect.h = h; // controls the height of the rect

	text = SDL_CreateTextureFromSurface(wnd.getRenderer(), renderedText);

	SDL_RenderCopy(wnd.getRenderer(), text, NULL, &textRect);

	//Below code prevents memory leak

	SDL_FreeSurface(renderedText);
	renderedText = nullptr;

	SDL_DestroyTexture(text);
	text = nullptr;

}