#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include <functional>
#include <SDL.h>
#include <Objects/Node.h>
#include <Input/EventHandler.h>

class Scene : public Node
{
protected:
	EventHandler m_eventHandler;
	std::function<void(const Uint8*, float)> m_update;

public:
	Scene();
	static std::shared_ptr<Scene> create();
	virtual ~Scene() = default;

	virtual void onUpdate(float _dt) override;

	virtual EventHandler& getEventHandler();
};

#endif // !__SCENE_H__
