#include <Core/GlobalDefines.h>
#include "Objects/Scene.h"

Scene::Scene()
	: m_update(nullptr)
{}

std::shared_ptr<Scene> Scene::create() {
	return std::make_shared<Scene>();
}

void Scene::removeChild(NodePtr _childToRemove) {
	Node::removeChild(_childToRemove);
	Updatable::_removeChild(_childToRemove);
}

void Scene::_insertChild(NodePtr _child, int _order, const std::string& _key) {
	Node::_insertChild(_child, _order, _key);
	Updatable::_insertChild(_child);
}

void Scene::update(float _dt) {
	if (m_update != nullptr) {
		const Uint8* state = SDL_GetKeyboardState(NULL);
		try {
			m_update(state, _dt);
		}
		catch (const std::bad_function_call& e) {
			LOG(e.what());
		}
	}
	Updatable::update(_dt);
}

EventHandler& Scene::getEventHandler() {
	return m_eventHandler;
}
