#pragma once
#include "Object.h"
#include <string>

class Player
{
protected:
	Object _body;

private:
	size_t _counter = 0;

	//for sprite animations
	//bool _punch = false;
	//bool _moving = false;

	//size_t _counter = 0; //counts how many frames have passed

	//char _spriteFrame = 'A'; //using letters as numbers of the image from the sprite A is number 1 B is 2 ...
	//char _attackSpritesFrame = 'A';
	//std::string _path = "Resources/Emo_glava.png";

	//std::string _idleSPRT = "Idle.png";
	//std::string _movingSPRT = "Moving.png";
	//std::string _punchSPRT = "Punch.png";

	//std::string _textureDir;	//"Resources/player1/"
	//std::string _bodyName;		//"KenBlue" //gonna add color as a variable later
	//std::string _headName;		//"Emo"

public:
	bool _hop = false;

	Player();
	//~Player();

	void pollEvents(SDL_Event& event, float rs);

	void draw()const;

	void flying(float rs);
	void falling(float rs) { _body._y += 2 * rs; }

	//void animateSprites();

	//SETTERS and GETTERS

	void setBody(int w, int h, int x, int y, const char* texture);
	void setBody(int w, int h, int x, int y, int r, int g, int b, int a);

	Object& getBody() { return _body; }

	int getLocX() { return _body._x; }
	int getLocY() { return _body._y; }


	int getPlayerH() { return _body.getH(); }
};

