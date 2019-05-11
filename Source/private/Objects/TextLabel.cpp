#include <Core/GlobalDefines.h>
#include <Objects/TextLabel.h>

TextLabel::TextLabel(const std::string& _fontPath, int _fsize, const std::string& _text)
	: m_fontPath(_fontPath)
	, m_fontSize(_fsize)
	, m_contentText(_text)
{
	m_textColor = { 255, 255, 255 };

	m_font = TTF_OpenFont(m_fontPath.c_str(), m_fontSize);
	if (m_font == NULL) {
		LOG(TTF_GetError());
		exit(1);
	}
	m_surface = TTF_RenderText_Solid(m_font, m_contentText.c_str(), m_textColor);
	m_texture = SDL_CreateTextureFromSurface(
		Keeper::getInstance().getRenderer(), m_surface);
	SDL_QueryTexture(m_texture, NULL, NULL, &m_labelRealSize.width,
		&m_labelRealSize.height);
}

TextLabel::TextLabelPtr TextLabel::create(const std::string& _fontPath, int _fsize, const std::string& _text) {
	return std::make_shared<TextLabel>(_fontPath, _fsize, _text);
}

TextLabel::~TextLabel() {
	TTF_CloseFont(m_font);
	_clearSurface();
}

void TextLabel::_updateSurface() {
	_clearSurface();

	m_surface = TTF_RenderText_Solid(m_font, m_contentText.c_str(), m_textColor);
	m_texture = SDL_CreateTextureFromSurface(
		Keeper::getInstance().getRenderer(), m_surface);
	SDL_QueryTexture(m_texture, NULL, NULL, &m_labelRealSize.width,
		&m_labelRealSize.height);
}

void TextLabel::_clearSurface() {
	SDL_DestroyTexture(m_texture);
	SDL_FreeSurface(m_surface);
}

void TextLabel::onDraw() {
	SDL_Rect texr;
	texr.w = m_labelRealSize.width  * Node::getScaleX();
	texr.h = m_labelRealSize.height * Node::getScaleY();
	texr.x = Node::getPositionX() - Node::getAnchorPoint().x * texr.w;
	texr.y = Node::getPositionY() - Node::getAnchorPoint().y * texr.h;

	SDL_RenderCopyEx(Keeper::getInstance().getRenderer(), m_texture, nullptr,
		&texr, Node::getRotation(), nullptr,
		Node::getFlipState().getSDLFlip());
}

void TextLabel::setString(const std::string& _newText) {
	m_contentText = _newText;
	_updateSurface();
}

const std::string& TextLabel::getString() {
	return m_contentText;
}

void TextLabel::setColor(const SDL_Color& _color) {
	m_textColor = _color;
	_updateSurface();
}

const SDL_Color& TextLabel::getColor() {
	return m_textColor;
}

void TextLabel::setFontSize(int _fsize) {
	TTF_CloseFont(m_font);
	m_fontSize = _fsize;

	m_font = TTF_OpenFont(m_fontPath.c_str(), m_fontSize);
	if (m_font == NULL) {
		LOG(TTF_GetError());
		exit(1);
	}
	_updateSurface();
}

int TextLabel::getFontSize() const {
	return m_fontSize;
}

void TextLabel::setFontPath(const std::string& _newFontPath) {
	TTF_CloseFont(m_font);
	m_fontPath = _newFontPath;

	m_font = TTF_OpenFont(m_fontPath.c_str(), m_fontSize);
	if (m_font == NULL) {
		LOG(TTF_GetError());
		exit(1);
	}

	_updateSurface();
}

const std::string& TextLabel::getFontPath() const {
	return m_fontPath;
}

const Size& TextLabel::getRealSize() const {
	return m_labelRealSize;
}
