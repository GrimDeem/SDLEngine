#ifndef _MOUSE_EVENT_HOLDER_
#define _MOUSE_EVENT_HOLDER_

#include <SDL.h>
#include <vector>
#include <functional>

class MouseEventHolder
{
private:
	typedef std::function<void(SDL_MouseButtonEvent *mEvent, float dt)> mouseBtnCallback;
	typedef std::function<void(SDL_MouseMotionEvent *mEvent, float dt)> mouseMotionCallback;
	std::vector <mouseBtnCallback> onButtonPressedCB;
	std::vector <mouseBtnCallback> onButtonReleasedCB;
	std::vector <mouseMotionCallback> onMouseMovedCB;
public:
	MouseEventHolder() {}
	virtual ~MouseEventHolder() {}
	virtual void onButtonPressed(mouseBtnCallback callback);
	virtual void onButtonReleased(mouseBtnCallback callback);
	virtual void onMouseMoved(mouseMotionCallback callback);

	virtual void processOnButtonPressed(SDL_MouseButtonEvent *key, float dt);
	virtual void processOnButtonReleased(SDL_MouseButtonEvent *key, float dt);
	virtual void processOnMouseMoved(SDL_MouseMotionEvent *key, float dt);
};

#endif // !_MOUSE_EVENT_HOLDER_