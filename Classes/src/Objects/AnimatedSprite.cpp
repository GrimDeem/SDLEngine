#include "../../include/Objects/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
	: animFPS(24)
	, frameTime(0)
{
}

std::shared_ptr<AnimatedSprite> AnimatedSprite::create()
{
	return std::make_shared<AnimatedSprite>();
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update(float deltaTime)
{
	// Update how long the current frame has been displayed
	frameTime += deltaTime / 1000; // Convert to sec
	// This check determines if it's time to change to the next frame.
	if (frameTime > (1 / animFPS))
		// The number of frames to increment is 
		// frameTime / (1 / animFPS) == frameTime * animFPS
		frameNum += frameTime * animFPS;
			
	// Check if we've advanced past the last frame, and must wrap.
	if (frameNum >= animData.frameInfo[animNum].numFrames)
		frameNum = frameNum % animData.frameInfo[animNum].numFrames;
	// Update the active image.
	// (startFrame is relative to all the images, while frameNum is
	// relative to the first frame of this particular animation).
	int imageNum = (animData.frameInfo[animNum].startFrame + frameNum) 
		% animData.frameInfo[animNum].numFrames;
	Sprite::setTexture((animData.images[imageNum]));

	frameTime = fmod(frameTime, 1 / animFPS);

	Updatable::update(deltaTime);
}

void AnimatedSprite::initalize(AnimData data, int startingAnimNum)
{
	animData = data;
	changeAnim(startingAnimNum);
}

void AnimatedSprite::changeAnim(int newAnimNum)
{
	animNum = newAnimNum;
	// The active animation is now at frame 0 and 0.0f time
	frameNum = 0;
	//animTime = 0.0f;
	// Set active image, which is just the starting frame.
	int imageNum = animData.frameInfo[animNum].startFrame;
	Sprite::setTexture((animData.images[imageNum]));
	
}

void AnimatedSprite::removeChild(NodePtr child)
{
	Node::removeChild(child);
	Updatable::removeChild(child);
}

void AnimatedSprite::insertChild(NodePtr child)
{
	Node::insertChild(child, 0, "");
	Updatable::insertChild(child);
}


void AnimatedSprite::setAnimFPS(int newFPS)
{
	animFPS = newFPS;
}
int AnimatedSprite::getAnimFPS()
{
	return animFPS;
}
