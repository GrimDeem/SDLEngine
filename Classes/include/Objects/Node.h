#pragma once
#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include <cassert>
#include "../Core/Vec2.h"

class Node
{
private:
	Vec2 position;
	//todo: size?

	float scaleX;
	float scaleY;

	Vec2 anchorPoint;
	int drawOrder;

	std::vector<Node*> childs;
	Node* parent;
public:
	Node();
	virtual ~Node() {};

	virtual void draw() = 0;

	virtual void addChild(Node* child);
	virtual void addChild(Node* child, int _drawOrder);
	virtual void addParent(Node* _parent);

	virtual std::vector<Node*> getChildren();
	virtual Node* getParent();

	virtual void removeFromParent();
	virtual void removeChild(Node* childToRemove);
	virtual void insertChild(Node* child, int order);

	//todo: get/set size
	virtual void setPosition(Vec2 _position);
	virtual void setPosition(float _x, float _y);
	virtual Vec2 getPosition();

	virtual void setScaleX(float _scaleX);
	virtual void setScaleY(float _scaleY);
	virtual void setScale(float _scale);	
	virtual float getScale();
	virtual float getScaleX();
	virtual float getScaleY();

	virtual void setDrawOrder(int order);
	virtual int getDrawOrder();
};

#endif //!__NODE_H__