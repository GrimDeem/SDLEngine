#include "InitialScene.h"

std::shared_ptr<InitialScene> InitialScene::create()
{
	auto pRet = std::make_shared<InitialScene>(InitialScene());
	if (pRet)
		if( pRet->init())
		return pRet;
	else
		assert(false);
}

bool InitialScene::init()
{
	FPSLabel = TextLabel::create(FONT_PATH, 26, "");
	FPSLabel->setPosition(100, 400);
	this->addChild(FPSLabel);
	
	auto spr = Sprite::create("../Resources/Sprites/BeardMan/idle1.png");
	spr->setPosition(20, 20);
	this->addChild(spr);

	animatedSpriteTest();
	aSpriteEvents();
	Keeper::getInstance().getCamera()->setTargetNode(aSprite);
	return true;
}

void InitialScene::update(float dt)
{
	Scene::update(dt);
	FPSLabel->setString(std::to_string(round(Keeper::getInstance().getFPS())));
}

void InitialScene::animatedSpriteTest()
{
	aSprite = AnimatedSprite::create();
	aSprite->setPosition(40, 40);
	aSprite->setScale(2);

	std::vector<SDL_Texture*> images;
	char str[256];
	for (int idx = 1; idx <= 5; idx++) {
		sprintf(str, "../Resources/Sprites/BeardMan/idle%d.png", idx);
		images.push_back(Keeper::getInstance().getTextureManager()->getTexture(str));
		LOG(("idle" + std::to_string(idx) + '\n').c_str());
	}
	aSprite->addAnimation("idle", images);
	aSprite->animateLooped("idle");

	images.clear();
	images.push_back(Keeper::getInstance().getTextureManager()->getTexture("../Resources/Sprites/BeardMan/attack1.png"));
	images.push_back(Keeper::getInstance().getTextureManager()->getTexture("../Resources/Sprites/BeardMan/attack2.png"));
	aSprite->addAnimation("attack", images);

	images.clear();
	images.push_back(Keeper::getInstance().getTextureManager()->getTexture("../Resources/Sprites/BeardMan/onhit1.png"));
	images.push_back(Keeper::getInstance().getTextureManager()->getTexture("../Resources/Sprites/BeardMan/onhit2.png"));
	aSprite->addAnimation("onhit", images);

	this->addChild(aSprite);

	KeyboardEventHolder test = KeyboardEventHolder();
	test.onKeyPressed([this](SDL_KeyboardEvent *key, float dt)
	{
		if (key->keysym.sym == SDLK_w) {
			aSprite->animate("attack", "idle");
		}
		if (key->keysym.sym == SDLK_s) {
			aSprite->animate("onhit", "idle");
		}
	});
	eventHandler.addKeyboardHolder(test);
}

void InitialScene::aSpriteEvents()
{
	KeyboardEventHolder moveWarrior = KeyboardEventHolder();
	moveWarrior.onKeyPressed([this](SDL_KeyboardEvent *key, float dt)
	{
		auto kbButton = key->keysym.sym;
		float speed = 10;
		if (kbButton == SDLK_w || kbButton == SDLK_UP) {
			aSprite->moveY(-speed);
		}
		else if (kbButton == SDLK_a || kbButton == SDLK_LEFT) {
			aSprite->moveX(-speed);
		}
		else if (kbButton == SDLK_s || kbButton == SDLK_DOWN) {
			aSprite->moveY(speed);
		}
		else if (kbButton == SDLK_d || kbButton == SDLK_RIGHT) {
			aSprite->moveX(speed);
		}
	});
	eventHandler.addKeyboardHolder(moveWarrior);
}
