#include "../../include/Input/EventHandler.h"

void EventHandler::addKeyboardHolder(KeyboardEventHolder newHolder)
{
	kbHolders.push_back(newHolder);
}

void EventHandler::processKBHoldersPressed(SDL_KeyboardEvent *key, float dt)
{
	for (auto holder : kbHolders)
		holder.processOnKeyPressed(key, dt);
}

void EventHandler::processKBHoldersReleased(SDL_KeyboardEvent *key, float dt)
{
	for (auto holder : kbHolders)
		holder.processOnKeyReleased(key, dt);
}
