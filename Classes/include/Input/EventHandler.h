#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include <vector>
#include "KeyboardEventHolder.h"
#include "MouseEventHolder.h"

class EventHandler
{
	std::vector <KeyboardEventHolder> kbHolders;
	std::vector <MouseEventHolder> mouseHolders;
public:
	EventHandler() {}
	virtual ~EventHandler() {}

	virtual void addKeyboardHolder(KeyboardEventHolder newHolder);
	virtual void processKBHoldersPressed(SDL_KeyboardEvent *key, float dt);
	virtual void processKBHoldersReleased(SDL_KeyboardEvent *key, float dt);

	virtual void addMouseHolder(MouseEventHolder newHolder);
	virtual void processMouseHoldersPressed(SDL_MouseButtonEvent *key, float dt);
	virtual void processMouseHoldersReleased(SDL_MouseButtonEvent *key, float dt);
	virtual void processMouseHoldersMoved(SDL_MouseMotionEvent *key, float dt);
};

#endif // !_EVENT_HANDLER_H_
