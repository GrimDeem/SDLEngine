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
	Sprite(std::string imgPath);
	virtual ~Sprite();

	//TODO:: draw with anchor point
	virtual void draw() override;
};


#endif // !__SPRITE_H__
