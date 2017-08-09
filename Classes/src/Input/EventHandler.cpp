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

void EventHandler::addMouseHolder(MouseEventHolder newHolder)
{
	mouseHolders.push_back(newHolder);
}

void EventHandler::processMouseHoldersPressed(SDL_MouseButtonEvent *key, float dt)
{
	for (auto holder : mouseHolders)
		holder.processOnButtonPressed(key, dt);
}

void EventHandler::processMouseHoldersReleased(SDL_MouseButtonEvent * key, float dt)
{
	for (auto holder : mouseHolders)
		holder.processOnButtonReleased(key, dt);
}

void EventHandler::processMouseHoldersMoved(SDL_MouseMotionEvent * key, float dt)
{
	for (auto holder : mouseHolders)
		holder.processOnMouseMoved(key, dt);
}
