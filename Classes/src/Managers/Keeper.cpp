#include "Managers/Keeper.h"

Keeper::Keeper()
	: renderer(nullptr)
	, framerate(0)
{
	winManager = new WindowManager();
	texManager = new TextureManager();
	sceneManager = new SceneManager();
	camera = new Camera(winManager->getWindowSize());
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

WindowManager * Keeper::getWindowManager()
{
	return winManager;
}

SceneManager * Keeper::getSceneManager()
{
	return sceneManager;
}

void Keeper::replaceCurrentScene(std::shared_ptr<Scene> newScene)
{
	sceneManager->replaceCurrentScene(newScene);
}

void Keeper::runFirstScene(std::shared_ptr<Scene> newScene)
{
	sceneManager->runFirstScene(newScene);
}

EventHandler Keeper::getEventHandler()
{
	return sceneManager->getCurrentSceneEventHandler();
}

void Keeper::drawCurrentScene()
{
	sceneManager->drawCurrentScene();
}

void Keeper::updateCurrentScene(float dt)
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

Camera* Keeper::getCamera()
{
	return camera;
}

void Keeper::end()
{
	delete camera;
	delete sceneManager;
	delete texManager;
	delete winManager;

	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
}
