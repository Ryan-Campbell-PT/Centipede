#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <vector>
#include <set>
#include <SFML/System/Vector2.hpp>
#include "Glyph.h"
#include "TEAL/GameObject.h"
struct HighScore;

class HighScoreManager : public GameObject
{
public:
	struct HighScore
	{
		HighScore(const int &score, const std::string &str)
			:score(score), text(str) {}

		bool operator > (const HighScore &hs) const
		{
			return this->score > hs.score;
		}

		int score;
		std::string text;
	};	

	//this will compare the current score list to see if it fits anywhere
	static void AddScore(const int &score);
	static int GetHighScore();
	static std::vector<HighScore> GetHighScoreList();

	static void WriteHighScoreList(); //displays the attractor mode high score
	static void WriteHighScore(); //displays the top high score
private:

	HighScoreManager();
	static HighScoreManager* GetInstance();

	virtual void Draw() override;

	void setupScores();
	void writeHighScoreList();

	static HighScoreManager *instance;
	std::vector<HighScore> highScoreList;
	sf::Vector2f startingPos_HS; //the top high score displayed throughout the entire game
	std::vector<Glyph> highScoreCharacters;
	sf::Vector2f startingPos_List; //the list viewed in attractor mode
};

#endif // HIGHSCOREMANAGER_H
