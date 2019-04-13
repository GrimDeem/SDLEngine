#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include <unordered_map>
#include <Objects/Scene.h>

/*SceneManager is entity responsible for scene switching and storage*/
class SceneManager
{
private:
	std::shared_ptr<Scene> m_currentScene;
	std::shared_ptr<Scene> m_nextScene;
	std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenePool;

public:
	SceneManager();
	~SceneManager();

	/*
	@brief returns event handler of current scene
	*/
	EventHandler getCurrentSceneEventHandler();

	/*
	@brief use only for first scene
	 */
	void runFirstScene(std::shared_ptr<Scene> _newScene);

	/*
	@brief adds scene to pool with tag
	 */
	void addSceneToPool(const std::string& _sceneTag, std::shared_ptr<Scene> _newScene);
	
	/*
	@brief search scene by tag in scene pool and return shared_ptr on it
	 */
	std::shared_ptr<Scene> getSceneFromPool(const std::string& _sceneTag);

	/*
	@brief remove scene with passed tag from pool (if it exists)
	 */
	void removeSceneFromPool(const std::string& _sceneTag);
	
	/*
	@brief remove passed scene from pool (if it exists)
	*/
	void removeSceneFromPool(std::shared_ptr<Scene> _sceneToRemove);

	/*
	@brief replaces current scene with a passed new one
	 */
	void replaceCurrentScene(std::shared_ptr<Scene> _newScene);
	
	void drawCurrentScene();
	void updateCurrentScene(float _dt);

	const std::unordered_map<std::string, std::shared_ptr<Scene>> getScenePool();
};

#endif // !__SCENE_MANAGER_H__
