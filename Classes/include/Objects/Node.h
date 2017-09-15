#pragma once
#ifndef __NODE_H__
#define __NODE_H__ 

#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <memory>
#include <SDL.h>
#include "Core/GlobalDefines.h"
#include "Core/Vec2.h"

/*	Node is the base element of the Scene Graph. 
	Elements of the Scene Graph must be Node objects or subclasses of it.

	Node is drawable object
	Node can contain other node objects (addChild)	
*/

//class Camera;

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
	
	SDL_RendererFlip getSDLFlip()
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
	Vec2 position;

	float scaleX;
	float scaleY;

	float rotation;

	FlipState flip;
	Vec2 anchorPoint;
	int drawOrder;
	bool needsSortFlag;

	std::vector<NodePtr> drwChilds;
	ParentPtr parent;

	std::string nodeKey;

protected:
	virtual void setParent(NodePtr _parent);
	virtual void insertChild(NodePtr child, int order, std::string key);

public:
	Node();
	static NodePtr create();
	virtual ~Node() {
		this->removeFromParent();
	};

	virtual void draw();

	virtual void addChild(NodePtr child);
	virtual void addChild(NodePtr child, int _drawOrder);
	virtual void addChild(NodePtr child, int _drawOrder, std::string key);

	virtual const std::vector<NodePtr> getDrawableChildren() const;
	virtual Node::NodePtr getParent() const;
	virtual void removeChildren();
	virtual void destroyChildrenRecursive();

	virtual void removeFromParent();
	virtual void removeChild(NodePtr childToRemove);

	virtual NodePtr getChildByKey(std::string childKey) const;

	virtual void setPosition(Vec2 _position);
	virtual void setPosition(float _x, float _y);
	virtual Vec2 getPosition() const;
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

	virtual void setDrawOrder(int order);
	virtual int getDrawOrder() const;

	virtual void setKey(std::string key);

	virtual void setAnchorPoint(Vec2 newAnchorPoint);
	virtual void setAnchorPoint(float anchorX, float anchorY);
	virtual Vec2 getAnchorPoint() const;

	/*sets rotation of the sprite clockwise in degrees */
	virtual void setRotation(float angle);
	virtual void setRotationRecursive(float angle);
	virtual float getRotation() const;

	virtual void flipVertical();
	virtual void flipHorisontal();
	virtual FlipState getFlipState() const;
	virtual void setFlipState(FlipState _newFlipState);

	virtual void setNodeKey(std::string _key);
	virtual std::string getNodeKey() const;

	virtual void move(Vec2 delta);
	virtual void move(float deltaX, float deltaY);
	virtual void moveX(float deltaX);
	virtual void moveY(float deltaY);
	virtual void moveRecursive(float deltaX, float deltaY);		

	virtual void needsSort();
};

#endif //!__NODE_H__
