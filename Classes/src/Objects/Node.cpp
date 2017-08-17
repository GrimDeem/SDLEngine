#include "../../include/Objects/Node.h"

Node::Node()
	: position(0,0)
	, scaleX(1)
	, scaleY(1)
	, rotation(0)
	, drawOrder(0)
	, anchorPoint(0.5, 0.5)
	, flip(false, false)
	, nodeKey("")
	, needsSortFlag(true)
{
}

Node::NodePtr Node::create()
{
	return std::make_shared<Node>();
}

void Node::draw()
{
	if (this->needsSortFlag == true) {
		std::sort(drwChilds.begin(), drwChilds.end(), [&](NodePtr first, NodePtr second) {
			return first->getDrawOrder() < second->getDrawOrder();
		});
		this->needsSortFlag = false;
	}
	for (auto &child : Node::getDrawableChildren())
		child->draw();
}

void Node::addChild(NodePtr child)
{
	this->addChild(child, 0, "");
}

void Node::addChild(NodePtr child, int _drawOrder)
{
	Node::addChild(child, _drawOrder, "");
}

void Node::addChild(NodePtr child, int _drawOrder, std::string key)
{
	assert(child != nullptr);
	assert(child->getParent() == nullptr);

	this->insertChild(child, _drawOrder, key);
}

const std::vector<Node::NodePtr> Node::getDrawableChildren() const
{
	return drwChilds;
}

void Node::removeChildren()
{
	for (auto child : drwChilds)
		child->setParent(nullptr);
	drwChilds.clear();
}

void Node::destroyChildrenRecursive()
{
	for (auto child : drwChilds)
		destroyChildrenRecursive();
	removeChildren();
}

Node::NodePtr Node::getParent() const
{
	if (auto ptr = parent.lock())
		return ptr;
	else
		return nullptr;
}

void Node::setParent(NodePtr _parent)
{
	parent = _parent;
}

void Node::removeFromParent()
{
	auto pPtr = parent.lock();
	if (pPtr != nullptr)
		pPtr->removeChild(shared_from_this());
}

void Node::removeChild(NodePtr childToRemove)
{
	if (drwChilds.empty())
		return;

	auto iter = std::find(drwChilds.begin(), drwChilds.end(), childToRemove);
	if (iter != drwChilds.end()) {
		(*iter)->setParent(nullptr);
		drwChilds.erase(iter);
	}
}

Node::NodePtr Node::getChildByKey(std::string childKey) const
{
	if (!childKey.empty()) {
		auto iter = std::find_if(drwChilds.begin(), drwChilds.end(), 
			[childKey](Node::NodePtr child)
		{
			return child->getNodeKey() == childKey;
		});
		if (iter != drwChilds.end())
			return *iter;
	}
	return nullptr;
}

void Node::insertChild(NodePtr child, int order, std::string key)
{
	drwChilds.push_back(child);
	child->setNodeKey(key);
	child->setDrawOrder(order);
	child->setParent(shared_from_this());
	this->needsSort();
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

float Node::getPositionX() const
{
	return position.x;
}

float Node::getPositionY() const
{
	return position.y;
}

void Node::setScaleX(float _scaleX)
{
	scaleX = _scaleX;
}

void Node::setScaleXRecursive(float _scaleX)
{
	scaleX = _scaleX;
	for (auto &child : Node::getDrawableChildren())
		child->setScaleXRecursive(_scaleX);
}

void Node::setScaleY(float _scaleY)
{
	scaleY = _scaleY;
}

void Node::setScaleYRecursive(float _scaleY)
{
	scaleY = _scaleY;
	for (auto &child : Node::getDrawableChildren())
		child->setScaleYRecursive(_scaleY);
}

void Node::setScale(float _scale)
{
	this->setScaleX(_scale);
	this->setScaleY(_scale);
}

void Node::setScaleRecursive(float _scale)
{
	this->setScaleXRecursive(_scale);
	this->setScaleYRecursive(_scale);
}

void Node::setScale(float _scaleX, float _scaleY)
{
	this->setScaleX(_scaleX);
	this->setScaleY(_scaleY);
}

void Node::setScaleRecursive(float _scaleX, float _scaleY)
{
	this->setScaleXRecursive(_scaleX);
	this->setScaleYRecursive(_scaleY);
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
	auto pPtr = parent.lock();
	if(pPtr != nullptr)
		pPtr->needsSort();
}

int Node::getDrawOrder() const
{
	return drawOrder;
}

void Node::setKey(std::string key)
{
	nodeKey = key;
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

Vec2 Node::getAnchorPoint() const
{
	return anchorPoint;
}

void Node::setRotation(float angle)
{
	rotation = angle;
}

void Node::setRotationRecursive(float angle)
{
	this->setRotation(angle);
	for (auto &child : Node::getDrawableChildren())
		child->setRotationRecursive(angle);
}

float Node::getRotation() const
{
	return rotation;
}

void Node::flipVertical()
{
	flip.vertical = !flip.vertical;
}
void Node::flipHorisontal()
{
	flip.horisontal = !flip.horisontal;
}

FlipState Node::getFlipState() const
{
	return flip;
}

void Node::setFlipState(FlipState _newFlipState)
{
	flip = _newFlipState;
}

void Node::setNodeKey(std::string _key)
{
	this->nodeKey = _key;
}

std::string Node::getNodeKey() const
{
	return nodeKey;
}

void Node::move(Vec2 delta)
{
	position = position + delta;
}

void Node::move(float deltaX, float deltaY)
{
	Node::move(Vec2(deltaX, deltaY));
}

void Node::moveX(float deltaX)
{
	Node::move(Vec2(deltaX, 0));
}

void Node::moveY(float deltaY)
{
	Node::move(Vec2(0, deltaY));
}
       
void Node::moveRecursive(float deltaX, float deltaY)
{
	Node::move(Vec2(deltaX, deltaY));
	for (auto &child : Node::getDrawableChildren())
		child->moveRecursive(deltaX, deltaY);
}

void Node::needsSort()
{
	this->needsSortFlag = true;
}
