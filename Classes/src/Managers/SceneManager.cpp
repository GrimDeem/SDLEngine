#include "../../include/Managers/SceneManager.h"

SceneManager::SceneManager():
	currentScene(nullptr)
{
}

void SceneManager::replaceScene(std::shared_ptr<Scene> newScene)
{
	assert(newScene != nullptr);
	currentScene = newScene;
}

void SceneManager::drawCurrentScene()
{
	currentScene->draw();
}

void SceneManager::updateCurrentScene(float dt)
{
	currentScene->update(dt);
}
