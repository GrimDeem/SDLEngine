#ifndef _MOUSE_EVENT_HOLDER_
#define _MOUSE_EVENT_HOLDER_

#include <vector>
#include <functional>

class SDL_MouseButtonEvent;
class SDL_MouseMotionEvent;

class MouseEventHolder
{
private:
	typedef std::function<void(SDL_MouseButtonEvent* _mEvent, float _dt)> mouseBtnCallback;
	typedef std::function<void(SDL_MouseMotionEvent* _mEvent, float _dt)> mouseMotionCallback;
	std::vector <mouseBtnCallback> m_onButtonPressedCB;
	std::vector <mouseBtnCallback> m_onButtonReleasedCB;
	std::vector <mouseMotionCallback> m_onMouseMovedCB;
public:
	MouseEventHolder() = default;
	virtual ~MouseEventHolder() = default;
	virtual void onButtonPressed(mouseBtnCallback _callback);
	virtual void onButtonReleased(mouseBtnCallback _callback);
	virtual void onMouseMoved(mouseMotionCallback _callback);

	virtual void processOnButtonPressed(SDL_MouseButtonEvent* _mEvent, float _dt);
	virtual void processOnButtonReleased(SDL_MouseButtonEvent* _mEvent, float _dt);
	virtual void processOnMouseMoved(SDL_MouseMotionEvent* _mEvent, float _dt);
};

#endif // !_MOUSE_EVENT_HOLDER_