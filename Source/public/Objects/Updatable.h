#pragma once
#ifndef __UPDATABLE_H__
#define __UPDATABLE_H__

#include <algorithm>
#include <Objects/Node.h>
/*
	Updatable is auxiliary class to describe objects
	which have to be updated each frame with delta time
	such as animated sprite
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
	std::vector<UpdatablePtr> m_updChilds;

protected:
	Updatable() = default;
	~Updatable() = default; //do not del or remove childs to avoid multiple del (node destructor)
	virtual void _removeChild(Node::NodePtr _childToRemove) {
		if (m_updChilds.empty())
			return;
		auto updChild = std::dynamic_pointer_cast<Updatable>(_childToRemove);
		if (updChild != nullptr) {
			auto iter = std::find(m_updChilds.begin(), m_updChilds.end(), updChild);
			if (iter != m_updChilds.end())
				m_updChilds.erase(iter);
		}
	}

	virtual void _insertChild(Node::NodePtr _child) {
		auto updChild = std::dynamic_pointer_cast<Updatable>(_child);
		if (updChild != nullptr)
			m_updChilds.push_back(updChild);
	}

public:
	virtual void update(float _dt) {
		for (auto &child : Updatable::getUpdatableChildren())
			child->update(_dt);
	}

	virtual const std::vector<UpdatablePtr>& getUpdatableChildren() const {
		return m_updChilds;
	}
};

#endif // !__IUPDATABLE_H__
