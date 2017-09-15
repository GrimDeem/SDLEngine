#include "Input/KeyboardEventHolder.h"

void KeyboardEventHolder::onKeyPressed(kbCallback callback)
{
	onKeyPressedCB.push_back(callback);
}

void KeyboardEventHolder::onKeyReleased(kbCallback callback)
{
	onKeyReleasedCB.push_back(callback);
}

void KeyboardEventHolder::processOnKeyPressed(SDL_KeyboardEvent *key, float dt)
{
	for (auto callback : onKeyPressedCB)
		callback(key, dt);
}

void KeyboardEventHolder::processOnKeyReleased(SDL_KeyboardEvent *key, float dt)
{
	for (auto callback : onKeyReleasedCB)
		callback(key, dt);
}
