#include <Input/EventHandler.h>

void EventHandler::addKeyboardHolder(KeyboardEventHolder _newHolder) {
	m_keyboardHolders.push_back(_newHolder);
}

void EventHandler::processKBHoldersPressed(SDL_KeyboardEvent* _event, float _dt) {
	for (auto holder : m_keyboardHolders)
		holder.processOnKeyPressed(_event, _dt);
}

void EventHandler::processKBHoldersReleased(SDL_KeyboardEvent* _event, float _dt) {
	for (auto holder : m_keyboardHolders)
		holder.processOnKeyReleased(_event, _dt);
}

void EventHandler::addMouseHolder(MouseEventHolder _newHolder) {
	m_mouseHolders.push_back(_newHolder);
}

void EventHandler::processMouseHoldersPressed(SDL_MouseButtonEvent* _event, float _dt) {
	for (auto holder : m_mouseHolders)
		holder.processOnButtonPressed(_event, _dt);
}

void EventHandler::processMouseHoldersReleased(SDL_MouseButtonEvent* _event, float _dt) {
	for (auto holder : m_mouseHolders)
		holder.processOnButtonReleased(_event, _dt);
}

void EventHandler::processMouseHoldersMoved(SDL_MouseMotionEvent* _event, float _dt) {
	for (auto holder : m_mouseHolders)
		holder.processOnMouseMoved(_event, _dt);
}

void EventHandler::addTouchFingerEventHolder(TouchFingerEventHolder _newHolder) {
	m_fingerTouchHolders.push_back(_newHolder);
}

void EventHandler::processFingerEventHoldersFingerDown(SDL_TouchFingerEvent* _event, float _dt) {
	for (auto holder : m_fingerTouchHolders)
		holder.processOnFingerDown(_event, _dt);
}

void EventHandler::processFingerEventHoldersFingerUp(SDL_TouchFingerEvent* _event, float _dt) {
	for (auto holder : m_fingerTouchHolders)
		holder.processOnFingerUp(_event, _dt);
}

void EventHandler::processFingerEventHoldersFingerMotion(SDL_TouchFingerEvent* _event, float _dt) {
	for (auto holder : m_fingerTouchHolders)
		holder.processOnFingerMotion(_event, _dt);
}
