#include "Player.h"
#include <SDL_image.h>
#include <iostream>
#include <string>

Player::Player()
{
	_body.setW(100);
	_body.setH(100);
	_body.setX(100);
	_body.setY(100);
	_body.setColor(220, 180, 0, 255);
	_counter = 0;
	_hop = false;
}

void Player::pollEvents(SDL_Event& event, float rs)
{

	if (event.type == SDL_KEYDOWN)
	{
		if (_hop == false)
		{		
			_hop = true;
			_counter = 0;
		}
	}
}

void Player::draw() const
{
	_body.draw();
}

void Player::flying(float rs)
{
	int speed = 3;
	_counter++;
	
	if (_counter % 18 > 14)
	{
		speed = 1;
	}
	_body._y -= speed * rs;
	if (_counter % 18 == 17)
	{
		_hop = false;
	}
}

//SETTERS
void Player::setBody(int w, int h, int x, int y, const char* texture)
{
	_body.setW(w);
	_body.setH(h);
	_body.setX(x);
	_body.setY(y);
	_body.setTexture(texture);
}

void Player::setBody(int w, int h, int x, int y, int r, int g, int b, int a)
{
	_body.setW(w);
	_body.setH(h);
	_body.setX(x);
	_body.setY(y);
	_body.setColor(r, g, b, a);
}