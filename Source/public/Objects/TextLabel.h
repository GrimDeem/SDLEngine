#pragma once
#ifndef __TEXT_LABEL_H__
#define __TEXT_LABEL_H__

#include <SDL_ttf.h>
#include <Objects/Node.h>
#include <Managers/Keeper.h>

/*
TextLabel is a simple text rendered on surface.
*/
class TextLabel : public Node
{
public:
	typedef std::shared_ptr<TextLabel> TextLabelPtr;
private:
	std::string m_fontPath;
	std::string m_contentText;
	int m_fontSize;
	Size m_labelRealSize;

	TTF_Font* m_font;
	SDL_Texture* m_texture;
	SDL_Surface* m_surface;
	SDL_Color m_textColor;

protected:
	/*func should be called every time when any of this is chnged:
	-fontPath
	-fontSize
	-textContent
	-textColor
	*/
	virtual void _updateSurface();
	virtual void _clearSurface();
public:
	TextLabel(const std::string& _fontPath, int _fsize, const std::string& _text);
	static TextLabelPtr create(const std::string& _fontPath, int _fsize, const std::string& _text);
	virtual ~TextLabel();

	virtual void draw() override;


	/*
	@brief sets new text content to a label
	*/
	virtual void setString(const std::string& _newText);
	virtual const std::string& getString();

	/*
	@brief sets new font color to a text label
	*/
	virtual void setColor(const SDL_Color& _color);
	virtual const SDL_Color& getColor();

	/*
	@brief sets new font size to a text label
	*/
	virtual void setFontSize(int _fsize);
	virtual int getFontSize() const;

	/*
	@brief sets new font to a label loaded from dedicated path
	*/
	virtual void setFontPath(const std::string& _newFontPath);
	virtual const std::string& getFontPath() const;

	virtual const Size& getRealSize() const;
};

#endif __TEXT_LABEL_H__
