#include "Obstacle.h"
#include <time.h>
#include <iostream>

Obstacle::Obstacle()
{
	_lowerTube.setX(540);
	_lowerTube.setY(400);
	_lowerTube.setH(360);
	_lowerTube.setW(75);
	_lowerTube.setColor(0, 150, 0, 255);

	_spacebetween = 100;

	_upperTube.setX(540);
	_upperTube.setY(200);
	_upperTube.setH(360);
	_upperTube.setW(75);
	_lowerTube.setColor(0, 150, 0, 255);
}
void Obstacle::draw() const
{
	_upperTube.draw();
	_lowerTube.draw();
}

void Obstacle::setRandomness(float rs)
{
	srand(time(NULL));
	_spacebetween = ((rand() * rand()) % 40) + 60;
	_spacebetween *= rs;
	srand(time(NULL));
	int lowerTubeY = ((rand() * rand()) % 160) + 100;
	lowerTubeY *= rs;

	_lowerTube._y = lowerTubeY;
	_upperTube._y = lowerTubeY - _spacebetween - (360 * rs);
}

void Obstacle::moving(float rs, size_t& score)
{
	_upperTube._x -= 3 * rs;
	_lowerTube._x -= 3 * rs;

	if (_upperTube._x < -100 * rs)
	{
		_upperTube._x = 740 * rs;
		_lowerTube._x = 740 * rs;
		setRandomness(rs);
		score++;
	}
}

void Obstacle::setUpper(int w, int h, int x, int y, int r, int g, int b, int a)
{
	_upperTube.setW(w);
	_upperTube.setH(h);
	_upperTube.setX(x);
	_upperTube.setY(y);
	_upperTube.setColor(r, g, b, a);
}

void Obstacle::setLower(int w, int h, int x, int y, int r, int g, int b, int a)
{
	_lowerTube.setW(w);
	_lowerTube.setH(h);
	_lowerTube.setX(x);
	_lowerTube.setY(y);
	_lowerTube.setColor(r, g, b, a);
}

void Obstacle::setUpper(int w, int h, int x, int y, const char* texture)
{
	_upperTube.setW(w);
	_upperTube.setH(h);
	_upperTube.setX(x);
	_upperTube.setY(y);
	_upperTube.setTexture(texture);
}

void Obstacle::setLower(int w, int h, int x, int y, const char* texture)
{
	_lowerTube.setW(w);
	_lowerTube.setH(h);
	_lowerTube.setX(x);
	_lowerTube.setY(y);
	_lowerTube.setTexture(texture);
}
