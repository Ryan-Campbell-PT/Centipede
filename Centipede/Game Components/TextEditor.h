#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "TEAL/CommonElements.h"
#include "AwesomeFont.h"
#include "HighScoreManager.h"

class TextEditor : public GameObject
{
public:
	static void CurrentScore(const unsigned int score);
	//static void WaveLevel(const int levelNum);
	static Glyph WriteText(const char &str, const sf::Vector2f &pos);
	static void AttractorMode(const bool &t);
	static void WriteHighScores(std::vector<HighScoreManager::HighScore> highScoreList, sf::Vector2f startingPos);
	
private:
	TextEditor();
	void ScoreToText(const unsigned int score);
	void waveToText(const int levelNum);
	void writeHighScores(std::vector<HighScoreManager::HighScore> highScoreList, sf::Vector2f startingPos);

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
	const int SCORE_SIZE = 6;
	const int WAVE_SIZE = 2;

	bool attractorMode;
	std::vector<Glyph> attractorGlyphs;
};

#endif // TEXTEDITOR_H
