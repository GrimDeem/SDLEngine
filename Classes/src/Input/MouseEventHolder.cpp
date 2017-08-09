#include "../../include/Input/MouseEventHolder.h"

void MouseEventHolder::onButtonPressed(mouseBtnCallback callback)
{
	onButtonPressedCB.push_back(callback);
}

void MouseEventHolder::onButtonReleased(mouseBtnCallback callback)
{
	onButtonReleasedCB.push_back(callback);
}

void MouseEventHolder::onMouseMoved(mouseMotionCallback callback)
{
	onMouseMovedCB.push_back(callback);
}

void MouseEventHolder::processOnButtonPressed(SDL_MouseButtonEvent * mEvent, float dt)
{
	for (auto callback : onButtonPressedCB)
		callback(mEvent, dt);
}

void MouseEventHolder::processOnButtonReleased(SDL_MouseButtonEvent * mEvent, float dt)
{
	for (auto callback : onButtonReleasedCB)
		callback(mEvent, dt);
}

void MouseEventHolder::processOnMouseMoved(SDL_MouseMotionEvent * mEvent, float dt)
{
	for (auto callback : onMouseMovedCB)
		callback(mEvent, dt);
}
