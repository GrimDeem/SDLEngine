#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

#include <functional>

#include <Core/GlobalDefines.h>
#include <Core/Vec2.h>
#include <Managers/Keeper.h>
#include <Input/EventHandler.h>

class Button {
public:
    typedef std::function<void()> OnButtonClickCallback;

private:
    EventHandler* m_handler;
    OnButtonClickCallback m_callback;

public:
    Button(EventHandler& handler, OnButtonClickCallback callback);
    virtual ~Button() = default;

private:
    virtual Vec2 _getObjectCenterPosition() = 0;
    virtual Size _getObjectSize() = 0;
    void _initHolders();
    bool _eventInArea(Vec2 eventPos);
};

#endif //SDL_BUTTON_H
