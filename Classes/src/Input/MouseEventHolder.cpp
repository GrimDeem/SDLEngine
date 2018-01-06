#include "Input/MouseEventHolder.h"

void MouseEventHolder::onButtonPressed(mouseBtnCallback _callback)
{
	m_onButtonPressedCB.push_back(_callback);
}

void MouseEventHolder::onButtonReleased(mouseBtnCallback _callback)
{
	m_onButtonReleasedCB.push_back(_callback);
}

void MouseEventHolder::onMouseMoved(mouseMotionCallback _callback)
{
	m_onMouseMovedCB.push_back(_callback);
}

void MouseEventHolder::processOnButtonPressed(SDL_MouseButtonEvent* _mEvent, float _dt)
{
	for (auto callback : m_onButtonPressedCB)
		callback(_mEvent, _dt);
}

void MouseEventHolder::processOnButtonReleased(SDL_MouseButtonEvent* _mEvent, float _dt)
{
	for (auto callback : m_onButtonReleasedCB)
		callback(_mEvent, _dt);
}

void MouseEventHolder::processOnMouseMoved(SDL_MouseMotionEvent* _mEvent, float _dt)
{
	for (auto callback : m_onMouseMovedCB)
		callback(_mEvent, _dt);
}
