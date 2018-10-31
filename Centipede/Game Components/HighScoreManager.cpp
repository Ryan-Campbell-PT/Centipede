#include "HighScoreManager.h"
#include "TEAL/WindowManager.h"
#include "GameGrid.h"
#include "TextEditor.h"

HighScoreManager* HighScoreManager::instance = nullptr;

HighScoreManager::HighScoreManager()
	:startingPos(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, SPRITE_SIZE * 3))
{
	for(int i = 0; i < 6; ++i)
		this->highScoreList.emplace_back(12345, "");
}

void HighScoreManager::AddScore(const int & score)
{
	//todo
#if false
	HighScoreManager r;
	if (score > r.highScoreList[r.highScoreList.size() - 1].score)
	{
		//r.highScoreList.empl
	}
	std::set<int> s;

	r.highScoreList.erase(r.highScoreList.begin(), r.highScoreList.end() + r.highScoreList.size())
#endif
}

int HighScoreManager::GetHighScore()
{
	return GetInstance()->highScoreList[0].score;
}

HighScoreManager * HighScoreManager::GetInstance()
{
	if(instance == nullptr)
		instance = new HighScoreManager;

	return instance;
}

void HighScoreManager::setupScores()
{
	//first start with displaying current high score
	auto hs = Tools::ToString(this->highScoreList[0].score);
	auto startingPos = sf::Vector2f(WindowManager::MainWindow.getSize().x / SPRITE_SIZE, SPRITE_SIZE);
	//todo: look at ign and find how to place the text
	for(auto i = 0; i < hs.size() - 1; ++i)
	{
		
	}
}
