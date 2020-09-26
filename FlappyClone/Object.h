#pragma once
#include <string>
#include "Window.h"

//MOTHER CLASS FOR ALL OBJECTS
class Object
{
protected:
	int _w, _h;				//Width and Height
	int _r, _g, _b, _a;		//Color if there is no texture
	SDL_Texture* _texture;  //Texture (2D image for the figure)

public:
	int _x, _y;				//Coordinates will need to change a lot in the event poll which means we would need to change them directly 

	Object();
	Object(int w, int h, int x, int y, int r, int g, int b, int a);
	Object(int w, int h, int x, int y, const std::string& image_path);
	~Object();

	//Renders the texture or if there isnt one a rectangle filled with the color
	void draw()const;

	//loadTexture is used as a setter
	SDL_Texture* LoadTexture(std::string filepath);

	//SETTERS AND GETTERS

	void setW(int w) { _w = w; }
	int getW()const { return _w; }

	void setH(int h) { _h = h; }
	int getH()const { return _h; }

	void setX(int x) { _x = x; }
	int getX()const { return _x; }

	void setY(int y) { _y = y; }
	int getY()const { return _y; }

	void setColor(int r, int g, int b, int a) { _r = r; _g = g; _b = b; _a = a; }

	void setTexture(const char* filepath) { _texture = LoadTexture(filepath); }
	void setTexture(char* filepath) { _texture = LoadTexture(filepath); }
	void setTexture(std::string filepath) { _texture = LoadTexture(filepath); }
};