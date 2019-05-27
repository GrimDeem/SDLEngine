#include <Controllers/Button.h>

Button::Button(EventHandler& handler, Button::OnButtonClickCallback callback)
: m_handler(&handler)
, m_callback(callback) {
    _initHolders();
}

void Button::_initHolders() {
#ifndef ANDROID
    MouseEventHolder mHolder;
    mHolder.onButtonPressed([this](SDL_MouseButtonEvent* _mEvent, float _dt){
        if(_mEvent->button == SDL_BUTTON_LEFT && _eventInArea(Vec2(_mEvent->x, _mEvent->y))) {
            m_callback();
        }
    });
    m_handler->addMouseHolder(mHolder);
#else
    TouchFingerEventHolder tHolder;
    tHolder.onFingerDown([this](SDL_TouchFingerEvent* _tEvent, float _dt){
        auto winSize = Keeper::getInstance().getWindowManager()->getWindowSize();
        if(_eventInArea(Vec2(_tEvent->x * winSize.width, _tEvent->y * winSize.height))) {
            m_callback();
        }
    });
    m_handler->addTouchFingerEventHolder(tHolder);
#endif
}

bool Button::_eventInArea(Vec2 eventPos) {
    float xMax, xMin, yMax, yMin; //Button borders
    auto centerPos = _getObjectCenterPosition();
    auto size = _getObjectSize();

    xMax = centerPos.x + size.width / 2;
    xMin = centerPos.x - size.width / 2;
    yMax = centerPos.y + size.height / 2;
    yMin = centerPos.y - size.height / 2;

    if(eventPos.x < xMax && eventPos.x > xMin)
        if(eventPos.y < yMax && eventPos.y > yMin)
            return true;
    return false;
}
