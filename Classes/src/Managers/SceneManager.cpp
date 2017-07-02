#include "../../include/Managers/SceneManager.h"

SceneManager::SceneManager():
	currentScene(nullptr)
{
}

void SceneManager::replaceScene(Scene* newScene)
{
	assert(newScene != nullptr);
	delete currentScene;
	currentScene = newScene;
}

void SceneManager::drawCurrentScene()
{
	assert(currentScene != nullptr);
	currentScene->draw();
}

void SceneManager::updateCurrentScene(float dt)
{
	currentScene->update(dt);
}
