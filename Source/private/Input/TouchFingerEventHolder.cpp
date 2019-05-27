#include <Input/TouchFingerEventHolder.h>

void TouchFingerEventHolder::onFingerDown(fingerEventCallback _callback) {
	m_onFingerDownCB.push_back(_callback);
}

void TouchFingerEventHolder::onFingerUp(fingerEventCallback _callback) {
	m_onFingerUpCB.push_back(_callback);
}

void TouchFingerEventHolder::onFingerMotion(fingerEventCallback _callback) {
	m_onFingerMotionCB.push_back(_callback);
}

void TouchFingerEventHolder::processOnFingerDown(SDL_TouchFingerEvent* _event, float _dt) {
	for (auto callback : m_onFingerDownCB)
		callback(_event, _dt);
}

void TouchFingerEventHolder::processOnFingerUp(SDL_TouchFingerEvent* _event, float _dt) {
	for (auto callback : m_onFingerUpCB)
		callback(_event, _dt);
}

void TouchFingerEventHolder::processOnFingerMotion(SDL_TouchFingerEvent* _event, float _dt) {
	for (auto callback : m_onFingerMotionCB)
		callback(_event, _dt);
}
