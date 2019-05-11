#pragma once
#ifndef __ANIMATED_SPRITE_H__
#define __ANIMATED_SPRITE_H__

#include <unordered_map>
#include <Objects/Sprite.h>


class AnimatedSprite : public Sprite
{
private:
	typedef std::vector<SDL_Texture*> AnimationFrames;

	// map of key(animationName) and animation frames
	std::unordered_map<std::string, AnimationFrames> m_animations;

	// The FPS the animation is running at (24FPS by default).
	float m_animFPS;

	// is currentAnimation looped or not
	bool m_isLooped;

	// The frame number of the active animation that's being displayed
	int m_frameNum;

	// Amount of time the current frame has been displayed
	float m_frameTime;

	AnimationFrames m_currentAnimation;

	// animation, that will be played after currentAnimation
	AnimationFrames m_nextAnimation;

protected:
	void _onAnimate(bool nextLooped);

public:
	AnimatedSprite();
	static std::shared_ptr<AnimatedSprite> create();
	virtual ~AnimatedSprite() = default;

	virtual void onUpdate(float deltaTime) override;

	/*
	add animation to animations with <animationName> key
	*/
	void addAnimation(const std::string& animationName, const AnimationFrames& frames);

	/*
	after end of <animationName> <nextAnimationName> will be looped
	*/
	void animate(const std::string& animationName, const std::string& nextAnimationName);

	/*
	play <loopedAnimationName> in loop
	*/
	void animateLooped(const std::string& loopedAnimationName);

	virtual void setAnimFPS(int newFPS);
	virtual int getAnimFPS();

private:
	void animateNext();
};

#endif // !__ANIMATED_SPRITE_H__
