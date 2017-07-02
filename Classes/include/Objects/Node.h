#pragma once
#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include "../Core/GlobalDefines.h"
#include "../Core/Vec2.h"

/*	Node is the base element of the Scene Graph. 
	Elements of the Scene Graph must be Node objects or subclasses of it.

	Node is drawable object
	Node can contain other node objects (addChild)	
*/
class Node
{
private:
	Vec2 position;

	float scaleX;
	float scaleY;

	float rotation;

	Vec2 anchorPoint;
	int drawOrder;

	std::vector<Node*> drwChilds;
	Node* parent;

	std::string nodeKey;

protected:
	virtual void setParent(Node* _parent);
	virtual void insertChild(Node* child, int order, std::string key);

public:
	Node();
	virtual ~Node() {
		this->removeFromParent();
		for (auto &child : Node::getDrawableChildren())
			delete child;
	};

	virtual void draw();

	virtual void addChild(Node* child);
	virtual void addChild(Node* child, int _drawOrder);
	virtual void addChild(Node* child, int _drawOrder, std::string key);

	virtual std::vector<Node*> getDrawableChildren() const;
	virtual Node* getParent() const;

	virtual void removeFromParent();
	virtual void removeChild(Node* childToRemove);

	virtual void setPosition(Vec2 _position);
	virtual void setPosition(float _x, float _y);
	virtual Vec2 getPosition() const;
	virtual float getPositionX();
	virtual float getPositionY();

	virtual void setScaleX(float _scaleX);
	virtual void setScaleXRecursive(float _scaleX);
	virtual void setScaleY(float _scaleY);
	virtual void setScaleYRecursive(float _scaleY);
	virtual void setScale(float _scale);
	virtual void setScaleRecursive(float _scale);
	virtual void setScale(float _scaleX, float _scaleY);
	virtual void setScaleRecursive(float _scaleX, float _scaleY);

	virtual float getScale() const;
	virtual float getScaleX() const;
	virtual float getScaleY() const;

	virtual void setDrawOrder(int order);
	virtual int getDrawOrder() const;

	virtual void setAnchorPoint(Vec2 newAnchorPoint);
	virtual void setAnchorPoint(float anchorX, float anchorY);
	virtual Vec2 getAnchorPoint();

	/*sets rotation of the sprite clockwise in degrees */
	virtual void setRotation(float angle);
	virtual void setRotationRecursive(float angle);
	virtual float getRotation();

	virtual void setNodeKey(std::string _key);
	virtual std::string getNodeKey();
};

#endif //!__NODE_H__
