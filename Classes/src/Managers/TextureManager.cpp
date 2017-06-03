#include "..\..\include\Managers\TextureManager.h"

SDL_Texture * TextureManager::getTexture(std::string pathToTexture)
{
	if (pathToTexture.empty()) {
#ifdef LOG
		std::cout << "Place -> TextureManager::getTexture(std::string pathToTexture)\n" 
			<< "Event type: pathToTexture is empty\n";
#endif
		return nullptr;
	}

	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) { // if texture is finded -> return it
#ifdef LOG
		std::cout << "Place -> TextureManager::getTexture(std::string pathToTexture)\n"
			<< "Event type: finded old texture\n";
#endif
		return _textures.at(pathToTexture);
	}
								//else -> add to map and return
	auto texure = loadTexture(pathToTexture);
#ifdef LOG
	std::cout << "Place -> TextureManager::getTexture(std::string pathToTexture)\n"
		<< "Event type: loaded new texture\n";
#endif 
	return texure;
}

SDL_Texture * TextureManager::loadTexture(std::string pathToTexture)
{
	auto loadedTex = IMG_LoadTexture(Keeper::getInstance().getRenderer(), pathToTexture.c_str());
	_textures.insert(std::make_pair(pathToTexture, loadedTex));
	return loadedTex;
}

void TextureManager::unloadTexture(std::string pathToTexture)
{
	if (pathToTexture.empty()) {
#ifdef LOG
		std::cout << "Place -> TextureManager::unloadTexture(std::string pathToTexture)\n"
			<< "Event type:  pathToTexture is empty\n";
#endif
		return;
	}

	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) // if texture is finded -> return it
		_textures.erase(pathToTexture);
	else {
#ifdef LOG
		std::cout << "Place -> TextureManager::unloadTexture(SDL_Texture * texture)\n"
			<< "Event type:  texture not finded\n";
#endif 
	}
}

void TextureManager::unloadTexture(SDL_Texture * texture)
{
	if (texture == nullptr) {
#ifdef LOG
		std::cout << "Place -> TextureManager::unloadTexture(SDL_Texture * texture)\n"
			<< "Event type:  texture == nullptr\n";
#endif
		return;
	}

	auto it = std::find_if(_textures.begin(), _textures.end(), [&texture](const std::unordered_map<std::string, SDL_Texture*>::value_type& value)
	{
		return value.second == texture;			
	});
	if (it == _textures.end()) {
#ifdef LOG
		std::cout << "Place -> TextureManager::unloadTexture(SDL_Texture * texture)\n"
			<< "Event type:  texture not finded\n";
#endif 
		return;
	}
	unloadTexture(it->first);
}
