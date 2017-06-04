#include "InitialScene.h"

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
	//initialize scene here
	Sprite* tank = new Sprite(IMG_PATH);
	tank->setPosition(Vec2(0, 0));
	tank->setScale(2);
	this->addChild(tank);

	return true;
}
