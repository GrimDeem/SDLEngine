#include "../../include/Objects/Scene.h"
#include <iostream>

void Scene::removeChild(NodePtr childToRemove)
{
	Node::removeChild(childToRemove);
	Updatable::removeChild(childToRemove);
}

void Scene::insertChild(NodePtr child, int order, std::string key)
{
	Node::insertChild(child, order, key);
	Updatable::insertChild(child);
}

void Scene::update(float dt)
{
	if (_update != nullptr) {
		const Uint8* state = SDL_GetKeyboardState(NULL);
		try {
			_update(state, dt);
		}
		catch (const std::bad_function_call& e) {
			std::cout << e.what() << '\n';
		}
	}
	Updatable::update(dt);
}
