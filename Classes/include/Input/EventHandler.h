#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include <vector>
#include <Input/KeyboardEventHolder.h>
#include <Input/MouseEventHolder.h>

class EventHandler
{
private:
	std::vector <KeyboardEventHolder> m_keyboardHolders;
	std::vector <MouseEventHolder> m_mouseHolders;
public:
	EventHandler() = default;
	virtual ~EventHandler() = default;

	virtual void addKeyboardHolder(KeyboardEventHolder _newHolder);
	virtual void processKBHoldersPressed(SDL_KeyboardEvent* _event, float _dt);
	virtual void processKBHoldersReleased(SDL_KeyboardEvent* _event, float _dt);

	virtual void addMouseHolder(MouseEventHolder _newHolder);
	virtual void processMouseHoldersPressed(SDL_MouseButtonEvent* _event, float _dt);
	virtual void processMouseHoldersReleased(SDL_MouseButtonEvent* _event, float _dt);
	virtual void processMouseHoldersMoved(SDL_MouseMotionEvent* _event, float _dt);
};

#endif // !_EVENT_HANDLER_H_
