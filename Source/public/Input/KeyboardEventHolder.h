#ifndef _KB_EVENT_HOLDER_
#define _KB_EVENT_HOLDER_

#include <vector>
#include <functional>

class SDL_KeyboardEvent;

class KeyboardEventHolder
{
private:
	typedef std::function<void(SDL_KeyboardEvent* _event, float _dt)> kbCallback;
	std::vector <kbCallback> m_onKeyPressedCB;
	std::vector <kbCallback> m_onKeyReleasedCB;
public:
	KeyboardEventHolder() = default;
	virtual ~KeyboardEventHolder() = default;
	virtual void onKeyPressed(kbCallback _callback);
	virtual void onKeyReleased(kbCallback _callback);

	virtual void processOnKeyPressed(SDL_KeyboardEvent* _event, float _dt);
	virtual void processOnKeyReleased(SDL_KeyboardEvent* _event, float _dt);
};

#endif // !_KB_EVENT_HOLDER_
