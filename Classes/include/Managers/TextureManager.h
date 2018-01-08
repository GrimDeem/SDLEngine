#pragma once
#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#define __TM_LOG__ 1
#include <unordered_map>
#include <algorithm>
#include <SDL_image.h>
#include <Managers/Keeper.h>

/*
	TextureManager is the class, which load, unload,
	store and provide access to all texures in engine
*/
class TextureManager
{
private:
	typedef std::unordered_map<std::string, SDL_Texture*>::iterator _texturesIterator;
	/* map of the loaded textures(texture pool)*/
	std::unordered_map<std::string, SDL_Texture*> m_textures;
	/*load texture and add it to the map*/
	SDL_Texture* _loadTexture(const std::string& _pathToTexture);
public:
	TextureManager() = default;
	~TextureManager();
	/*returns texture from the following path*/
	SDL_Texture* getTexture(const std::string& _pathToTexture);

	/*unloads passed texture from memory & map*/
	void unloadTexture(SDL_Texture* _texture);

	/*Unloads the texture along the specified path from memory & map*/
	void unloadTexture(const std::string& _pathToTexture);

	/*Unloads all textures from pool*/
	void clearTexturePool();
};


#endif // !__TEXTURE_MANAGER_H__
