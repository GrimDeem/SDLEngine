#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include "Core/Vec2.h"
#include <SDL_render.h>

#define WINDOW_TITLE "SDL_Game"
#define WINDOW_POSITION_X 200
#define WINDOW_POSITION_Y 200
#define WINDOW_SIZE_X 1366
#define WINDOW_SIZE_Y 768

class WindowManager
{
private:
	SDL_Window* instance;
	Size windowSize;
	Vec2 position;

private:
	void destroyWindow();

public:
	WindowManager();
	~WindowManager();

	SDL_Window* createWindow();

	Size getWindowSize();
};

#endif // !WINDOW_MANAGER
