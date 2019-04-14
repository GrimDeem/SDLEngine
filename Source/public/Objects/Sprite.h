#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <Objects/Node.h>

struct SDL_Texture;

/*
	Sprite is a 2d image.
*/
class Sprite : public Node
{
private:
	SDL_Texture* m_texture2D; //texture to draw
	std::string m_path;
	Size m_imageRealSize; // texture width & height

public:
	Sprite() = default;
	Sprite(const std::string& _imgPath);
	static std::shared_ptr<Sprite> create();
	static std::shared_ptr<Sprite> create(const std::string& _imgPath);
	virtual ~Sprite();

	virtual void draw() override;
	virtual const Size& getContentSize() const;
	virtual void setTexture(const std::string& _imgPath);
	virtual void setTexture(SDL_Texture* _texture);
};


#endif // !__SPRITE_H__
