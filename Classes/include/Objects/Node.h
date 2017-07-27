#pragma once
#ifndef __NODE_H__
#define __NODE_H__ 

#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <memory>
#include <SDL.h>
#include "../Core/GlobalDefines.h"
#include "../Core/Vec2.h"

/*	Node is the base element of the Scene Graph. 
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
private:
	Vec2 position;

	float scaleX;
	float scaleY;

	float rotation;

	FlipState flip;
	Vec2 anchorPoint;
	int drawOrder;

	std::vector<NodePtr> drwChilds;
	Node* parent;

	std::string nodeKey;

protected:
	virtual void setParent(Node* _parent);
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

	virtual std::vector<NodePtr> getDrawableChildren() const;
	virtual Node* getParent() const;

	virtual void removeFromParent();
	virtual void removeChild(NodePtr childToRemove);

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

	virtual void setKey(std::string key);

	virtual void setAnchorPoint(Vec2 newAnchorPoint);
	virtual void setAnchorPoint(float anchorX, float anchorY);
	virtual Vec2 getAnchorPoint();

	/*sets rotation of the sprite clockwise in degrees */
	virtual void setRotation(float angle);
	virtual void setRotationRecursive(float angle);
	virtual float getRotation();

	virtual void flipVertical();
	virtual void flipHorisontal();
	virtual FlipState getFlipState();
	virtual void setFlipState(FlipState _newFlipState);

	virtual void setNodeKey(std::string _key);
	virtual std::string getNodeKey();

	virtual void move(Vec2 delta);
	virtual void move(float deltaX, float deltaY);
	virtual void moveX(float deltaX);
	virtual void moveY(float deltaY);
	virtual void moveRecursive(float deltaX, float deltaY);		
};

#endif //!__NODE_H__
