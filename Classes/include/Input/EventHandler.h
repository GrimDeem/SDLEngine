#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include <vector>
#include "KeyboardEventHolder.h"

class EventHandler
{
	std::vector <KeyboardEventHolder> kbHolders;
public:
	EventHandler() {}
	virtual ~EventHandler() {}

	virtual void addKeyboardHolder(KeyboardEventHolder newHolder);
	virtual void processKBHoldersPressed(SDL_KeyboardEvent *key, float dt);
	virtual void processKBHoldersReleased(SDL_KeyboardEvent *key, float dt);
};

#endif // !_EVENT_HANDLER_H_
