#pragma once
#ifndef __UPDATABLE_H__
#define __UPDATABLE_H__

#include "Objects/Node.h"
/*
	Updatable is auxiliary class to describe objects
	which have to be updated each frame with delta time
	sush as animated sprite
	Methods of the "updatable" class should be called in overridden 
	methods of the derived classes with similar "Node" methods 
	to avoid memory leaks

	Updatable can contain other updatable objects (insertChild) 
*/
class Updatable
{
public:
	typedef std::shared_ptr<Updatable> UpdatablePtr;
private:
	std::vector<UpdatablePtr> updChilds;

protected:
	Updatable() {}
	~Updatable() {} //do not del or remove childs to avoid multiple del (node destructor)
	virtual void removeChild(Node::NodePtr childToRemove)
	{
		if (updChilds.empty())
			return;
		auto updChild = std::dynamic_pointer_cast<Updatable>(childToRemove);
		if (updChild != nullptr) {
			auto iter = std::find(updChilds.begin(), updChilds.end(), updChild);
			if (iter != updChilds.end())
				updChilds.erase(iter);
		}
	}

	virtual void insertChild(Node::NodePtr child)
	{
		auto updChild = std::dynamic_pointer_cast<Updatable>(child);
		if (updChild != nullptr)
			updChilds.push_back(updChild);
	}

public:
	virtual void update(float dt)
	{
		for (auto &child : Updatable::getUpdatableChildren())
			child->update(dt);
	}

	virtual const std::vector<UpdatablePtr> getUpdatableChildren() const
	{
		return updChilds;
	}
};

#endif // !__IUPDATABLE_H__
