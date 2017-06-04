#include "InitialScene.h"
#define IMG_PATH "../Resources/tank.bmp"
#define IMG2_PATH "../Resources/img.bmp"

Scene * InitialScene::createScene()
{
	Scene* scene = new Scene();
	auto init = InitialScene::create();
	scene->addChild(init);
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
	//write testCode here
	Node* parentNode1 = new Node(); 
	{
		//initialize scene here
		Sprite* tank = new Sprite(IMG_PATH);
		tank->setPosition(Vec2(100, 100));
		tank->setRotation(270);
		tank->setScale(2);
		parentNode1->addChild(tank, 1);

		Sprite* tank2 = new Sprite(IMG_PATH);
		tank2->setPosition(Vec2(100, 200));
		tank2->setRotation(270);
		tank2->setScale(2);
		parentNode1->addChild(tank2, 1);

		Sprite* linux = new Sprite(IMG_PATH);
		linux->setPosition(Vec2(100, 150));
		linux->setScale(1.0f / 2);
		parentNode1->addChild(linux, 1);
	}

	Node* parentNode2 = new Node();
	{
		//initialize scene here
		Sprite* tank = new Sprite(IMG2_PATH);
		tank->setPosition(Vec2(100, 100));
		tank->setRotation(270);
		tank->setScale(2);
		parentNode2->addChild(tank, -1);

		Sprite* tank2 = new Sprite(IMG2_PATH);
		tank2->setPosition(Vec2(100, 200));
		tank2->setRotation(270);
		tank2->setScale(2);
		parentNode2->addChild(tank2, -1);

		Sprite* linux = new Sprite(IMG2_PATH);
		linux->setPosition(Vec2(100, 150));
		linux->setScale(1.0f / 2);
		parentNode2->addChild(linux, -1);

	}

	this->addChild(parentNode1, 0);
	this->addChild(parentNode2, -1);
	return true;
}
