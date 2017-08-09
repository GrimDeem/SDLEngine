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
	std::shared_ptr<Sprite> movableTank;
	std::shared_ptr<TextLabel> FPSLabel;
public:
	static std::shared_ptr<InitialScene> create();
	virtual bool init();
	virtual void update(float dt) override;
	void updateScene(const Uint8* kbState, float dt);
	void updateTest();
	void drawPriorityTest();
	void animatedSpriteTest();
	void drawTextLabelTest();
	void flipsTest();
};

class AdditionalScene : public Scene
{
private:
	std::shared_ptr<TextLabel> FPSLabel;
	std::vector<std::shared_ptr<Sprite>> sprites;
public:
	static std::shared_ptr<AdditionalScene> AdditionalScene::create()
	{
		AdditionalScene *pRet = new(std::nothrow) AdditionalScene();
		if (pRet && pRet->init())
			return std::make_shared<AdditionalScene>(*pRet);
		else
			assert(false);
	}
	
	bool AdditionalScene::init()
	{
		auto kbHolder = KeyboardEventHolder();
		kbHolder.onKeyPressed(
			[](SDL_KeyboardEvent *key, float dt)
		{ 
			if (key->keysym.sym == SDLK_ESCAPE)
				exit(0);
		});
		eventHandler.addKeyboardHolder(kbHolder);
		
		FPSLabel = TextLabel::create(FONT_PATH, 40, "");
		FPSLabel->setPosition(100, 100);
		FPSLabel->setColor({ 255, 0, 0 });
		this->addChild(FPSLabel, 1);

		for (int i = 0; i <= 50000; i++) {
			auto sprite = Sprite::create(IMG2_PATH);
			sprite->setPosition(createSpritePos());
			sprite->setScale(0.1);
			sprites.push_back(sprite);
			this->addChild(sprite, -1);
		}
		return true;
	}

	virtual void AdditionalScene::update(float dt) override
	{
		for (auto sprite : sprites)
			sprite->setPosition(createSpritePos());
		FPSLabel->setString(std::to_string(round(Keeper::getInstance().getFPS())));
	}

	Vec2 createSpritePos() 
	{
		return Vec2(rand() % 1366, rand() % 768);
	}
};
 

#endif // !__INITIAL_SCENE_H__
