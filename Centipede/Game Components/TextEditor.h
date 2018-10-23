#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "TEAL/CommonElements.h"
#include "AwesomeFont.h"

class TextEditor : public GameObject
{
public:
	static void CurrentScore(const unsigned int score);

private:
	TextEditor();
	void ScoreToText(const unsigned int score);

	virtual void Draw() override;

	static TextEditor* GetInstance();

	static TextEditor* instance;
	AwesomeFont myFont;

	Glyph *glyphLink;
	sf::Vector2f startingPos;
	unsigned int sizeFont;
};

#endif // TEXTEDITOR_H
