#include "Managers/TextureManager.h"

#if __TM_LOG__ >= 1
void logListOfTextures(std::unordered_map<std::string, SDL_Texture*> _textures) {
	LOG("List of textures: \n");
	for (auto &it : _textures)
		LOG("%s \n", it.first.c_str());
	LOG("end \n\n");
}
#endif // !__TM_LOG__

SDL_Texture * TextureManager::getTexture(std::string pathToTexture)
{
	if (!pathToTexture.empty()) {
		auto it = _textures.find(pathToTexture);
		if (it != _textures.end())
			return it->second;	// if texture is finded -> return it
		else
			return loadTexture(pathToTexture);  //else -> add to map and return
	}
	assert(false);
}

SDL_Texture * TextureManager::loadTexture(std::string pathToTexture)
{
	auto loadedTex = IMG_LoadTexture(Keeper::getInstance().getRenderer(), pathToTexture.c_str());
	if(loadedTex == nullptr)
		LOG(IMG_GetError());
	_textures.insert(std::make_pair(pathToTexture, loadedTex));
	return loadedTex;
}

void TextureManager::unloadTexture(std::string pathToTexture)
{
	if (!pathToTexture.empty()) {
		_texturesIterator it = _textures.find(pathToTexture);
		if (it != _textures.end()) {  // if texture is finded -> return it
			SDL_DestroyTexture(it->second);
			_textures.erase(it);
		}
	}
}

void TextureManager::unloadTexture(SDL_Texture * texture)
{
	if (texture != nullptr) {
		auto it = std::find_if(_textures.begin(), _textures.end(),
			[&texture](const std::unordered_map<std::string, SDL_Texture*>::value_type& value)
		{
			return value.second == texture;
		});
		if (it != _textures.end())
			unloadTexture(it->first);
	}
}

void TextureManager::clearTexturePool()
{
	for(auto& tex : _textures)
		SDL_DestroyTexture(tex.second);
	_textures.clear();
}
