#include "Rect.h"
#include <SDL_image.h>
#include <iostream>

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a) :
	_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
}

Rect::Rect(int w, int h, int x, int y, const std::string& image_path) :
	_w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str()); //c_str converts it to a construct pointer
	if (!surface)
	{
		std::cerr << "Failed to create surface\n";
	}

	_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!_texture)
	{
		std::cerr << "Failed to create texture\n";
	}

	SDL_FreeSurface(surface);
}

Rect::~Rect()
{
	SDL_DestroyTexture(_texture);
}

void Rect::draw() const
{
	SDL_Rect rect = { _x, _y, _w, _h };

	if (_texture)
	{
		SDL_RenderCopy(Window::renderer, _texture, nullptr, &rect);
	}
	else
	{
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}

void Rect::pollEvents(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{

		default:
			break;
		}
	}
}
