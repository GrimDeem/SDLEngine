#pragma once
#ifndef __INITIAL_SCENE_H__
#define __INITIAL_SCENE_H__

#include "include\Objects\Scene.h"
#include "include\Objects\Sprite.h"

#define IMG_PATH "../Resources/tank.bmp"

class InitialScene : public Scene
{
private:
public:
	static Scene* createScene();
	static InitialScene* create();
	virtual bool init();
};
 
#endif // !__INITIAL_SCENE_H__
