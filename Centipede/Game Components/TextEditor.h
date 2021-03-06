#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "TEAL/CommonElements.h"
#include "AwesomeFont.h"
#include "HighScoreManager.h"

class TextEditor
{
public:
	static Glyph WriteText(const char &str, const sf::Vector2f &pos);

	static void Terminate();

private:
	TextEditor() = default;

	static TextEditor* GetInstance();

	static TextEditor* instance;
	AwesomeFont myFont;
};

#endif // TEXTEDITOR_H
