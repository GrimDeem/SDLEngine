#include "..\..\include\Objects\Sprite.h"

Sprite::Sprite(std::string pathToImg)
	: path(pathToImg)
	, rotation(0)
{
	this->texture2D = Keeper::getInstance().getTextureManager()->getTexture(pathToImg);
	SDL_QueryTexture(texture2D, nullptr, nullptr, &imageRealSize.width, &imageRealSize.height);
}

void Sprite::draw()
{
	SDL_Rect texr;
	texr.w = imageRealSize.width  * Node::getScaleX();	//SpriteSize
	texr.h = imageRealSize.height * Node::getScaleY();
	texr.x = Node::getPositionX() - Node::getAnchorPoint().x * texr.w; //SpritePosition
	texr.y = Node::getPositionY() - Node::getAnchorPoint().y * texr.h;
	
	SDL_RendererFlip flip = SDL_FLIP_VERTICAL;

	SDL_RenderCopyEx(Keeper::getInstance().getRenderer(), 
		texture2D, nullptr, &texr, rotation, nullptr, flip);

	Node::draw();
}

Size Sprite::getContentSize()
{
	return Size(imageRealSize.width * Node::getScaleX(), imageRealSize.height * Node::getScaleY());
}

void Sprite::setRotation(float angle)
{
	rotation = angle;
}

Sprite::~Sprite()
{
	Keeper::getInstance().getTextureManager()->unloadTexture(path);
}