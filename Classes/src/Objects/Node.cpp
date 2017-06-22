#include "../../include/Objects/Node.h"

Node::Node()
	: position(0,0)
	, scaleX(1)
	, scaleY(1)
	, drawOrder(0)
	, anchorPoint(0.5, 0.5)
	, parent(nullptr)
	, nodeKey("")
{
}

void Node::draw()
{
	std::sort(drwChilds.begin(), drwChilds.end(), [&](Node *first, Node *second) {
		return first->getDrawOrder() < second->getDrawOrder();
	});
	for (auto &child : Node::getDrawableChildren())
		child->draw();
}

void Node::addChild(Node * child)
{
	this->addChild(child, 0);
}

void Node::addChild(Node * child, int _drawOrder)
{
	Node::addChild(child, _drawOrder, "");
}

void Node::addChild(Node * child, int _drawOrder, std::string key)
{
	assert(child != nullptr);
	assert(child->parent == nullptr);
	
	if (drwChilds.empty())
		drwChilds.reserve(5);

	this->insertChild(child, _drawOrder);
}

std::vector<Node*> Node::getDrawableChildren() const
{
	return drwChilds;
}

Node * Node::getParent() const
{
	return parent;
}

void Node::setParent(Node* _parent)
{
	assert(_parent != nullptr);
	parent = _parent;
}

void Node::removeFromParent()
{
	if (parent != nullptr)
		parent->removeChild(this);
}

void Node::removeChild(Node * childToRemove)
{
	if (drwChilds.empty())
		return;

	auto iter = std::find(drwChilds.begin(), drwChilds.end(), childToRemove);
	if (iter != drwChilds.end()) {
		drwChilds.erase(iter);
		childToRemove->setParent(nullptr);
	}
}

void Node::insertChild(Node * child, int order, std::string key)
{
	drwChilds.push_back(child);
	child->setNodeKey(key);
	child->setDrawOrder(order);
	child->setParent(this);
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

void Node::setAnchorPoint(Vec2 newAnchorPoint)
{
	assert(newAnchorPoint.x <= 1 && newAnchorPoint.x >= 0
		&& newAnchorPoint.y <= 1 && newAnchorPoint.y >= 0);
	anchorPoint = newAnchorPoint;
}

void Node::setAnchorPoint(float anchorX, float anchorY)
{
	assert(anchorX <= 1 && anchorX >= 0 && anchorY <= 1 && anchorY >= 0);
	anchorPoint = Vec2(anchorX, anchorY);
}

Vec2 Node::getAnchorPoint()
{
	return anchorPoint;
}

void Node::setNodeKey(std::string _key)
{
	this->nodeKey = _key;
}

std::string Node::getNodeKey()
{
	return nodeKey;
}
