#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "Node.h"
#include "SDL_image.h"
#include "../Managers/Keeper.h"

/*
	Sprite is a 2d image.
*/
class Sprite : public Node
{
private: 
	SDL_Texture *texture2D; //texture to draw
	std::string path;
	Size imageRealSize; // texture width & height
public:
	Sprite();
	Sprite(std::string imgPath);
	static std::shared_ptr<Sprite> create();
	static std::shared_ptr<Sprite> create(std::string imgPath);
	virtual ~Sprite();

	virtual void draw() override;
	virtual Size getContentSize();
	virtual void setTexture(std::string imgPath);
	virtual void setTexture(SDL_Texture *texture);
};


#endif // !__SPRITE_H__
