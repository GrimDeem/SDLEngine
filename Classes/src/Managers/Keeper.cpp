#include "../../include/Managers/Keeper.h"

Keeper::Keeper()
	: renderer(nullptr)
	, window(nullptr)
	, framerate(0)
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

SDL_Window * Keeper::getWindow()
{
	return window;
}

void Keeper::replaceScene(std::shared_ptr<Scene> newScene)
{
	auto scene = std::make_shared<Scene>(*newScene);
	sceneManager->replaceScene(scene);
}

void Keeper::drawCurrentScene()
{
	sceneManager->drawCurrentScene();
}

void Keeper::updateCurrentScene( float dt)
{
	sceneManager->updateCurrentScene(dt);
}

void Keeper::setFPS(float fps)
{
	framerate = fps;
}

float Keeper::getFPS()
{
	return framerate;
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
