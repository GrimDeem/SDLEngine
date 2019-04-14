#include <SDL_image.h>

#include <Managers/Keeper.h>
#include <Objects/Sprite.h>

Sprite::Sprite(const std::string& _pathToImg)
	: m_path(_pathToImg)
{
	setTexture(Keeper::getInstance().getTextureManager()->getTexture(_pathToImg));
}

Sprite::~Sprite() {
	Keeper::getInstance().getTextureManager()->unloadTexture(m_path);
}

std::shared_ptr<Sprite> Sprite::create() {
	return std::make_shared<Sprite>();
}

std::shared_ptr<Sprite> Sprite::create(const std::string& _imgPath) {
	return std::make_shared<Sprite>(_imgPath);
}

void Sprite::draw() {
	SDL_Rect texr;
	texr.w = m_imageRealSize.width  * Node::getScaleX();		    //SpriteSize
	texr.h = m_imageRealSize.height * Node::getScaleY();
	texr.x = Node::getPositionX() - Node::getAnchorPoint().x * texr.w
		- Keeper::getInstance().getCamera()->getPosition().x;  //SpritePosition
	texr.y = Node::getPositionY() - Node::getAnchorPoint().y * texr.h
		- Keeper::getInstance().getCamera()->getPosition().y;

	SDL_RenderCopyEx(Keeper::getInstance().getRenderer(),
			 m_texture2D, nullptr, &texr, Node::getRotation(),
			 nullptr, Node::getFlipState().getSDLFlip());
	Node::draw();
}

const Size& Sprite::getContentSize() const {
	return Size(m_imageRealSize.width * Node::getScaleX(), m_imageRealSize.height * Node::getScaleY());
}

void Sprite::setTexture(const std::string& imgPath) {
	m_path = imgPath;
	setTexture(Keeper::getInstance().getTextureManager()->getTexture(m_path));
}

void Sprite::setTexture(SDL_Texture* texture) {
	m_texture2D = texture;
	SDL_QueryTexture(m_texture2D, nullptr, nullptr, &m_imageRealSize.width, &m_imageRealSize.height);
}
