#include "..\..\include\Managers\TextureManager.h"

#ifdef LOG
void logListOfTextures(std::unordered_map<std::string, SDL_Texture*> _textures) {
	std::cout << "List of textures: \n" << std::endl;
	for (auto &it : _textures)
		std::cout << it.first.c_str() << std::endl;
	std::cout << "end \n" << std::endl;
}
#endif // !LOG

SDL_Texture * TextureManager::getTexture(std::string pathToTexture)
{
	if (pathToTexture.empty()) {
#ifdef LOG
		std::cout << "Place -> TextureManager::getTexture(std::string pathToTexture)\n" 
			<< "Event type: pathToTexture is empty\n" << pathToTexture.c_str() ;
#endif
		return nullptr;
	}

	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) { // if texture is finded -> return it
#ifdef LOG
		std::cout << "Place -> TextureManager::getTexture(std::string pathToTexture)\n"
			<< "Event type: finded old texture\n" << pathToTexture.c_str() ;
#endif
		return _textures.at(pathToTexture);
	}
								//else -> add to map and return
	auto texure = loadTexture(pathToTexture);
#ifdef LOG
	std::cout << "Place -> TextureManager::getTexture(std::string pathToTexture)\n"
		<< "Event type: loaded new texture\n" << pathToTexture.c_str() ;
#endif 
	return texure;
}

SDL_Texture * TextureManager::loadTexture(std::string pathToTexture)
{
	auto loadedTex = IMG_LoadTexture(Keeper::getInstance().getRenderer(), pathToTexture.c_str());
	_textures.insert(std::make_pair(pathToTexture, loadedTex));
#ifdef LOG
	logListOfTextures(_textures);
#endif
	return loadedTex;
}

void TextureManager::unloadTexture(std::string pathToTexture)
{
	if (pathToTexture.empty()) {
#ifdef LOG
		std::cout << "Place -> TextureManager::unloadTexture(std::string pathToTexture)\n"
			<< "Event type:  pathToTexture is empty\n" << pathToTexture.c_str() ;
#endif
		return;
	}
	
	auto it = _textures.find(pathToTexture);
	if (it != _textures.end()) // if texture is finded -> return it
		_textures.erase(pathToTexture);
	else {
#ifdef LOG
		std::cout << "Place -> TextureManager::unloadTexture(SDL_Texture * texture)\n"
			<< "Event type:  texture not finded\n" << pathToTexture.c_str();
#endif 
	}
#ifdef LOG
	logListOfTextures(_textures);
#endif
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
			<< "Event type:  texture not finded\n" << it->first.c_str() ;
#endif 
		return;
	}
	unloadTexture(it->first);
}

