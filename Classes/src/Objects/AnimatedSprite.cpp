#include "Objects/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
	: m_animFPS(24)
	, m_frameTime(0)
{ }

std::shared_ptr<AnimatedSprite> AnimatedSprite::create()
{
	return std::make_shared<AnimatedSprite>();
}

void AnimatedSprite::update(float _deltaTime)
{
	// Update how long the current frame has been displayed
	m_frameTime += _deltaTime / 1000; // Convert to sec
								   // This check determines if it's time to change to the next frame.
	if (m_frameTime > (1 / m_animFPS))
		// The number of frames to increment is 
		// m_frameTime / (1 / m_animFPS) == m_frameTime * m_animFPS
		m_frameNum += m_frameTime * m_animFPS;

	// Check if we've advanced past the last frame
	if (m_frameNum >= m_currentAnimation.size()) {
		if (m_isLooped)
			m_frameNum = m_frameNum % m_currentAnimation.size();
		else {
			animateNext();
			return;
		}
	}
	Sprite::setTexture((m_currentAnimation[m_frameNum]));
	m_frameTime = fmod(m_frameTime, 1 / m_animFPS);
	Updatable::update(_deltaTime);
}

void AnimatedSprite::removeChild(NodePtr _child)
{
	Node::removeChild(_child);
	Updatable::removeChild(_child);
}

void AnimatedSprite::addAnimation(const std::string& _animationName, const AnimationFrames& _frames)
{
	assert(!_animationName.empty() && !_frames.empty());
	m_animations.insert(std::make_pair(_animationName, _frames));
}

void AnimatedSprite::animate(const std::string& _animationName, const std::string& _nextAnimationName)
{
	assert(!_animationName.empty() && !_nextAnimationName.empty());
	m_frameNum = 0;
	m_frameTime = 0;
	m_isLooped = false;
	m_currentAnimation = m_animations[_animationName];
	m_nextAnimation = m_animations[_nextAnimationName];
}

void AnimatedSprite::insertChild(NodePtr _child)
{
	Node::insertChild(_child, 0, "");
	Updatable::insertChild(_child);
}


void AnimatedSprite::animateLooped(const std::string& _loopedAnimationName)
{
	m_currentAnimation = m_animations[_loopedAnimationName];
	m_frameNum = 0;
	m_frameTime = 0;
	m_isLooped = true;
}

void AnimatedSprite::setAnimFPS(int _newFPS)
{
	m_animFPS = _newFPS;
}
int AnimatedSprite::getAnimFPS()
{
	return m_animFPS;
}

void AnimatedSprite::animateNext()
{
	m_currentAnimation = m_nextAnimation;
	m_isLooped = true;
	m_frameNum = 0;
	m_frameTime = 0;
}
