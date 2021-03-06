#include <iostream>
#include "Window.h"
#include "Rect.h"
#include "Text.h"
#include "Object.h"
#include "Player.h"
#include "Obstacle.h"
#include <string>
#include "tools.h"

void pollEvents(Window& window, Player& player1, float resolutionSetting)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event, resolutionSetting);
		player1.pollEvents(event, resolutionSetting);
	}
}

void gameOVerPoll(Window& window, float resolutionSetting)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event, resolutionSetting);
	}
}

void pollEventsForMenu(Window& window, Rect& menu)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event, 1);
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
	char scoreChar[4] = { '0', '\0', '\0','\0' };

	//Stuff needed to lock fps
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	//

	Window window("FlappyClone", 640 * rs, 360 * rs);
	Object background(640 * rs, 360 * rs, 0, 0, 100, 200, 255, 255);
	Object clouds1(633 * rs, 360 * rs, 0, 0, "Resources/clouds.png");
	Object clouds2(633 * rs, 360 * rs, 633 * rs, 0, "Resources/clouds2.png");

	Player player1;
	player1.setBody(18 * rs, 12 * rs, 80 * rs, 0, "Resources/DirpyBird.png");

	Obstacle obstacle;
	obstacle.setUpper(35 * rs, 360 * rs, 500 * rs, (-360 * rs) + 120 * rs, "Resources/Pipe.png");
	obstacle.setLower(35 * rs, 360 * rs, 500 * rs, 180 * rs, "Resources/Pipe.png");
	
	Object overScreen(200 * rs, 300 * rs, 220 * rs, 40 * rs, "Resources/OverMenu.png");

	bool gameover = false;

	int oldScore = 0;

	//Rect debug(71 * rs, 70 * rs, 241 * rs, 224 * rs, 255, 0, 0, 255);

	Text text(Window::renderer, "Resources/arial.ttf", 30, scoreChar, { 30, 10, 10, 255 });
	
	unsigned short int oneTimeOptimization = 0;
	
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
			pollEvents(window, player1, rs);
		}

		background.draw();
		clouds1.draw();
		clouds2.draw();
		{
			clouds1._x -= 1 * rs;
			clouds2._x -= 1 * rs;
			if (clouds1._x < -633 * rs)
			{
				clouds1._x = 633 * rs;
			}
			if (clouds2._x < -633 * rs)
			{
				clouds2._x = 633 * rs;
			}
		}

		player1.draw();
		obstacle.draw();
		obstacle.moving(rs, scoreInt);

		if (!gameover)
		{
			tools::intToScore(scoreInt, scoreChar);
			if (scoreInt != oldScore)
			{
				text.changeText(Window::renderer, "Resources/arial.ttf", 30, scoreChar, { 30, 10, 10, 255 });
				oldScore = scoreInt;
			}
			text.display(20, 20, Window::renderer);
		}
		else
		{
			window.setEndMenu(true);
			if (oneTimeOptimization == 0)
			{
				text.changeText(Window::renderer, "Resources/arial.ttf", 24 * rs, scoreChar, { 0, 0, 0, 255 });
				oneTimeOptimization++;
			}
			
			overScreen.draw();
			text.display(330 * rs, 157 * rs, Window::renderer);

			if (window.getRestart())
			{
				player1.setBody(18 * rs, 12 * rs, 80 * rs, 0, "Resources/DirpyBird.png");
				scoreChar[0] = '0';
				scoreChar[1] = '\0';
				scoreChar[2] = '\0';
				scoreChar[3] = '\0';
				scoreInt = 0;
				oneTimeOptimization = 0;
				gameover = false;
				window.setRestart(false);
			}
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