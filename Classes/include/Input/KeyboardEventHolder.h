#ifndef _KB_EVENT_HOLDER_
#define _KB_EVENT_HOLDER_

#include <SDL.h>
#include <vector>
#include <functional>

class KeyboardEventHolder
{
private:
	typedef std::function<void(SDL_KeyboardEvent *key, float dt)> kbCallback;
	std::vector <kbCallback> onKeyPressedCB;
	std::vector <kbCallback> onKeyReleasedCB;
public:
	KeyboardEventHolder() {}
	virtual ~KeyboardEventHolder() {}
	virtual void onKeyPressed(kbCallback callback);
	virtual void onKeyReleased(kbCallback callback);

	virtual void processOnKeyPressed(SDL_KeyboardEvent *key, float dt);
	virtual void processOnKeyReleased(SDL_KeyboardEvent *key, float dt);
};

#endif // !_KB_EVENT_HOLDER_
