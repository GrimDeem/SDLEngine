#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include "Node.h"
#include "../Objects/Updatable.h"
#include <SDL.h>
#include <functional>

class Scene : public Node, public Updatable
{
public:
	std::function<void(const Uint8*, float)> _update;
	Scene() 
		: _update(nullptr)
	{}
	virtual ~Scene() {
		for (auto &child : Node::getDrawableChildren())
			delete child;
	}

	/*draw scene means draw all it children*/
	virtual void draw() override;
	virtual void removeChild(Node* childToRemove) override;
	virtual void insertChild(Node * child, int order) override;
	virtual void update(float dt) override;
};

#endif // !__SCENE_H__
