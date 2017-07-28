#pragma once
#ifndef __TEXT_LABEL_H__
#define __TEXT_LABEL_H__

#include "Node.h"
#include "SDL_ttf.h"
#include "../Managers/Keeper.h"

/*
	TextLabel is a simple text rendered on surface.
*/
class TextLabel : public Node
{
public:
	typedef std::shared_ptr<TextLabel> TextLabelPtr;
private:
	std::string fontPath;
	std::string contentText;
	int fontSize;	
	Size labelRealSize;
	
	TTF_Font * font;
	SDL_Texture * texture;
	SDL_Surface * surface;
	SDL_Color textColor;
	
protected:
	/*func should be called every time when any of this is chnged:
	  -fontPath
	  -fontSize
	  -textContent
	  -textColor
	*/
	virtual void updateSurface();
	virtual void clearSurface();
public:
	TextLabel(std::string _fontPath, int fsize, std::string _text);

	static TextLabelPtr create(std::string _fontPath, int fsize, std::string _text);
	virtual ~TextLabel();
	
	virtual void draw() override;


	/*
	  @brief sets new text content to a label
	 */
	virtual void setString(std::string _newText);
	virtual std::string getString();

	/*
	  @brief sets new font color to a text label
	 */
	virtual void setColor(SDL_Color _color);
	virtual SDL_Color getColor();
	
	/*
	  @brief sets new font size to a text label
	 */
	virtual void setFontSize(int fsize);
	virtual int getFontSize();

	/*
	  @brief sets new font to a label loaded from dedicated path
	 */
	virtual void setFontPath(std::string newFontPath);
	virtual std::string getFontPath();
};

#endif __TEXT_LABEL_H__
