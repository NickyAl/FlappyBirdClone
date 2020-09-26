#pragma once
#include "Window.h"
#include <string>

class Rect
{
private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture* _texture;

public:
	Rect(int w, int h, int x, int y, int r, int g, int b, int a);
	Rect(int w, int h, int x, int y, const std::string& image_path);
	~Rect();

	void draw()const;
	void pollEvents(SDL_Event& event);

	void setY(int y) { _y = y; }
};