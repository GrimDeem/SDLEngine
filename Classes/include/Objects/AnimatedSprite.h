#pragma once
#ifndef __ANIMATED_SPRITE_H__
#define __ANIMATED_SPRITE_H__

#include "Sprite.h"
#include "Updatable.h"

struct AnimFrameData
{
	AnimFrameData(int _startFrame, int _numFrames)
	{
		startFrame = _startFrame;
		numFrames = _numFrames;
	}
	// index of the start frame of an animation
	int startFrame;
	// total number of frames for said animation
	int numFrames;
};

struct AnimData
{
	// array of images for all the animations
	std::vector<Sprite*> images;
	// frame data for all the different animations
	std::vector<AnimFrameData> frameInfo;
};

class AnimatedSprite : public Node, public Updatable
{
private:
	Sprite image;
	// All of the animation data (includes ImageFiles and FrameData)
	AnimData animData;
	// The particular animation that is active
	int animNum;
	// The frame number of the active animation that's being displayed
	int frameNum;
	// Amount of time the current frame has been displayed
	float frameTime;
	// The FPS the animation is running at (24FPS by default).
	float animFPS;
public:
	AnimatedSprite();
	virtual ~AnimatedSprite();

	virtual void draw();
	virtual void update(float deltaTime) override;
	virtual void initalize(AnimData data, int startingAnimNum);
	virtual void changeAnim(int newAnimNum);

	virtual void removeChild(Node * child) override;
	virtual void insertChild(Node * child) override;

	
};

#endif // !__ANIMATED_SPRITE_H__
