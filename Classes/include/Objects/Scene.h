#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include <functional>
#include <SDL.h>
#include <Objects/Node.h>
#include <Objects/Updatable.h>
#include <Input/EventHandler.h>

class Scene : public Node, public Updatable
{
protected:
	EventHandler m_eventHandler;
	std::function<void(const Uint8*, float)> m_update;

private:
	virtual void _insertChild(NodePtr _child, int _order, const std::string& _key) override;

public:
	Scene();
	static std::shared_ptr<Scene> create();
	virtual ~Scene() = default;

	virtual void removeChild(NodePtr _childToRemove) override;
	virtual void update(float _dt) override;

	virtual EventHandler& getEventHandler();
};

#endif // !__SCENE_H__
