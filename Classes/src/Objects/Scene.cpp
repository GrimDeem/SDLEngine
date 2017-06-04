#include "..\..\include\Objects\Scene.h"

void Scene::draw()
{
	//todo: sort children by priority (discending)
	for (auto &child : Node::getChildren())
		child->draw();
}
