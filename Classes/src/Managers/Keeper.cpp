#include "..\..\include\Managers\Keeper.h"

Keeper::Keeper()
{
	renderer = nullptr;
	window = nullptr;
	texManager = new TextureManager();
	currentScene = nullptr;
}

Keeper & Keeper::getInstance()
{
	static Keeper inst;
	return inst;
}

TextureManager* Keeper::getTextureManager()
{
	return texManager;
}

void Keeper::initRenderer(SDL_Renderer* _renderer)
{
	if (renderer == nullptr) {
		assert(_renderer != nullptr);
		renderer = _renderer;
	}
}

SDL_Renderer* Keeper::getRenderer()
{
	assert(renderer != nullptr);
	return renderer;
}

void Keeper::initWindow(SDL_Window * _window)
{
	if (window == nullptr) {
		assert(_window != nullptr);
		window = _window;
	}
}

void Keeper::replaceScene(Scene* newScene)
{
	assert(newScene != nullptr);
	currentScene = newScene;

}

void Keeper::drawCurrentScene()
{
	assert(currentScene != nullptr);
	currentScene->draw();
}

void Keeper::end()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
