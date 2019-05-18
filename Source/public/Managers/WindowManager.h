#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include <WindowSettings.h>
#include <Core/Vec2.h>

class SDL_Window;

class WindowManager
{
private:
	SDL_Window* m_instance;
	Size m_windowSize;
	Vec2 m_position;
	std::string m_windowTitle;

private:
	void destroyWindow();

public:
	WindowManager(const WindowSettings& settings);
	~WindowManager();

	SDL_Window* createWindow();

	Size getWindowSize();
};

#endif // !WINDOW_MANAGER
