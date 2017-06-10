#pragma once
#ifndef __INITIAL_SCENE_H__
#define __INITIAL_SCENE_H__

#include "include\Objects\Scene.h"
#include "include\Objects\Sprite.h"

class InitialScene : public Scene
{
private:
	Sprite* movableTank;
public:
	void updateScene(const Uint8* kbState, float dt);
	static Scene* createScene();
	static InitialScene* create();
	virtual bool init();
};
 
#endif // !__INITIAL_SCENE_H__
