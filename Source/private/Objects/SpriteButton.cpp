#include <Objects/SpriteButton.h>

std::shared_ptr<SpriteButton>
SpriteButton::create(const std::string &imgPath, EventHandler &handler,
                     Button::OnButtonClickCallback callback) {
    return std::make_shared<SpriteButton>(imgPath, handler, callback);
}

SpriteButton::SpriteButton(const std::string &_imgPath, EventHandler &handler,
                           Button::OnButtonClickCallback callback)
: Sprite(_imgPath)
, Button(handler, callback) {
    enableFixedPositionOnScreen();
}

Vec2 SpriteButton::_getObjectCenterPosition() {
    auto x = _calcucatePositionOnScreenX() - ( Node::getAnchorPoint().x - 0.5 ) * getContentSize().width;
    auto y = _calcucatePositionOnScreenY() - ( Node::getAnchorPoint().y - 0.5 ) * getContentSize().height;
    return Vec2(x, y);
}

Size SpriteButton::_getObjectSize() {
    return getContentSize();
}
