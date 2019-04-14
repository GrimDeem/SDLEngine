#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include <Core/Vec2.h>

// load this data from config
#define WINDOW_TITLE "SDL_Game"
#define WINDOW_POSITION_X 200
#define WINDOW_POSITION_Y 200
#define WINDOW_SIZE_X 1366
#define WINDOW_SIZE_Y 768

class SDL_Window;

class WindowManager
{
private:
	SDL_Window* m_instance;
	Size m_windowSize;
	Vec2 m_position;

private:
	void destroyWindow();

public:
	WindowManager();
	~WindowManager();

	SDL_Window* createWindow();

	Size getWindowSize();
};

#endif // !WINDOW_MANAGER
