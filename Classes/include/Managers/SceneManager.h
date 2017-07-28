#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "../Objects/Scene.h"

/*SceneManager responsible for scene switching*/
class SceneManager
{
private:
	std::shared_ptr<Scene> currentScene;
public:
	SceneManager();
	~SceneManager() { }

	/*
	@brief replaces current scene with a passed new one
	 */
	void replaceScene(std::shared_ptr<Scene> newScene);
	
	void drawCurrentScene();

	void updateCurrentScene(float dt);
};

#endif // !__SCENE_MANAGER_H__
