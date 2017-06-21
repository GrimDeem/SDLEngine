#pragma once
#ifndef __UPDATABLE_H__
#define __UPDATABLE_H__

class Updatable
{
private:
	std::vector<Updatable*> updChilds;	//updatable
public:
	virtual ~Updatable() {}
	virtual void update(float dt)
	{
		for (auto &child : Updatable::getUpdatableChildren())
			child->update(dt);
	}
	
	virtual void removeChild(Node* childToRemove)
	{
		if (updChilds.empty())
			return;
		auto updChild = dynamic_cast<Updatable*>(childToRemove);
		if (updChild != nullptr) {
			auto iter = std::find(updChilds.begin(), updChilds.end(), updChild);
			if (iter != updChilds.end())
				updChilds.erase(iter);
		}
	}

	virtual void insertChild(Node * child)
	{
		auto updChild = dynamic_cast<Updatable*>(child);
		if (updChild != nullptr)
			updChilds.push_back(updChild);
	}

	virtual std::vector<Updatable*> getUpdatableChildren() const
	{
		return updChilds;
	}
};

#endif // !__IUPDATABLE_H__