#pragma once
#ifndef __ANIMATED_SPRITE_H__
#define __ANIMATED_SPRITE_H__

#include <unordered_map>
#include "Objects/Sprite.h"
#include "Objects/Updatable.h"


class AnimatedSprite : public Sprite, public Updatable
{
private:
	typedef std::vector<SDL_Texture*> AnimationFrames;

	// map of key(animationName) and animation frames
	std::unordered_map<std::string, AnimationFrames> animations;

	// The FPS the animation is running at (24FPS by default).
	float animFPS;

	// is currentAnimation looped or not
	bool isLooped;

	// The frame number of the active animation that's being displayed
	int frameNum;

	// Amount of time the current frame has been displayed
	float frameTime;

	AnimationFrames currentAnimation;

	// animation, that will be played after currentAnimation
	AnimationFrames nextAnimation;

protected:
	virtual void insertChild(NodePtr child) override;

public:
	AnimatedSprite();
	static std::shared_ptr<AnimatedSprite> create();
	virtual ~AnimatedSprite();

	virtual void update(float deltaTime) override;
	virtual void removeChild(NodePtr child) override;

	/*
	add animation to animations with <animationName> key
	*/
	void addAnimation(std::string animationName, AnimationFrames frames);

	/*
	after end of <animationName> <nextAnimationName> will be looped
	*/
	void animate(std::string animationName, std::string nextAnimationName);

	/*
	play <loopedAnimationName> in loop
	*/
	void animateLooped(std::string loopedAnimationName);

	virtual void setAnimFPS(int newFPS);
	virtual int getAnimFPS();

private:
	void animateNext();
};

#endif // !__ANIMATED_SPRITE_H__
