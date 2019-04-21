#include <algorithm>
#include <cassert>

#include <Core/GlobalDefines.h>
#include <Objects/Node.h>
#include <Managers/Keeper.h>

Node::Node()
	: m_position(0,0)
	, m_scaleX(1)
	, m_scaleY(1)
	, m_rotation(0)
	, m_drawOrder(0)
	, m_anchorPoint(0.5, 0.5)
	, m_flip(false, false)
	, m_nodeKey("")
	, m_needsSortFlag(true)
{}

Node::~Node() {
	this->removeFromParent();
};

Node::NodePtr Node::create() {
	return std::make_shared<Node>();
}

void Node::draw() {
	if (this->m_needsSortFlag == true) {
		std::sort(m_drwChilds.begin(), m_drwChilds.end(), [&](NodePtr first, NodePtr second) {
			return first->getDrawOrder() < second->getDrawOrder();
		});
		this->m_needsSortFlag = false;
	}
	for_each_child(&Node::draw);
}

void Node::update(float _dt) {
	for_each_child(&Node::update, _dt);
}

void Node::addChild(NodePtr _child) {
	this->addChild(_child, 0, "");
}

void Node::addChild(NodePtr _child, int _drawOrder) {
	Node::addChild(_child, _drawOrder, "");
}

void Node::addChild(NodePtr _child, int _drawOrder, const std::string& _key) {
	assert(_child != nullptr);
	assert(_child->getParent() == nullptr);

	this->_insertChild(_child, _drawOrder, _key);
}

const std::vector<Node::NodePtr>& Node::getDrawableChildren() const {
	return m_drwChilds;
}

void Node::removeChildren() {
	for_each_child(&Node::_setParent, nullptr);
	m_drwChilds.clear();
}

void Node::destroyChildrenRecursive() {
	for_each_child(&Node::destroyChildrenRecursive);
	removeChildren();
}

Node::NodePtr Node::getParent() const {
	if (auto ptr = m_parent.lock())
		return ptr;
	else
		return nullptr;
}

void Node::_setParent(NodePtr _parent) {
	m_parent = _parent;
}

void Node::removeFromParent() {
	auto pPtr = m_parent.lock();
	if (pPtr != nullptr)
		pPtr->removeChild(shared_from_this());
}

void Node::removeChild(NodePtr _childToRemove) {
	if (m_drwChilds.empty())
		return;

	auto iter = std::find(m_drwChilds.begin(), m_drwChilds.end(), _childToRemove);
	if (iter != m_drwChilds.end()) {
		(*iter)->_setParent(nullptr);
		m_drwChilds.erase(iter);
	}
}

Node::NodePtr Node::getChildByKey(const std::string& _childKey) const {
	if (!_childKey.empty()) {
		auto iter = std::find_if(m_drwChilds.begin(), m_drwChilds.end(),
			[_childKey](Node::NodePtr child)
		{
			return child->getNodeKey() == _childKey;
		});
		if (iter != m_drwChilds.end())
			return *iter;
	}
	return nullptr;
}

void Node::_insertChild(NodePtr _child, int _order, const std::string& _key) {
	m_drwChilds.push_back(_child);
	_child->setNodeKey(_key);
	_child->setDrawOrder(_order);
	_child->_setParent(shared_from_this());
	this->needsSort();
}

void Node::setPosition(const Vec2& _position) {
	m_position = _position;
}

void Node::setPosition(float _x, float _y) {
	m_position = Vec2(_x, _y);
}

const Vec2& Node::getPosition() const {
	return m_position;
}

float Node::getPositionX() const {
	return m_position.x;
}

float Node::getPositionY() const {
	return m_position.y;
}

void Node::setScaleX(float _scaleX) {
	m_scaleX = _scaleX;
}

void Node::setScaleXRecursive(float _scaleX) {
	m_scaleX = _scaleX;
	for_each_child(&Node::setScaleXRecursive, _scaleX);
}

void Node::setScaleY(float _scaleY) {
	m_scaleY = _scaleY;
}

void Node::setScaleYRecursive(float _scaleY) {
	m_scaleY = _scaleY;
	for_each_child(&Node::setScaleYRecursive, _scaleY);
}

void Node::setScale(float _scale) {
	this->setScaleX(_scale);
	this->setScaleY(_scale);
}

void Node::setScaleRecursive(float _scale) {
	this->setScaleXRecursive(_scale);
	this->setScaleYRecursive(_scale);
}

void Node::setScale(float _scaleX, float _scaleY) {
	this->setScaleX(_scaleX);
	this->setScaleY(_scaleY);
}

void Node::setScaleRecursive(float _scaleX, float _scaleY) {
	this->setScaleXRecursive(_scaleX);
	this->setScaleYRecursive(_scaleY);
}

float Node::getScale() const {
	assert(m_scaleX == m_scaleY);
	return m_scaleX;
}

float Node::getScaleX() const {
	return m_scaleX;
}

float Node::getScaleY() const {
	return m_scaleY;
}

void Node::setDrawOrder(int _order) {
	m_drawOrder = _order;
	auto pPtr = m_parent.lock();
	if(pPtr != nullptr)
		pPtr->needsSort();
}

int Node::getDrawOrder() const {
	return m_drawOrder;
}

void Node::setKey(const std::string& _key) {
	m_nodeKey = _key;
}

void Node::setAnchorPoint(const Vec2& _newAnchorPoint) {
	assert(_newAnchorPoint.x <= 1 && _newAnchorPoint.x >= 0
		&& _newAnchorPoint.y <= 1 && _newAnchorPoint.y >= 0);
	m_anchorPoint = _newAnchorPoint;
}

void Node::setAnchorPoint(float _anchorX, float _anchorY) {
	assert(_anchorX <= 1 && _anchorX >= 0 && _anchorY <= 1 && _anchorY >= 0);
	m_anchorPoint = Vec2(_anchorX, _anchorY);
}

const Vec2& Node::getAnchorPoint() const {
	return m_anchorPoint;
}

void Node::setRotation(float _angle) {
	m_rotation = _angle;
}

void Node::setRotationRecursive(float _angle) {
	this->setRotation(_angle);
	for_each_child(&Node::setRotationRecursive, _angle);
}

float Node::getRotation() const {
	return m_rotation;
}

void Node::flipVertical() {
	m_flip.vertical = !m_flip.vertical;
}
void Node::flipHorisontal() {
	m_flip.horisontal = !m_flip.horisontal;
}

const FlipState& Node::getFlipState() const {
	return m_flip;
}

void Node::setFlipState(const FlipState& _newFlipState) {
	m_flip = _newFlipState;
}

void Node::setNodeKey(const std::string& _key) {
	this->m_nodeKey = _key;
}

const std::string& Node::getNodeKey() const {
	return m_nodeKey;
}

void Node::move(const Vec2& _delta) {
	m_position = m_position + _delta;
}

void Node::move(float _deltaX, float _deltaY) {
	Node::move(Vec2(_deltaX, _deltaY));
}

void Node::moveX(float _deltaX) {
	Node::move(Vec2(_deltaX, 0));
}

void Node::moveY(float _deltaY) {
	Node::move(Vec2(0, _deltaY));
}

void Node::moveRecursive(float _deltaX, float _deltaY) {
	Node::move(Vec2(_deltaX, _deltaY));
	for_each_child(&Node::moveRecursive, _deltaX, _deltaY);
}

void Node::needsSort() {
	this->m_needsSortFlag = true;
}
