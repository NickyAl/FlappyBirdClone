#include <iostream>
#include "Window.h"
#include "Rect.h"
#include "Text.h"
#include "Object.h"
#include "Player.h"
#include "Obstacle.h"
#include <string>
#include "tools.h"

void pollEvents(Window& window, Player& player1, /*SecondPlayer& player2,*/ float resolutionSetting)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event);
		player1.pollEvents(event, resolutionSetting);
		/*player2.pollEvents(event);*/
	}
}

void gameOVerPoll(Window& window, /*SecondPlayer& player2,*/ float resolutionSetting)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event);
		/*player2.pollEvents(event);*/
	}
}

void pollEventsForMenu(Window& window, Rect& menu)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event);
		menu.pollEvents(event);
	}
}

int main(int argc, char** argv)
{
	Window startMenu("Settings", 200, 300);
	Rect menu(200, 300, 0, 0, "Resources/testMenu.jpg");

	while (!startMenu.isClosed())
	{

		pollEventsForMenu(startMenu, menu);

		startMenu.setOpndSttng(true);

		menu.draw();

		startMenu.clear();

	}
	int rs = startMenu.getRS(); //resolution settings
	size_t scoreInt = 0;
	char scoreChar[4] = { '\0' };

	//Stuff needed to lock fps
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	//

	Window window("FlappyClone", 640 * rs, 360 * rs);
	Object background(640 * rs, 360 * rs, 0, 0, 100, 200, 255, 255);

	//Text text(Window::renderer, "Resources/arial.ttf", 30, "0", { 30, 10, 10, 255 });

	Player player1;
	player1.setBody(18 * rs, 12 * rs, 80 * rs, 0, "Resources/DirpyBird.png");

	Obstacle obstacle;
	obstacle.setUpper(35 * rs, 360 * rs, 500 * rs, (-360 * rs) + 120 * rs, "Resources/Pipe.png");
	obstacle.setLower(35 * rs, 360 * rs, 500 * rs, 180 * rs, "Resources/Pipe.png");
	
	Object overScreen(500 * rs, 500 * rs, 70 * rs, -70 * rs, "Resources/GameOver.png");

	bool gameover = false;

	while (!window.isClosed())
	{
		frameStart = SDL_GetTicks();
		if (obstacle.getUpX() < player1.getBody()._x && (obstacle.getUpX() + (35 * rs)) > player1.getBody()._x)
		{
			if (player1.getBody()._y < obstacle.getUpY() + obstacle.getUpH() || player1.getBody()._y > obstacle.getLowY())
			{
				gameover = true;
			}
		}

		if (gameover)
		{
			gameOVerPoll(window, rs);
		}
		else
		{
			pollEvents(window, player1, /*player2.*/ rs);
		}
		background.draw();
		Text text(Window::renderer, "Resources/arial.ttf", 30, scoreChar, { 30, 10, 10, 255 });
		text.display(20, 20, Window::renderer);
		player1.draw();
		obstacle.draw();
		obstacle.moving(rs, scoreInt);
		if (!gameover)
		{
			tools::intToScore(scoreInt, scoreChar);
		}
		else
		{
			overScreen.draw();
		}


		if (player1._hop)
		{
			player1.flying(rs);
		}
		else
		{
			player1.falling(rs);
		}

		window.clear();

		//if all the events ended before the end of the frame we delay until the end of the frame
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	return 0;
}