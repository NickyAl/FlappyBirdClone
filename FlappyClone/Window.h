#pragma once
#include <string>
#include <SDL.h>

class Window
{
private:
	std::string title;
	int _width = 640;
	int _height = 360;

	float _resSet = 1.0f;
	bool _openedSettings = false;

	bool _closed = false;

	SDL_Window* _window = nullptr;

	bool init();

public:
	static SDL_Renderer* renderer;

public:
	Window(const std::string& newTitle, int newWidth, int newHeight);
	~Window();

	bool isClosed()const { return this->_closed; }

	void pollEvents(SDL_Event& event);
	void clear() const; //"means to put stuff onto the screen" - youtube dude

	//setters and getters

	void setOpndSttng(bool x) { _openedSettings = x; }
	int getRS() { return _resSet; } //get resolution settings
};