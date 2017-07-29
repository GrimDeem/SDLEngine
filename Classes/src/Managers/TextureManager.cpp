#include "../../include/Managers/TextureManager.h"

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
	if (pathToTexture.empty()) {
		return nullptr;
	}

	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) {	// if texture is finded -> return it
		return _textures.at(pathToTexture);
	}
	//else -> add to map and return
	auto texure = loadTexture(pathToTexture);
	return texure;
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
	if (pathToTexture.empty()) {
		return;
	}	
	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) {  // if texture is finded -> return it
		_textures.erase(pathToTexture);
		SDL_DestroyTexture(it->second);
	}
}

void TextureManager::unloadTexture(SDL_Texture * texture)
{
	if (texture == nullptr) {
		return;
	}
	
	auto it = std::find_if(_textures.begin(), _textures.end(), 
			       [&texture](const std::unordered_map<std::string, SDL_Texture*>::value_type& value)
			       {
				       return value.second == texture;			
			       });
	if (it != _textures.end()) 
		unloadTexture(it->first);
}

void TextureManager::clearTexturePool()
{
	for(auto& tex : _textures)
		SDL_DestroyTexture(tex.second);
	_textures.clear();
}
