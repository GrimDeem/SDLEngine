#include "..\..\include\Objects\Sprite.h"

Sprite::Sprite(std::string pathToImg)
{
	this->path = pathToImg;
	this->texture2D = Keeper::getInstance().getTextureManager()->getTexture(pathToImg);
	SDL_QueryTexture(texture2D, NULL, NULL, &imageRealSize.width, &imageRealSize.height);	
}

void Sprite::draw()
{
	SDL_Rect texr;
	texr.w = imageRealSize.width  * Node::getScaleX(); 
	texr.h = imageRealSize.height * Node::getScaleY();
	texr.x = Node::getPositionX() - Node::getAnchorPoint().x * texr.w;
	texr.y = Node::getPositionY() - Node::getAnchorPoint().y * texr.h;

	SDL_RenderCopy(Keeper::getInstance().getRenderer(), texture2D, NULL, &texr);
}

Size Sprite::getContentSize()
{
	return Size(imageRealSize.width  * Node::getScaleX(), imageRealSize.height * Node::getScaleY());
}

Sprite::~Sprite()
{
	Keeper::getInstance().getTextureManager()->unloadTexture(path);
}