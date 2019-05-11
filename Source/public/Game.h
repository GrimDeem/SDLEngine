#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include <cstdint>

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
	void drawWorld();
	void clean();

	bool is_running;
	uint32_t frametimes[FRAME_VALUES]; // An array to store frame times
	uint32_t frametimelast;  // Last calculated SDL_GetTicks
	uint32_t framecount; 	   // total frames rendered
	float framespersecond;
	const float targetFrameTime = 33.f; // for 60 fps
};

#endif //!__GAME_H__
