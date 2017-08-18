#include "../../include/Managers/SceneManager.h"

SceneManager::SceneManager()
	: currentScene(nullptr)
	, nextScene(nullptr)
{
}

EventHandler SceneManager::getCurrentSceneEventHandler()
{
	return currentScene->getEventHandler();
}

void SceneManager::runFirstScene(std::shared_ptr<Scene> newScene)
{
	assert(newScene != nullptr);
	currentScene = newScene;
}

void SceneManager::replaceCurrentScene(std::shared_ptr<Scene> newScene)
{
	assert(newScene != nullptr);
	nextScene = newScene;
}

void SceneManager::addSceneToPool(std::string sceneTag, std::shared_ptr<Scene> newScene)
{
	assert(newScene != nullptr && !sceneTag.empty());
	scenePool.insert(std::make_pair(sceneTag, newScene));
}

std::shared_ptr<Scene> SceneManager::getSceneFromPool(std::string sceneTag)
{
	if (!sceneTag.empty()) {
		auto it = scenePool.find(sceneTag);
		if (it != scenePool.end())
			return scenePool.at(sceneTag);
	}
	assert(false); //scene with this tag not finded
	return nullptr; 
}

void SceneManager::removeSceneFromPool(std::string sceneTag)
{
	assert(!sceneTag.empty());
	auto it = scenePool.find(sceneTag);
	if (it != scenePool.end())
		scenePool.erase(sceneTag);
}

void SceneManager::removeSceneFromPool(std::shared_ptr<Scene> sceneToRemove)
{
	assert(sceneToRemove != nullptr);
	auto it = std::find_if(scenePool.begin(), scenePool.end(),
		[&sceneToRemove](const std::unordered_map<std::string, std::shared_ptr<Scene>>::value_type& value)
	{
		return value.second == sceneToRemove;
	});
	if (it != scenePool.end())
		removeSceneFromPool(it->first);
}

void SceneManager::drawCurrentScene()
{
	assert(currentScene != nullptr);
	currentScene->draw();
}

void SceneManager::updateCurrentScene(float dt)
{
	assert(currentScene != nullptr);
	currentScene->update(dt);
	
	if (nextScene != nullptr) {
		currentScene = nextScene;
		nextScene = nullptr;
	}		
}

const std::unordered_map<std::string, std::shared_ptr<Scene>> SceneManager::getScenePool()
{
	return scenePool;
}
