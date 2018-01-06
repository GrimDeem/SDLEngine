#include "Input/KeyboardEventHolder.h"

void KeyboardEventHolder::onKeyPressed(kbCallback _callback)
{
	m_onKeyPressedCB.push_back(_callback);
}

void KeyboardEventHolder::onKeyReleased(kbCallback _callback)
{
	m_onKeyReleasedCB.push_back(_callback);
}

void KeyboardEventHolder::processOnKeyPressed(SDL_KeyboardEvent* _event, float _dt)
{
	for (auto callback : m_onKeyPressedCB)
		callback(_event, _dt);
}

void KeyboardEventHolder::processOnKeyReleased(SDL_KeyboardEvent* _event, float _dt)
{
	for (auto callback : m_onKeyReleasedCB)
		callback(_event, _dt);
}
