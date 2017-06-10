#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include "Node.h"
#include <SDL.h>
#include <functional>

class Scene : public Node
{
protected:
public:

	std::function<void(const Uint8*, float)> _update;
	Scene() 
		: _update(nullptr)
	{}
	virtual ~Scene() {
		for (auto &child : Node::getChildren())
			delete child;
	}
	/*draw scene means draw all it children*/
	virtual void draw() override;
	virtual void update(float dt);
};

#endif // !__SCENE_H__
