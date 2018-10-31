#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "TEAL/CommonElements.h"
#include "AwesomeFont.h"

class TextEditor : public GameObject
{
public:
	static void CurrentScore(const unsigned int score);
	static void WaveLevel(const int levelNum);
	static void WriteText(const char &str, const sf::Vector2f &pos);

private:
	TextEditor();
	void ScoreToText(const unsigned int score);
	void waveToText(const int levelNum);

	virtual void Draw() override;

	static TextEditor* GetInstance();

	static TextEditor* instance;
	AwesomeFont myFont;

	Glyph *scoreGlyph;
	Glyph *waveGlyph;
	sf::Vector2f startingPos_Score;
	sf::Vector2f startingPos_Wave;
	unsigned int sizeFont;
	///this is simply to remove magic numbers
	const int DEFAULT_SIZE = 6;

	std::vector<Glyph> listOfGlyphs;
};

#endif // TEXTEDITOR_H
