#include <Managers/TextureManager.h>

TextureManager::~TextureManager() {
	clearTexturePool();
}

#if __TM_LOG__ >= 1
void logListOfTextures(std::unordered_map<std::string, SDL_Texture*> _textures) {
	LOG("List of textures: \n");
	for (auto &it : _textures)
		LOG("%s \n", it.first.c_str());
	LOG("end \n\n");
}
#endif // !__TM_LOG__

SDL_Texture * TextureManager::getTexture(const std::string& _pathToTexture) {
	if (!_pathToTexture.empty()) {
		auto it = m_textures.find(_pathToTexture);
		if (it != m_textures.end())
			return it->second;	// if texture is finded -> return it
		else
			return _loadTexture(_pathToTexture);  //else -> add to map and return
	}
	assert(false);
}

SDL_Texture * TextureManager::_loadTexture(const std::string& _pathToTexture) {
	auto loadedTex = IMG_LoadTexture(Keeper::getInstance().getRenderer(), _pathToTexture.c_str());
	if(loadedTex == nullptr)
		LOG(IMG_GetError());
	m_textures.insert(std::make_pair(_pathToTexture, loadedTex));
	return loadedTex;
}

void TextureManager::unloadTexture(const std::string& _pathToTexture) {
	if (!_pathToTexture.empty()) {
		_texturesIterator it = m_textures.find(_pathToTexture);
		if (it != m_textures.end()) {  // if texture is finded -> return it
			SDL_DestroyTexture(it->second);
			m_textures.erase(it);
		}
	}
}

void TextureManager::unloadTexture(SDL_Texture * _texture) {
	if (_texture != nullptr) {
		auto it = std::find_if(m_textures.begin(), m_textures.end(),
			[&_texture](const std::unordered_map<std::string, SDL_Texture*>::value_type& value)
		{
			return value.second == _texture;
		});
		if (it != m_textures.end())
			unloadTexture(it->first);
	}
}

void TextureManager::clearTexturePool() {
	for(auto& tex : m_textures)
		SDL_DestroyTexture(tex.second);
	m_textures.clear();
}
