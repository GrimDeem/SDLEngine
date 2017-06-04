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
	float rotation;		//
public:
	Sprite(std::string imgPath);
	virtual ~Sprite();

	virtual void draw() override;
	virtual Size getContentSize();

	/*sets rotation of the sprite clockwise in degrees */
	virtual void setRotation(float angle); 
};


#endif // !__SPRITE_H__
