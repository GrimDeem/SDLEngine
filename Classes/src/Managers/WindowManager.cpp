#include "Managers/WindowManager.h"

WindowManager::WindowManager()
{
	windowSize = Size(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	position = Vec2(WINDOW_POSITION_X, WINDOW_POSITION_Y);
}

WindowManager::~WindowManager()
{
	destroyWindow();
}

SDL_Window * WindowManager::createWindow()
{
	instance = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POSITION_X,
		WINDOW_POSITION_Y,
		WINDOW_SIZE_X,
		WINDOW_SIZE_Y,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	return instance;
}

Size WindowManager::getWindowSize()
{
	return windowSize;
}

void WindowManager::destroyWindow()
{
	SDL_DestroyWindow(instance);
}

