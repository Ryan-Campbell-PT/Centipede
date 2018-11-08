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
	static void AddScore(const unsigned int &score);
	static int GetHighScore();
	static std::vector<HighScore> GetHighScoreList();

	static void WriteHighScoreList(); //displays the attractor mode high score
	static void WriteHighScore(); //displays the top high score

	//todo: this will take the current score from the ScoreManager, and save it in the highScoreList
	static void EndWave();
	static void Terminate(GameObject *);
	static void Cleanup();

private:

	HighScoreManager();
	static HighScoreManager* GetInstance();

	virtual void Draw() override;

	void setupScores();
	void writeHighScoreList();
	void endWave();
	void setHighScore(const int &place, const int &score, const std::string& user = "");
	///this function will pause the game and have the user type in their name for the high score
	std::string requestUserName();

	static HighScoreManager *instance;
	std::vector<HighScore> highScoreList; //the actual scores and "player names" associated 
	sf::Vector2f startingPos_HS; //the top high score displayed throughout the entire game
	std::vector<Glyph> highScoreCharacters; //all the characters on the screen at the time
	sf::Vector2f startingPos_List; //the list viewed in attractor mode

	unsigned int maxSizeScores; //the maximum number of characters avaliable in a given score (never can get to 100k)
	unsigned int currentHighScore;
};

#endif // HIGHSCOREMANAGER_H
