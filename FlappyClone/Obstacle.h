#pragma once
#include "Object.h"

class Obstacle : public Object
{
private:
	Object _upperTube;
	Object _lowerTube;

	int _spacebetween;

public:
	Obstacle();

	void draw()const;

	void setRandomness(float rs);

	void moving(float rs, size_t& score);

	void setUpper(int w, int h, int x, int y, int r, int g, int b, int a);
	void setLower(int w, int h, int x, int y, int r, int g, int b, int a);

	void setUpper(int w, int h, int x, int y, const char* texture);
	void setLower(int w, int h, int x, int y, const char* texture);

	int getUpY() { return _upperTube.getY(); }
	int getLowY() { return _lowerTube.getY(); }

	int getUpX() { return _upperTube.getX(); }
	int getLowX() { return _lowerTube.getX(); }

	int getUpH() { return _upperTube.getH(); }

	//void setX(int x) { _upperTube._x = x; _lowerTube._x = x; }
};

