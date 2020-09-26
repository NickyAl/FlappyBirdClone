#pragma once
#include "Object.h"
#include <string>

class Player
{
protected:
	Object _body;

private:
	size_t _counter = 0;

public:
	bool _hop = false;

	Player();
	//~Player();

	void pollEvents(SDL_Event& event, float rs);

	void draw()const;

	void flying(float rs);
	void falling(float rs) { _body._y += 2 * rs; }

	//SETTERS and GETTERS
	void setBody(int w, int h, int x, int y, const char* texture);
	void setBody(int w, int h, int x, int y, int r, int g, int b, int a);

	Object& getBody() { return _body; }

	int getLocX() { return _body._x; }
	int getLocY() { return _body._y; }


	int getPlayerH() { return _body.getH(); }
};

