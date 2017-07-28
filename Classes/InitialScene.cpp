#include "InitialScene.h"

Scene * InitialScene::createScene()
{
	Scene* scene = InitialScene::create();
	return scene;
}

InitialScene * InitialScene::create()
{
	InitialScene *pRet = new(std::nothrow) InitialScene(); 
	if (pRet && pRet->init())
		return pRet; 
	else 
	{ 
		delete pRet; 
		return nullptr; 
	}
}

bool InitialScene::init()
{
	this->setKey("Scene");
	
	FPSLabel = TextLabel::create(FONT_PATH, 26, "");
	FPSLabel->setPosition(100, 400);
	this->addChild(FPSLabel);

	//animatedSpriteTest();
	updateTest();
	//drawPriorityTest();
	//drawTextLabelTest();
	//flipsTest();
	return true;
}

void InitialScene::update(float dt)
{
	Scene::update(dt);
}

void InitialScene::drawTextLabelTest()
{
	auto label = TextLabel::create(FONT_PATH, 26, "Felt");
	label->setPosition(Vec2(100,100));
	label->setFontPath("../Resources/Fonts/MarkerFelt.ttf");
	label->setColor({0, 255, 133});
	label->setAnchorPoint(Vec2(0,0));
	
	this->addChild(label, 0);
	
	auto label2 = std::make_shared<TextLabel> ("../Resources/Fonts/Kurale.ttf", 26, "Kurale");
	label2->setPosition(Vec2(170,100));
	this->addChild(label2, 0);
}

void InitialScene::updateScene(const Uint8* kbState, float dt)
{
	float speed = 0.1;
	if (kbState[SDL_SCANCODE_RIGHT] || kbState[SDL_SCANCODE_D]) {
		movableTank->moveX(dt * speed);
	} else if (kbState[SDL_SCANCODE_LEFT] || kbState[SDL_SCANCODE_A]) {
		movableTank->moveX(-dt * speed);
	}
	if (kbState[SDL_SCANCODE_UP] || kbState[SDL_SCANCODE_W]) {
		movableTank->moveY(-dt * speed);
	} else  if (kbState[SDL_SCANCODE_DOWN] || kbState[SDL_SCANCODE_S]) {
		movableTank->moveY(dt * speed);
	}
	FPSLabel->setString(std::to_string(round(Keeper::getInstance().getFPS())));
}

void InitialScene::updateTest()
{
	movableTank = Sprite::create("../Resources/Sprites/TimAnimation/TimRun0.png");
	movableTank->setPosition(Vec2(60, 70));
	this->addChild(movableTank, 1, "movableTank");

	_update = std::bind(&InitialScene::updateScene, this, std::placeholders::_1, std::placeholders::_2);
}

void InitialScene::drawPriorityTest()
{
	auto parentNode1 = Node::create();
	{
		auto tank = Sprite::create(IMG_PATH);
		tank->setPosition(Vec2(100, 100));
		tank->setRotation(270);
		tank->setScale(2);
		parentNode1->addChild(tank, 1, "tank");

		auto tank2 = Sprite::create(IMG_PATH);
		tank2->setPosition(Vec2(100, 200));
		tank2->setRotation(270);
		tank2->setScale(2);
		parentNode1->addChild(tank2, 1, "tank2");

		auto tank3 = Sprite::create(IMG_PATH);
		tank3->setPosition(Vec2(100, 150));
		tank3->setScale(1.0f / 2);
		parentNode1->addChild(tank3, 1, "tank3");
	}

	auto parentNode2 = Node::create();
	{
		auto linux = Sprite::create(IMG2_PATH);
		linux->setPosition(Vec2(100, 100));
		linux->setRotation(180);
		linux->setScale(0.5);
		parentNode2->addChild(linux, -1, "linux");

		auto linux2 = Sprite::create(IMG2_PATH);
		linux2->setPosition(Vec2(100, 200));
		linux2->setRotation(180);
		linux2->setScale(0.5);
		parentNode2->addChild(linux2, -1, "linux2");
		
		auto tank = Sprite::create(IMG_PATH);
		tank->setPosition(Vec2(100, 150));
		tank->setScale(2);
		parentNode2->addChild(tank, -1, "tank");
	}

	this->addChild(parentNode1, 0, "parentNode1");
	this->addChild(parentNode2, -1, "parentNode2");
}

void InitialScene::animatedSpriteTest()
{
	auto anim = AnimatedSprite::create();
	anim->setPosition(Vec2(200, 200));
	std::vector<SDL_Texture*> images;
	char str[256];
	for (int idx = 0; idx < 27; idx++) {
		sprintf(str, "../Resources/Sprites/TimAnimation/TimRun%d.png", idx);
		images.push_back(Keeper::getInstance().getTextureManager()->getTexture(str));
		LOG(("TimRun" + std::to_string(idx) + '\n').c_str());
	}
	AnimData data;
	data.images = images;
	data.frameInfo.push_back(AnimFrameData(1, 27));
	anim->initalize(data, 0);
	anim->flipHorisontal();
	anim->setAnimFPS(40);
	
	this->addChild(anim, 0, "animated");
}

void InitialScene::flipsTest()
{
        //todo: fix bug (if draw labels first assertion failed and one of sprites is not drawing) wt?!
	auto tank = Sprite::create(IMG_PATH);
	tank->setPosition(Vec2(100, 100));
	this->addChild(tank, 0, "tank");

	auto tank2 = Sprite::create(IMG_PATH);
	tank2->setPosition(Vec2(100, 200));
	tank2->flipHorisontal();
	this->addChild(tank2, 1, "tank2");

	auto tank3 = Sprite::create(IMG_PATH);
	tank3->setPosition(Vec2(100, 150));
      	this->addChild(tank3, 0, "tank3");		
	
	auto labelDefault = TextLabel::create("../Resources/Fonts/Kurale.ttf", 26, "Kurale");
	labelDefault->setPosition(Vec2(170,60));
	this->addChild(labelDefault, 0);
	
	auto labelFlippedV = TextLabel::create("../Resources/Fonts/Kurale.ttf", 26, "Kurale");
	labelFlippedV->setPosition(Vec2(170,100));
	labelFlippedV->flipVertical();
	this->addChild(labelFlippedV, 0);
		
	auto labelFlippedH = TextLabel::create("../Resources/Fonts/Kurale.ttf", 26, "Kurale");
	labelFlippedH->setPosition(Vec2(170,140));
	labelFlippedH->flipHorisontal();
	this->addChild(labelFlippedH, 0);
}
