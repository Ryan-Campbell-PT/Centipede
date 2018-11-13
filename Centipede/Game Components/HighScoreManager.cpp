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

void HighScoreManager::SetCurrentUserName(const std::string& username)
{
	GetInstance()->highScoreList[instance->highScoreList.size() - 1].text = username;
}

bool HighScoreManager::IsHighScore()
{
	return ScoreManager::GetCurrentScore() > GetInstance()->highScoreList[instance->maxSizeScores - 1].score;
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

	//if we arent less than the lowest one, then set the high score at the lowest score,
	//therefor pushing it off the score list all together
	//todo;: you have to figure out a way to confirm the text entered in userinputmanager
	this->setHighScore(this->maxSizeScores - 1, curScore);
}

void HighScoreManager::setHighScore(const int& place, const int& score)
{
	this->highScoreList[place].score = score;

	std::sort(this->highScoreList.begin(), this->highScoreList.end());
}

std::string HighScoreManager::requestUserName()
{
	//todo
	return "";
}
