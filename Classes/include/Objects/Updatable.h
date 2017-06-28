#pragma once
#ifndef __UPDATABLE_H__
#define __UPDATABLE_H__

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
private:
	std::vector<Updatable*> updChilds;	//updatable
protected:
	Updatable() {}
public:
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