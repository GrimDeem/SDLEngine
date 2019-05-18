#include <iostream>
#include <SDL_render.h>
#include <Managers/WindowManager.h>

WindowManager::WindowManager(const WindowSettings& settings) {
	m_windowTitle = settings.getTitle();
	m_windowSize = Size(settings.getSizeX(), settings.getSizeY());
	m_position = Vec2(settings.getPositionX(), settings.getPositionY());
}

WindowManager::~WindowManager() {
	destroyWindow();
}

SDL_Window * WindowManager::createWindow() {
	m_instance = SDL_CreateWindow(
		m_windowTitle.c_str(),
		m_position.x,
		m_position.y,
		m_windowSize.width,
		m_windowSize.height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	std::cout << m_windowTitle.c_str() << " "
				<< m_position.x << " "
				<< m_position.y << " "
				<< m_windowSize.width << " "
				<< m_windowSize.height << " " << std::endl;
	return m_instance;
}

Size WindowManager::getWindowSize() {
	return m_windowSize;
}

void WindowManager::destroyWindow() {
	SDL_DestroyWindow(m_instance);
}
