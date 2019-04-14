#include <SDL_render.h>

#include <Managers/WindowManager.h>

WindowManager::WindowManager() {
	m_windowSize = Size(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	m_position = Vec2(WINDOW_POSITION_X, WINDOW_POSITION_Y);
}

WindowManager::~WindowManager() {
	destroyWindow();
}

SDL_Window * WindowManager::createWindow() {
	m_instance = SDL_CreateWindow(
		WINDOW_TITLE,
		WINDOW_POSITION_X,
		WINDOW_POSITION_Y,
		WINDOW_SIZE_X,
		WINDOW_SIZE_Y,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	return m_instance;
}

Size WindowManager::getWindowSize() {
	return m_windowSize;
}

void WindowManager::destroyWindow() {
	SDL_DestroyWindow(m_instance);
}
