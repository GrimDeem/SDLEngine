#include "../../include/Objects/Node.h"

Node::Node()
	: position(0,0)
	, scaleX(1)
	, scaleY(1)
	, drawOrder(0)
	, anchorPoint(0.5, 0.5)
	, parent(nullptr)
{
}


void Node::addChild(Node * child)
{
	this->addChild(child, 0);
}

void Node::addChild(Node * child, int _drawOrder)
{
	assert(child != nullptr);
	assert(child->parent == nullptr); //checks if child already added

	if (childs.empty())
	{
		childs.reserve(5);
	}

	this->insertChild(child, _drawOrder);
}

void Node::addParent(Node * _parent)
{
	parent = _parent;
}

std::vector<Node*> Node::getChildren() const
{
	return childs;
}

Node * Node::getParent() const
{
	return parent;
}

void Node::removeFromParent()
{
	if (parent != nullptr)
	{
		parent->removeChild(this);
	}
}

void Node::removeChild(Node * childToRemove)
{
	if (childs.empty())
	{
		return;
	}

	size_t index;

	auto iter = std::find(childs.begin(), childs.end(), childToRemove);
	if (iter != childs.end())
		index = iter - childs.begin();
	else {
		index = -1;
		return;
	}

	assert(!childs.empty() && index >= 0 && index < childs.size());
	auto it = std::next(childs.begin(), index);
	childs.erase(it);
}

void Node::insertChild(Node * child, int order)
{
	childs.push_back(child);
	child->setDrawOrder(order);
}

void Node::setPosition(Vec2 _position)
{
	position = _position;
}

void Node::setPosition(float x, float y)
{
	position = Vec2(x, y);
}

Vec2 Node::getPosition() const
{
	return position;
}

float Node::getPositionX()
{
	return position.x;
}

float Node::getPositionY()
{
	return position.y;
}

void Node::setScaleX(float _scaleX)
{
	scaleX = _scaleX;
}

void Node::setScaleY(float _scaleY)
{
	scaleY = _scaleY;
}

void Node::setScale(float _scale)
{
	this->setScaleX(_scale);
	this->setScaleY(_scale);
}

float Node::getScale() const
{
	assert(scaleX == scaleY);
	return scaleX;
}

float Node::getScaleX() const
{
	return scaleX;
}

float Node::getScaleY() const
{
	return scaleY;
}

void Node::setDrawOrder(int order)
{
	drawOrder = order;
}

int Node::getDrawOrder() const
{
	return drawOrder;
}
