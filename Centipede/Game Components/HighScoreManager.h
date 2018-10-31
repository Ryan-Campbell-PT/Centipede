#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <vector>
#include <set>
#include <SFML/System/Vector2.hpp>

class HighScoreManager
{
public:
	//this will compare the current score list to see if it fits anywhere
	static void AddScore(const int &score);
	static int GetHighScore();

private:
	struct HighScore
	{
		HighScore(const int &score, const std::string str)
			:score(0), text(str) {}

		bool operator > (const HighScore &hs) const
		{
			return this->score > hs.score;
		}

		int score;
		std::string text;
	};


	HighScoreManager();
	static HighScoreManager* GetInstance();

	void setupScores();

	static HighScoreManager *instance;
	std::vector<HighScore> highScoreList;
	sf::Vector2f startingPos;
};

#endif // HIGHSCOREMANAGER_H
