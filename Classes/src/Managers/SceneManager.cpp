#include "Managers/SceneManager.h"

SceneManager::SceneManager()
	: m_currentScene(nullptr)
	, m_nextScene(nullptr)
{}

SceneManager::~SceneManager()
{
	m_scenePool.clear();
}

EventHandler SceneManager::getCurrentSceneEventHandler()
{
	return m_currentScene->getEventHandler();
}

void SceneManager::runFirstScene(std::shared_ptr<Scene> _newScene)
{
	assert(_newScene != nullptr);
	m_currentScene = _newScene;
}

void SceneManager::replaceCurrentScene(std::shared_ptr<Scene> _newScene)
{
	assert(_newScene != nullptr);
	m_nextScene = _newScene;
}

void SceneManager::addSceneToPool(const std::string& _sceneTag, std::shared_ptr<Scene> _newScene)
{
	assert(_newScene != nullptr && !_sceneTag.empty());
	m_scenePool.insert(std::make_pair(_sceneTag, _newScene));
}

std::shared_ptr<Scene> SceneManager::getSceneFromPool(const std::string& _sceneTag)
{
	if (!_sceneTag.empty()) {
		auto it = m_scenePool.find(_sceneTag);
		if (it != m_scenePool.end())
			return m_scenePool.at(_sceneTag);
	}
	assert(false); //scene with this tag not finded
	return nullptr; 
}

void SceneManager::removeSceneFromPool(const std::string& _sceneTag)
{
	assert(!_sceneTag.empty());
	auto it = m_scenePool.find(_sceneTag);
	if (it != m_scenePool.end())
		m_scenePool.erase(_sceneTag);
}

void SceneManager::removeSceneFromPool(std::shared_ptr<Scene> _sceneToRemove)
{
	assert(_sceneToRemove != nullptr);
	auto it = std::find_if(m_scenePool.begin(), m_scenePool.end(),
		[&_sceneToRemove](const std::unordered_map<std::string, std::shared_ptr<Scene>>::value_type& value)
	{
		return value.second == _sceneToRemove;
	});
	if (it != m_scenePool.end())
		removeSceneFromPool(it->first);
}

void SceneManager::drawCurrentScene()
{
	assert(m_currentScene != nullptr);
	m_currentScene->draw();
}

void SceneManager::updateCurrentScene(float _dt)
{
	assert(m_currentScene != nullptr);
	m_currentScene->update(_dt);
	
	if (m_nextScene != nullptr) {
		m_currentScene = m_nextScene;
		m_nextScene = nullptr;
	}		
}

const std::unordered_map<std::string, std::shared_ptr<Scene>> SceneManager::getScenePool()
{
	return m_scenePool;
}
