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
	std::shared_ptr<AnimatedSprite> aSprite;
	std::shared_ptr<TextLabel> FPSLabel;
public: 
	static std::shared_ptr<InitialScene> create();
	virtual bool init();
	virtual void update(float dt) override;

	void animatedSpriteTest();
	void aSpriteEvents();
}; 

#endif // !__INITIAL_SCENE_H__
