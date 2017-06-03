#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include <SDL_render.h>
#include <SDL_main.h>
#include "Managers\Keeper.h"
#include "Objects\Sprite.h"

//#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif 

#define WINDOW_TITLE "SDL_Game"
#define WINDOW_POSITION_X 200
#define WINDOW_POSITION_Y 200
#define WINDOW_SIZE_X 1366
#define WINDOW_SIZE_Y 768

class Game
{
public:
	Game();
	void run();
private:
	bool initSDL();
	void processEvents();
	void updateWorld(float dt);
	void draw();
	void clean();

	bool is_running;
	const float targetFrameTime = 66.6f; // for 30 fps
};

#endif //!__GAME_H__