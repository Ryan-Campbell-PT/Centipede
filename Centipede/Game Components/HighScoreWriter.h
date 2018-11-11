#ifndef HIGHSCOREWRITER_H
#define HIGHSCOREWRITER_H

#include "TEAL/CommonElements.h"
#include "Glyph.h"
#include "HighScoreManager.h"

class HighScoreWriter : public GameObject
{
public:

	static void DrawHighScore(const int &score);
	static void DrawHighScoreList(const std::vector<HighScoreManager::HighScore> &scoreList);

	static void Cleanup();

	static void Terminate(GameObject *);

private:
	HighScoreWriter();
	static HighScoreWriter* GetInstance();
	static HighScoreWriter* instance;

	virtual void Draw() override;

	void drawHighScore(const int &score);
	void drawHighScoreList(const std::vector<HighScoreManager::HighScore> &scoreList);

	std::vector<Glyph> highScoreList_Characters; //all the glyphs that hold the high score list in attractor mode
	sf::Vector2f startingPosition_List; //starting position to place those glyphs
	Glyph *highScore_Dynamic; //the dynamic score at the top of the screen during all time of play
	sf::Vector2f startingPos_DynamicHS; //the starting position for those glyps

	unsigned int maxCharacters_Dynamic; //the maximum number of characters avaliable in a given score (never can get to 100k)
	unsigned int currentScoreSize_Dynamic;
};

#endif // HIGHSCOREWRITER_H
