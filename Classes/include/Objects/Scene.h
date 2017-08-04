#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include <functional>
#include <SDL.h>
#include "Node.h"
#include "Updatable.h"
#include "../Input/EventHandler.h"

class Scene : public Node, public Updatable
{
protected:
	EventHandler eventHandler;
	std::function<void(const Uint8*, float)> _update;
	virtual void insertChild(NodePtr child, int order, std::string key) override;

public:
	Scene() 
		: _update(nullptr)
	{}
	static std::shared_ptr<Scene> create();
	virtual ~Scene() {}

	virtual void removeChild(NodePtr childToRemove) override;
	virtual void update(float dt) override;

	virtual EventHandler getEventHandler();
};

#endif // !__SCENE_H__
