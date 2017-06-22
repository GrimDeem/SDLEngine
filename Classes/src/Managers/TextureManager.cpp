#include "..\..\include\Managers\TextureManager.h"

#ifdef LOGGING
void logListOfTextures(std::unordered_map<std::string, SDL_Texture*> _textures) {
	LOG("List of textures: \n");
	for (auto &it : _textures)
		LOG("%s \n", it.first.c_str());
	LOG("end \n\n");
}
#endif // !LOGGING

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
	_textures.insert(std::make_pair(pathToTexture, loadedTex));

#ifdef LOGGING
	logListOfTextures(_textures);
#endif
	return loadedTex;
}

void TextureManager::unloadTexture(std::string pathToTexture)
{
	if (pathToTexture.empty()) {
		return;
	}	
	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) // if texture is finded -> return it
		_textures.erase(pathToTexture);

#ifdef LOGGING
	logListOfTextures(_textures);
#endif
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
	if (it == _textures.end()) {
		return;
	}
	unloadTexture(it->first);
}