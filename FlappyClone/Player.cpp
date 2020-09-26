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

	//_punch = false;
	//_moving = false;
	//_textureDir = "Resources/player1/";
	//_bodyName = "KenBlue";
	//_headName = "Emo";

	//_counter = 0;

	//_spriteFrame = 'A';
	//_attackSpritesFrame = 'A';
	//_path = "Resources/Emo_glava.png";

	//_idleSPRT = "Idle.png";
	//_movingSPRT = "Moving.png";
	//_punchSPRT = "Punch.png";
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
		/*switch (event.key.keysym.sym)
		{
		case SDLK_a:
			_body.setX(_body._x - 3 * rs);
			break;

		case SDLK_d:
			_body.setX(_body._x + 3 * rs);
			break;

		case SDLK_w:
			_body.setY(_body._y - 100 * rs);
			break;

		case SDLK_s:
			_body.setY(_body._y + 10);
			break;

		case SDLK_t:

		default:
			break;
		}*/
	}
	else if (event.type == SDL_KEYUP)
	{
		//_punch = false;
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


//SPRITES ANIMATION
//void Player::animateSprites()
//{
//	if (_punch)  //punch animation
//	{
//		_counter++;
//		if (_counter % 6 == 0)	//on every 6th frame the image changes
//		{
//			if (_attackSpritesFrame > 'F')
//			{
//				_attackSpritesFrame = 'A';
//				_punch = false;
//			}
//			_body.setTexture(_textureDir + _attackSpritesFrame + _bodyName + _punchSPRT);
//			_head.setTexture(_textureDir + _attackSpritesFrame + _headName + _punchSPRT);
//			_attackSpritesFrame++;
//		}
//	}
//	else if (_moving) //moving animation
//	{
//		_counter++;
//		if (_counter % 7 == 0)
//		{
//			if (_spriteFrame > 'E')
//			{
//				_spriteFrame = 'A';
//			}
//			_body.setTexture(_textureDir + _spriteFrame + _bodyName + _movingSPRT);
//			_head.setTexture(_textureDir + _spriteFrame + _headName + _movingSPRT);
//			_spriteFrame++;
//		}
//	}
//	else  //idle animation
//	{
//		_counter++;
//		if (_counter % 10 == 0)
//		{
//			if (_spriteFrame > 'D')
//			{
//				_spriteFrame = 'A';
//			}
//			_body.setTexture(_textureDir + _spriteFrame + _bodyName + _idleSPRT);
//			_head.setTexture(_textureDir + _spriteFrame + _headName + _idleSPRT);
//			_spriteFrame++;
//		}
//	}
//}

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