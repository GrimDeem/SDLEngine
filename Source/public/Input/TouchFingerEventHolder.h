#ifndef SDL_TOUCHFINGEREVENTHOLDER_H
#define SDL_TOUCHFINGEREVENTHOLDER_H

#include <SDL.h>
#include <vector>
#include <functional>

class TouchFingerEventHolder
{
private:
	typedef std::function<void(SDL_TouchFingerEvent* _event, float _dt)> fingerEventCallback;
	std::vector <fingerEventCallback> m_onFingerDownCB;
	std::vector <fingerEventCallback> m_onFingerUpCB;
	std::vector <fingerEventCallback> m_onFingerMotionCB;
public:
	TouchFingerEventHolder() = default;
	virtual ~TouchFingerEventHolder() = default;
	virtual void onFingerDown(fingerEventCallback _callback);
	virtual void onFingerUp(fingerEventCallback _callback);
	virtual void onFingerMotion(fingerEventCallback _callback);

	virtual void processOnFingerDown(SDL_TouchFingerEvent* _event, float _dt);
	virtual void processOnFingerUp(SDL_TouchFingerEvent* _event, float _dt);
	virtual void processOnFingerMotion(SDL_TouchFingerEvent* _event, float _dt);
};

#endif //SDL_TOUCHFINGEREVENTHOLDER_H
