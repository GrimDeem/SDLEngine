#pragma once
#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <unordered_map>
#include <algorithm>
#include <SDL_image.h>
#include "../Managers/Keeper.h"

#ifdef LOG
#include <iostream>
#endif

/*	TextureManager is the class, which loads, unloads,  
	stores and provides access to all texures in engine
*/
class TextureManager
{
private:
	/* map of the loaded textures
	*/
	std::unordered_map<std::string, SDL_Texture*> _textures;
	/*add new texture to the map*/
	SDL_Texture* loadTexture(std::string pathToTexture); 
public:
	TextureManager() {}
	~TextureManager() {
		_textures.clear();
	}
	/*returns texture from the following path*/
	SDL_Texture* getTexture(std::string pathToTexture);

	/*unloads passed texture from memory & map*/
	void unloadTexture(SDL_Texture* texture);

	/*Unloads the texture along the specified path from memory & map*/
	void unloadTexture(std::string pathToTexture);
};


#endif // !__TEXTURE_MANAGER_H__
