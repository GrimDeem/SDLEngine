#include "../../include/Objects/TextLabel.h"
	
TextLabel::TextLabel(std::string _fontPath, int fsize, std::string _text)
	: fontPath(_fontPath)
	, fontSize(fsize)
	, contentText(_text)
{
	textColor = { 255, 255, 255 };
	updateTexture();
}

TextLabel::TextLabelPtr TextLabel::create(std::string _fontPath, int fsize, std::string _text)
{
	auto newLabel = new TextLabel(_fontPath, fsize, _text);
	return std::make_shared<TextLabel>(*newLabel);

//	return std::make_shared<TextLabel>(TextLabel(_fontPath, fsize, _text));
}

TextLabel::~TextLabel()
{
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
}

void TextLabel::updateTexture()
{
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if(font == NULL){
		LOG(TTF_GetError());
		exit(1);
	}
	
	surface = TTF_RenderText_Solid(font, contentText.c_str(), textColor);
        texture = SDL_CreateTextureFromSurface(
		Keeper::getInstance().getRenderer(), surface);
	SDL_QueryTexture(texture, NULL, NULL, &labelRealSize.width,
			 &labelRealSize.height);
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
	updateTexture();
}

std::string TextLabel::getString()
{
	return contentText;
}

void TextLabel::setColor(SDL_Color color)
{
	textColor = color;
	updateTexture();
}

SDL_Color TextLabel::getColor()
{
	return textColor;
}
	
void TextLabel::setFontSize(int fsize)
{
	fontSize = fsize;
	updateTexture();
}

int TextLabel::getFontSize()
{
	return fontSize;
}

void TextLabel::setFontPath(std::string newFontPath)
{
	fontPath = newFontPath;
	updateTexture();
}

std::string TextLabel::getFontPath()
{
	return fontPath;
}

