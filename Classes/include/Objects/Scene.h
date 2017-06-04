#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include "Node.h"

class Scene : public Node
{
private:

public:
	Scene() {}
	virtual ~Scene() {
		for (auto &child : Node::getChildren())
			delete child;
	}
	/*draw scene means draw all it children*/
	virtual void draw() override;
};

#endif // !__SCENE_H__
