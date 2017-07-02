#pragma once
#ifndef __INITIAL_SCENE_H__
#define __INITIAL_SCENE_H__

#include "include/Objects/Scene.h"
#include "include/Objects/Sprite.h"
#include "include/Objects/AnimatedSprite.h"
#include <assert.h>
#include <string>
#define IMG_PATH "../Resources/tank.bmp"
#define IMG2_PATH "../Resources/img.bmp"

class InitialScene : public Scene
{
private:
	Sprite* movableTank;
	Node* parentNode1;
public:
	void updateScene(const Uint8* kbState, float dt);
	void updateTest();
	void drawPriorityTest();
	void animatedSpriteTest();
	static Scene* createScene();
	static InitialScene* create();
	virtual bool init();
};
 
#endif // !__INITIAL_SCENE_H__
