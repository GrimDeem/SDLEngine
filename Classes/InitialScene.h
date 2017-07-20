#pragma once
#ifndef __INITIAL_SCENE_H__
#define __INITIAL_SCENE_H__ 

#include "include/Objects/Scene.h"
#include "include/Objects/Sprite.h"
#include "include/Objects/TextLabel.h"
#include "include/Objects/AnimatedSprite.h"

#include <assert.h>
#include <string>
#define IMG_PATH  "../Resources/Sprites/tank.bmp"
#define IMG2_PATH "../Resources/Sprites/linux.bmp"
#define FONT_PATH "../Resources/Fonts/DroidSans.ttf"

class InitialScene : public Scene
{
private:
	Sprite* movableTank;
public:
	static Scene* createScene();
	static InitialScene* create();
	virtual bool init();

	void updateScene(const Uint8* kbState, float dt);
	void updateTest();
	void drawPriorityTest();
	void animatedSpriteTest();
	void drawTextLabelTest();
	void flipsTest();
};
 
#endif // !__INITIAL_SCENE_H__

