#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include <unordered_map>
#include "Objects/Scene.h"

/*SceneManager is entity responsible for scene switching and storage*/
class SceneManager
{
private:

	std::shared_ptr<Scene> currentScene;
	std::shared_ptr<Scene> nextScene;
	std::unordered_map<std::string, std::shared_ptr<Scene> > scenePool;
public:
	SceneManager();
	~SceneManager() {
		scenePool.clear();
	}

	/*
	@brief returns shared_ptr to current scene
	*/
	EventHandler getCurrentSceneEventHandler();

	/*
	@brief use only for first scene
	 */
	void runFirstScene(std::shared_ptr<Scene> newScene);

	/*
	@brief adds scene to poll with tag
	 */
	void addSceneToPool(std::string sceneTag, std::shared_ptr<Scene> newScene);
	
	/*
	@brief search scene by tag in scene pool and return shared_ptr on it
	 */
	std::shared_ptr<Scene> getSceneFromPool(std::string sceneTag);

	/*
	@brief remove scene with passed tag from pool (if it exists)
	 */
	void removeSceneFromPool(std::string sceneTag);
	
	/*
	@brief remove passed scene from pool (if it exists)
	*/
	void removeSceneFromPool(std::shared_ptr<Scene> sceneToRemove);

	/*
	@brief replaces current scene with a passed new one
	 */
	void replaceCurrentScene(std::shared_ptr<Scene> newScene);
	
	void drawCurrentScene();
	void updateCurrentScene(float dt);

	const std::unordered_map<std::string, std::shared_ptr<Scene>> getScenePool();
};

#endif // !__SCENE_MANAGER_H__
