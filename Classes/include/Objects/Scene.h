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
	virtual void insertChild(Node * child, int order, std::string key) override;
	std::function<void(const Uint8*, float)> _update;

public:
	Scene() 
		: _update(nullptr)
	{}
	virtual ~Scene() {}

	virtual void removeChild(Node* childToRemove) override;
	virtual void update(float dt) override;
};

#endif // !__SCENE_H__
