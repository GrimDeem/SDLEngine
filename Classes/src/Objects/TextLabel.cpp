#include "Objects/TextLabel.h"

TextLabel::TextLabel(std::string _fontPath, int fsize, std::string _text)
	: fontPath(_fontPath)
	, fontSize(fsize)
	, contentText(_text)
{
	textColor = { 255, 255, 255 };

	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL) {
		LOG(TTF_GetError());
		exit(1);
	}
	surface = TTF_RenderText_Solid(font, contentText.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(
		Keeper::getInstance().getRenderer(), surface);
	SDL_QueryTexture(texture, NULL, NULL, &labelRealSize.width,
		&labelRealSize.height);
}

TextLabel::TextLabelPtr TextLabel::create(std::string _fontPath, int fsize, std::string _text)
{
	return std::make_shared<TextLabel>(_fontPath, fsize, _text);
}

TextLabel::~TextLabel()
{
	TTF_CloseFont(font);
	clearSurface();
}

void TextLabel::updateSurface()
{
	clearSurface();

	surface = TTF_RenderText_Solid(font, contentText.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(
		Keeper::getInstance().getRenderer(), surface);
	SDL_QueryTexture(texture, NULL, NULL, &labelRealSize.width,
		&labelRealSize.height);
}

void TextLabel::clearSurface()
{
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void TextLabel::draw()
{
	Node::draw();

	SDL_Rect texr;
	texr.w = labelRealSize.width  * Node::getScaleX();
	texr.h = labelRealSize.height * Node::getScaleY();
	texr.x = Node::getPositionX() - Node::getAnchorPoint().x * texr.w;
	texr.y = Node::getPositionY() - Node::getAnchorPoint().y * texr.h;

	SDL_RenderCopyEx(Keeper::getInstance().getRenderer(), texture, nullptr,
		&texr, Node::getRotation(), nullptr,
		Node::getFlipState().getSDLFlip());
}

void TextLabel::setString(std::string _newText)
{
	contentText = _newText;
	updateSurface();
}

std::string TextLabel::getString()
{
	return contentText;
}

void TextLabel::setColor(SDL_Color color)
{
	textColor = color;
	updateSurface();
}

SDL_Color TextLabel::getColor()
{
	return textColor;
}

void TextLabel::setFontSize(int fsize)
{
	TTF_CloseFont(font);
	fontSize = fsize;

	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL) {
		LOG(TTF_GetError());
		exit(1);
	}
	updateSurface();
}

int TextLabel::getFontSize()
{
	return fontSize;
}

void TextLabel::setFontPath(std::string newFontPath)
{
	TTF_CloseFont(font);
	fontPath = newFontPath;

	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL) {
		LOG(TTF_GetError());
		exit(1);
	}

	updateSurface();
}

std::string TextLabel::getFontPath()
{
	return fontPath;
}

const Size TextLabel::getRealSize() const
{
	return labelRealSize;
}
