#pragma once
#ifndef __INITIAL_SCENE_H__
#define __INITIAL_SCENE_H__ 

#include "include/Objects/Scene.h"
#include "include/Objects/Sprite.h"
#include "include/Objects/TextLabel.h"
#include "include/Objects/AnimatedSprite.h"

#include <assert.h>
#include <string>
#define IMG_PATH  "../Resources/Sprites/tank.bmp"
#define IMG2_PATH "../Resources/Sprites/img.bmp"
#define FONT_PATH "../Resources/Fonts/DroidSans.ttf"

class InitialScene : public Scene
{
private:
	Sprite* movableTank;
public:
	void updateScene(const Uint8* kbState, float dt);
	void updateTest();
	void drawPriorityTest();
	void animatedSpriteTest();
	void drawTextLabelTest();
	static Scene* createScene();
	static InitialScene* create();
	virtual bool init();
};
 
#endif // !__INITIAL_SCENE_H__

/*textlabel example
void Var2()
{
	TTF_Font * font = TTF_OpenFont("../Resources/Fonts/DroidSans.ttf", 25);
	
	if(font == NULL){
		std::cout << TTF_GetError() << endl;
		exit(1);
	}
	
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface * surface = TTF_RenderText_Solid(font,
						     "Welcome to Programmer's Ranch", color);
        SDL_Texture * texture = SDL_CreateTextureFromSurface(Keeper::getInstance().getRenderer(),
							     surface);
	int texW = 100;
	int texH = 100;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	std::cout << texW << ':' << texH << endl;
	SDL_Rect dstrect = { 100, 100, texW, texH };

	SDL_RenderCopy(Keeper::getInstance().getRenderer(), texture, NULL, &dstrect);
}
*/
