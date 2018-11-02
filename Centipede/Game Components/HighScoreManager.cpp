#include "HighScoreManager.h"
#include "TEAL/WindowManager.h"
#include "GameGrid.h"
#include "TextEditor.h"

HighScoreManager* HighScoreManager::instance = nullptr;

HighScoreManager::HighScoreManager()
	:startingPos_HS(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, SPRITE_SIZE)),
	startingPos_List(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, SPRITE_SIZE * 6))
{
	for (int i = 0; i < 6; ++i)
		this->highScoreList.emplace_back(12345, "doi");
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
	if (!GetInstance()->highScoreList.empty())
		return GetInstance()->highScoreList[0].score;

	return -1;
}

std::vector<HighScoreManager::HighScore> HighScoreManager::GetHighScoreList()
{
	return GetInstance()->highScoreList;
}

void HighScoreManager::WriteHighScoreList()
{
	GetInstance()->writeHighScoreList();
}

void HighScoreManager::WriteHighScore()
{
	auto hs = Tools::ToString(GetInstance()->GetHighScore());
	auto tmpStart = instance->startingPos_HS; //dont want to modify the real starting pos (for when we write again)

	for (unsigned int i = 0; i < hs.size(); i++)
	{
		instance->highScoreCharacters.push_back(
			TextEditor::WriteText(hs.at(i), instance->startingPos_HS)
		);
		tmpStart.x += SPRITE_SIZE * i;
		//instance->startingPos_HS.y
	}
}

HighScoreManager * HighScoreManager::GetInstance()
{
	if (instance == nullptr)
		instance = new HighScoreManager;

	return instance;
}

void HighScoreManager::Draw()
{
	for (auto hs : this->highScoreCharacters)
		hs.Draw();
}

void HighScoreManager::setupScores()
{
	/*	//first start with displaying current high score
		auto hs = Tools::ToString(this->highScoreList[0].score);
		auto startingPos = sf::Vector2f(WindowManager::MainWindow.getSize().x / SPRITE_SIZE, SPRITE_SIZE);
		//todo: look at ign and find how to place the text
		for(auto i = 0; i < hs.size() - 1; ++i)
		{

		}
		*/
}

void HighScoreManager::writeHighScoreList()
{
	for (auto hs : this->highScoreList)
	{
		auto scoreText = Tools::ToString(hs.score);

		for (unsigned int i = 0; i < scoreText.size(); i++)
		{//write the score to the left of the starting position
			auto g = TextEditor::WriteText(scoreText.at(scoreText.size() - 1 - i), sf::Vector2f(startingPos_List.x - (SPRITE_SIZE * i), startingPos_List.y));
			//this->attractorGlyphs.push_back(myFont.GetGlyph(, );
			this->highScoreCharacters.push_back(g);
		}

		//string
		for (unsigned int j = 0; j < hs.text.size(); j++)
		{//write the text associated with it to the right
			auto g = TextEditor::WriteText(hs.text.at(j), sf::Vector2f(startingPos_List.x + SPRITE_SIZE * 2 + (SPRITE_SIZE * j), startingPos_List.y));

			this->highScoreCharacters.push_back(g);
		}

		startingPos_List.y += SPRITE_SIZE;

	}
}
