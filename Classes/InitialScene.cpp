#include "InitialScene.h"
#include <assert.h>
#define IMG_PATH "../Resources/tank.bmp"
#define IMG2_PATH "../Resources/img.bmp"

Scene * InitialScene::createScene()
{
	Scene* scene = InitialScene::create();
	/*auto init = 
	scene->addChild(init);*/
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
		parentNode1->addChild(tank, 1, "tank");

		Sprite* tank2 = new Sprite(IMG_PATH);
		tank2->setPosition(Vec2(100, 200));
		tank2->setRotation(270);
		tank2->setScale(2);
		parentNode1->addChild(tank2, 1, "tank2");

		Sprite* tank3 = new Sprite(IMG_PATH);
		tank3->setPosition(Vec2(100, 150));
		tank3->setScale(1.0f / 2);
		parentNode1->addChild(tank3, 1, "tank3");
	}

	Node* parentNode2 = new Node();
	{
		//initialize scene here
		Sprite* linux = new Sprite(IMG2_PATH);
		linux->setPosition(Vec2(100, 100));
		linux->setRotation(270);
		linux->setScale(2);
		parentNode2->addChild(linux, -1, "linux");

		Sprite* linux2 = new Sprite(IMG2_PATH);
		linux2->setPosition(Vec2(100, 200));
		linux2->setRotation(270);
		linux2->setScale(2);
		parentNode2->addChild(linux2, -1, "linux2");
		
		movableTank = new Sprite(IMG_PATH);
		movableTank->setPosition(Vec2(100, 150));
		movableTank->setScale(1.0f / 2);
		parentNode2->addChild(movableTank, -1, "Movlinux");


	}
	this->addChild(parentNode1, 0, "parentNode1");
	this->addChild(parentNode2, -1, "parentNode2");

	delete parentNode1;
	_update = std::bind(&InitialScene::updateScene, this, std::placeholders::_1, std::placeholders::_2);;
	return true;
}

void InitialScene::updateScene(const Uint8* kbState, float dt)
{
	float speed = 0.1;
	if (kbState[SDL_SCANCODE_RIGHT]) {
		movableTank->setPosition(movableTank->getPositionX() + dt * speed, movableTank->getPositionY());
		std::cout << "SDL_SCANCODE_RIGHT" << std::endl;
	} else if (kbState[SDL_SCANCODE_LEFT]) {
		movableTank->setPosition(movableTank->getPositionX() - dt * speed, movableTank->getPositionY());
		std::cout << "SDL_SCANCODE_LEFT" << std::endl;
	}
	if (kbState[SDL_SCANCODE_UP]) {
		movableTank->setPosition(movableTank->getPositionX(), movableTank->getPositionY() - dt * speed);
		std::cout << "SDL_SCANCODE_UP" << std::endl;
	} else  if (kbState[SDL_SCANCODE_DOWN]) {
		movableTank->setPosition(movableTank->getPositionX(), movableTank->getPositionY() + dt * speed);
		std::cout << "SDL_SCANCODE_DOWN" << std::endl;
	}

}