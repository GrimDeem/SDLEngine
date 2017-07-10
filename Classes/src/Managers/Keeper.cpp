#include "../../include/Managers/Keeper.h"

Keeper::Keeper()
	: renderer(nullptr)
	, window(nullptr)
{
	texManager = new TextureManager();
	sceneManager = new SceneManager();
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
	assert(_renderer != nullptr);
	renderer = _renderer;
}

SDL_Renderer* Keeper::getRenderer()
{
	assert(renderer != nullptr);
	return renderer;
}

void Keeper::initWindow(SDL_Window * _window)
{
	assert(_window != nullptr);
	window = _window;
}

void Keeper::replaceScene(Scene * newScene)
{
	sceneManager->replaceScene(newScene);
}

void Keeper::drawCurrentScene()
{
	sceneManager->drawCurrentScene();
}

void Keeper::updateCurrentScene( float dt)
{
	sceneManager->updateCurrentScene(dt);
}

void Keeper::end()
{
	delete texManager;
	delete sceneManager;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
}
