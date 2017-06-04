#include "..\..\include\Objects\Sprite.h"

Sprite::Sprite(std::string pathToImg)
{
	this->path = pathToImg;
	this->texture2D = Keeper::getInstance().getTextureManager()->getTexture(pathToImg);//IMG_LoadTexture(Keeper::getInstance().getRenderer(), pathToImg.c_str());  //TODO::Loader
	SDL_QueryTexture(texture2D, NULL, NULL, &imageRealSize.width, &imageRealSize.height);	
}

void Sprite::draw()
{
	SDL_Rect texr;
	texr.x = Node::getPositionX();
	texr.y = Node::getPositionY();
	texr.w = imageRealSize.width  * Node::getScaleX(); 
	texr.h = imageRealSize.height * Node::getScaleY();

	SDL_RenderCopy(Keeper::getInstance().getRenderer(), texture2D, NULL, &texr);
}

Sprite::~Sprite()
{
	Keeper::getInstance().getTextureManager()->unloadTexture(path);
}