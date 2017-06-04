#pragma once
#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include <algorithm>
#include <cassert>
#include "../Core/Vec2.h"

/*	Node is the base element of the Scene Graph. 
	Elements of the Scene Graph must be Node objects or subclasses of it.

	Node can contain other node objects (addChild)	
*/
class Node
{
private:
	Vec2 position;

	float scaleX;
	float scaleY;

	Vec2 anchorPoint;
	int drawOrder;

	std::vector<Node*> childs;
	Node* parent;
public:
	Node();
	virtual ~Node() {};

	virtual void draw();

	virtual void addChild(Node* child);
	virtual void addChild(Node* child, int _drawOrder);
	virtual void addParent(Node* _parent);

	virtual std::vector<Node*> getChildren() const;
	virtual Node* getParent() const;

	virtual void removeFromParent();
	virtual void removeChild(Node* childToRemove);
	virtual void insertChild(Node* child, int order);

	virtual void setPosition(Vec2 _position);
	virtual void setPosition(float _x, float _y);
	virtual Vec2 getPosition() const;
	virtual float getPositionX();
	virtual float getPositionY();

	virtual void setScaleX(float _scaleX);
	virtual void setScaleY(float _scaleY);
	virtual void setScale(float _scale);	
	virtual float getScale() const;
	virtual float getScaleX() const;
	virtual float getScaleY() const;

	virtual void setDrawOrder(int order);
	virtual int getDrawOrder() const;

	virtual void setAnchorPoint(Vec2 newAnchorPoint);
	virtual void setAnchorPoint(float anchorX, float anchorY);
	virtual Vec2 getAnchorPoint();
};

#endif //!__NODE_H__