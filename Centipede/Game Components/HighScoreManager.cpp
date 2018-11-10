#include "HighScoreManager.h"
#include "TEAL/WindowManager.h"
#include "GameGrid.h"
#include "TextEditor.h"
#include "ScoreManager.h"
#include "HighScoreWriter.h"


#define WRITER true
HighScoreManager* HighScoreManager::instance = nullptr;

HighScoreManager::HighScoreManager()	
	:maxSizeScores(5)
{	
	for (unsigned int i = 0; i < maxSizeScores; ++i)
		this->highScoreList.emplace_back(0, "doi");

	this->currentHighScore = this->highScoreList[0].score;
}

void HighScoreManager::AddScore(const unsigned int & score)
{
	if (GetInstance()->currentHighScore < score)
	{
		instance->currentHighScore = score;
		HighScoreWriter::DrawHighScore(score);
	}
}

int HighScoreManager::GetHighScore()
{
	if (!GetInstance()->highScoreList.empty())
		return GetInstance()->highScoreList[0].score;

	return 0;
}

std::vector<HighScoreManager::HighScore> HighScoreManager::GetHighScoreList()
{
	return GetInstance()->highScoreList;
}

void HighScoreManager::WriteHighScoreList()
{
	HighScoreWriter::DrawHighScoreList(GetInstance()->highScoreList);
}

void HighScoreManager::WriteHighScore()
{
	HighScoreWriter::DrawHighScore(GetInstance()->GetHighScore());
}

void HighScoreManager::EndWave()
{
	GetInstance()->endWave();
}

void HighScoreManager::Cleanup()
{
	HighScoreWriter::Cleanup();
}

void HighScoreManager::EndGame()
{
	GetInstance()->endWave();
}

HighScoreManager * HighScoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new HighScoreManager;

	return instance;
}

void HighScoreManager::endWave()
{
	const auto curScore = ScoreManager::GetCurrentScore();

	if (curScore < this->highScoreList[this->maxSizeScores - 1].score)
		return; //cant place anywhere in list, so dont do anything

	else if (curScore > this->highScoreList[0].score)
	{ //if the current score is greater than the current high score
		for (unsigned int i = 0; i < this->maxSizeScores - 1; i++)
		{ //move all the high scores down one place
			this->highScoreList[i + 1] = this->highScoreList[i];
		}
		//todo: you will need to somehow take user input
		this->setHighScore(0, curScore);
	}

	else
	{ // the current score is somewhere inbetween
		unsigned int i = 0;
		while (i < this->maxSizeScores - 1)
		{
			if (this->highScoreList[i].score > curScore && this->highScoreList[i + 1].score < curScore)
			{ //high score should be placed in between these two scores
				this->setHighScore(i, curScore);

				//now move everything down one, from the place we are at in the current loop
				//(it looks like a nested for loop, but its not)
				while(i < this->maxSizeScores - 1)
				{//after this loop, above loop should end because i > maxSizeScore
					this->highScoreList[i + 1] = this->highScoreList[i];
					++i;
				}
					
			}
			++i;
		}
	}

}

void HighScoreManager::setHighScore(const int& place, const int& score, const std::string& user)
{
	this->highScoreList[place].score = score;
	if(user.empty())
	{
		this->highScoreList[place].text = this->requestUserName();
	}

	else
		this->highScoreList[place].text = user;
}

std::string HighScoreManager::requestUserName()
{
	//todo
	return "";
}
