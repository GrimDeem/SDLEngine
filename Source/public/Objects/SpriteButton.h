#ifndef SDL_SPRITEBUTTON_H
#define SDL_SPRITEBUTTON_H

#include <Objects/Sprite.h>
#include <Controllers/Button.h>

class SpriteButton : public Sprite, public Button {
public:
    SpriteButton(const std::string& _imgPath, EventHandler& handler, OnButtonClickCallback callback);

    static std::shared_ptr<SpriteButton> create(const std::string& _imgPath, EventHandler& handler, OnButtonClickCallback callback);
private:
    virtual Vec2 _getObjectCenterPosition() override;
    virtual Size _getObjectSize() override;
};

#endif //SDL_SPRITEBUTTON_H
