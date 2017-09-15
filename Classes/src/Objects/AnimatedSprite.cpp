#include "Objects/AnimatedSprite.h"

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

	// Check if we've advanced past the last frame
	if (frameNum >= currentAnimation.size()) {
		if (isLooped)
			frameNum = frameNum % currentAnimation.size();
		else {
			animateNext();
			return;
		}
	}
	Sprite::setTexture((currentAnimation[frameNum]));
	frameTime = fmod(frameTime, 1 / animFPS);
	Updatable::update(deltaTime);
}

void AnimatedSprite::removeChild(NodePtr child)
{
	Node::removeChild(child);
	Updatable::removeChild(child);
}

void AnimatedSprite::addAnimation(std::string animationName, AnimationFrames frames)
{
	assert(!animationName.empty() && !frames.empty());
	animations.insert(std::make_pair(animationName, frames));
}

void AnimatedSprite::animate(std::string animationName, std::string nextAnimationName)
{
	assert(!animationName.empty() && !nextAnimationName.empty());
	frameNum = 0;
	frameTime = 0;
	isLooped = false;
	currentAnimation = animations[animationName];
	nextAnimation = animations[nextAnimationName];
}

void AnimatedSprite::insertChild(NodePtr child)
{
	Node::insertChild(child, 0, "");
	Updatable::insertChild(child);
}


void AnimatedSprite::animateLooped(std::string loopedAnimationName)
{
	currentAnimation = animations[loopedAnimationName];
	frameNum = 0;
	frameTime = 0;
	isLooped = true;
}

void AnimatedSprite::setAnimFPS(int newFPS)
{
	animFPS = newFPS;
}
int AnimatedSprite::getAnimFPS()
{
	return animFPS;
}

void AnimatedSprite::animateNext()
{
	currentAnimation = nextAnimation;
	isLooped = true;
	frameNum = 0;
	frameTime = 0;
}
