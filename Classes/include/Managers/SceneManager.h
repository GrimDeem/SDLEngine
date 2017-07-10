#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "../Objects/Scene.h"

/*SceneManager responsible for scene switching*/
class SceneManager
{
private:
	Scene* currentScene;
public:
	SceneManager();
	~SceneManager() {
		delete currentScene;
	}

	/*replaces current scene with a passed new one*/
	void replaceScene(Scene* newScene);
	
	void drawCurrentScene();

	void updateCurrentScene(float dt);
};

#endif // !__SCENE_MANAGER_H__
