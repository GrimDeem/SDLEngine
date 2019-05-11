#pragma once
#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include <string>
#include <memory>
#include <SDL.h>
#include <Core/Vec2.h>

/*
	Node is the base element of the Scene Graph.
	Elements of the Scene Graph must be Node objects or subclasses of it.

	Node is drawable object
	Node can contain other node objects (addChild)
*/

struct FlipState
{
	bool vertical;
	bool horisontal;

	FlipState()
	: vertical(false)
	, horisontal(false)
	{ }

	FlipState(bool _vertical, bool _horisontal)
	: vertical(_vertical)
	, horisontal(_horisontal)
	{ }

	SDL_RendererFlip getSDLFlip() const
	{
		SDL_RendererFlip flip;
		if(vertical == false && horisontal == false)
			flip = SDL_FLIP_NONE;
		else if(vertical == true  && horisontal == false)
			flip = SDL_FLIP_VERTICAL;
		else if(vertical == false && horisontal == true )
			flip = SDL_FLIP_HORIZONTAL;
		else if(vertical == true  && horisontal == true )
			flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
		return flip;
	}
};

class Node : public std::enable_shared_from_this<Node>
{
public:
	typedef std::shared_ptr<Node> NodePtr;
	typedef std::weak_ptr<Node> ParentPtr;
private:
	Vec2 m_position;

	float m_scaleX;
	float m_scaleY;

	float m_rotation;

	FlipState m_flip;
	Vec2 m_anchorPoint;
	int m_drawOrder;
	bool m_needsSortFlag;

	std::vector<NodePtr> m_drwChilds;
	ParentPtr m_parent;

	std::string m_nodeKey;

protected:
	virtual void _setParent(NodePtr _parent);
	virtual void _insertChild(NodePtr _child, int _order, const std::string& _key);

	template<typename Fun, typename... Types>
	void for_each_child(Fun _function, Types... _args)
	{
		for (auto &child : Node::getDrawableChildren()) {
			(child.get()->*_function)(_args...);
		}
	}

public:
	Node();
	static NodePtr create();
	virtual ~Node();

	virtual void draw();
	virtual void update(float _dt);

	virtual void addChild(NodePtr _child);
	virtual void addChild(NodePtr _child, int _drawOrder);
	virtual void addChild(NodePtr _child, int _drawOrder, const std::string& _key);

	virtual const std::vector<NodePtr>& getDrawableChildren() const;
	virtual Node::NodePtr getParent() const;
	virtual void removeChildren();
	virtual void destroyChildrenRecursive();

	virtual void removeFromParent();
	virtual void removeChild(NodePtr _childToRemove);

	virtual NodePtr getChildByKey(const std::string& _childKey) const;

	virtual void setPosition(const Vec2& _position);
	virtual void setPosition(float _x, float _y);
	virtual const Vec2& getPosition() const;
	virtual float getPositionX() const;
	virtual float getPositionY() const;

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

	virtual void setDrawOrder(int _order);
	virtual int getDrawOrder() const;

	virtual void setAnchorPoint(const Vec2& _newAnchorPoint);
	virtual void setAnchorPoint(float _anchorX, float _anchorY);
	virtual const Vec2& getAnchorPoint() const;

	/*sets rotation of the sprite clockwise in degrees */
	virtual void setRotation(float _angle);
	virtual void setRotationRecursive(float _angle);
	virtual float getRotation() const;

	virtual void flipVertical();
	virtual void flipHorisontal();
	virtual const FlipState& getFlipState() const;
	virtual void setFlipState(const FlipState& _newFlipState);

	virtual void setNodeKey(const std::string& _key);
	virtual const std::string& getNodeKey() const;

	virtual void move(const Vec2& _delta);
	virtual void move(float _deltaX, float _deltaY);
	virtual void moveX(float _deltaX);
	virtual void moveY(float _deltaY);
	virtual void moveRecursive(float _deltaX, float _deltaY);

	virtual void needsSort();
};

#endif //!__NODE_H__
