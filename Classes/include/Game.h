#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include <SDL_render.h>
#include <SDL_main.h>
#include <SDL_ttf.h>
#include "Managers/Keeper.h"
#include "../InitialScene.h"

#define FRAME_VALUES 10
class Game
{
public:
	Game();
	void run();
private:
	bool initSDL();
	void initFPS();
	float calcFPS();
	void processEvents(float dt);
	void updateWorld(float dt);
	void draw();
	void clean();

	bool is_running;
	Uint32 frametimes[FRAME_VALUES]; // An array to store frame times
	Uint32 frametimelast;  // Last calculated SDL_GetTicks
	Uint32 framecount; 	   // total frames rendered
	float framespersecond;
	const float targetFrameTime = 33.f; // for 60 fps
};

#endif //!__GAME_H__
