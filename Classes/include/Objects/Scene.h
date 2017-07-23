#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include "Node.h"
#include "../Objects/Updatable.h"
#include <SDL.h>
#include <functional>

class Scene : public Node, public Updatable
{
protected:
	std::function<void(const Uint8*, float)> _update;
	virtual void insertChild(NodePtr child, int order, std::string key) override;

public:
	Scene() 
		: _update(nullptr)
	{}
	virtual ~Scene() {}

	virtual void removeChild(NodePtr childToRemove) override;
	virtual void update(float dt) override;
};

#endif // !__SCENE_H__
