#include "../../include/Objects/Sprite.h"

Sprite::Sprite(std::string pathToImg)
	: path(pathToImg)
{
	setTexture(Keeper::getInstance().getTextureManager()->getTexture(pathToImg));
}

Sprite::Sprite()
{
}

std::shared_ptr<Sprite> Sprite::create()
{
	return std::make_shared<Sprite>();
}

std::shared_ptr<Sprite> Sprite::create(std::string imgPath)
{
	return std::make_shared<Sprite>(imgPath);
}

void Sprite::draw()
{
	SDL_Rect texr;
	texr.w = imageRealSize.width  * Node::getScaleX();		    //SpriteSize
	texr.h = imageRealSize.height * Node::getScaleY();
	texr.x = Node::getPositionX() - Node::getAnchorPoint().x * texr.w;  //SpritePosition
	texr.y = Node::getPositionY() - Node::getAnchorPoint().y * texr.h;

	SDL_RenderCopyEx(Keeper::getInstance().getRenderer(), 
			 texture2D, nullptr, &texr, Node::getRotation(),
			 nullptr, Node::getFlipState().getSDLFlip());
	Node::draw();
}

Size Sprite::getContentSize()
{
	return Size(imageRealSize.width * Node::getScaleX(), imageRealSize.height * Node::getScaleY());
}

void Sprite::setTexture(std::string imgPath)
{
	path = imgPath;
	setTexture(Keeper::getInstance().getTextureManager()->getTexture(path));
}

void Sprite::setTexture(SDL_Texture * texture)
{
	texture2D = texture;
	SDL_QueryTexture(texture2D, nullptr, nullptr, &imageRealSize.width, &imageRealSize.height);
}

Sprite::~Sprite()
{
	Keeper::getInstance().getTextureManager()->unloadTexture(path);
}
