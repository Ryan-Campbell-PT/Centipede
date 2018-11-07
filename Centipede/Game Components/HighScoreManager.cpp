#include "HighScoreManager.h"
#include "TEAL/WindowManager.h"
#include "GameGrid.h"
#include "TextEditor.h"
#include "ScoreManager.h"

HighScoreManager* HighScoreManager::instance = nullptr;

HighScoreManager::HighScoreManager()	
	:maxSizeScores(5)
{
	startingPos_HS = sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, 0);
	startingPos_List = sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, SPRITE_SIZE * 6);
	GameGrid::GetCenterGridPosition(startingPos_HS);
	GameGrid::GetCenterGridPosition(startingPos_List);
	
	for (unsigned int i = 0; i < maxSizeScores; ++i)
		this->highScoreList.emplace_back(0, "doi");

	this->currentHighScore = this->highScoreList[0].score;
}

void HighScoreManager::AddScore(const unsigned int & score)
{
	if (GetInstance()->currentHighScore < score)
		instance->currentHighScore = score;
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
	GetInstance()->writeHighScoreList();
}

void HighScoreManager::WriteHighScore()
{
	auto hs = Tools::ToString(GetInstance()->GetHighScore());
	auto tmpStart = instance->startingPos_HS; //dont want to modify the real starting pos (for when we write again)

	for (unsigned int i = 0; i < hs.size(); i++)
	{
		instance->highScoreCharacters.push_back(
			TextEditor::WriteText(hs.at(hs.size() - i - 1), instance->startingPos_HS)
		);
		tmpStart.x += SPRITE_SIZE * i;
		//instance->startingPos_HS.y
	}
}

void HighScoreManager::EndWave()
{
	GetInstance()->endWave();
}

void HighScoreManager::Terminate(GameObject*)
{
	delete instance;
	instance = nullptr;
}

HighScoreManager * HighScoreManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new HighScoreManager;
		instance->SetExternalManagement(Terminate);
	}

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
	//bring me the loops, bruder
	for (auto hs : this->highScoreList)
	{
		std::string scoreText;
		if (hs.score == 0)
			for (unsigned int i = 0; i < this->maxSizeScores; i++)
				scoreText += '0'; //add a bunch of 0's because just having score == 0 will only be one char
		else
			scoreText = Tools::ToString(hs.score);

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

void HighScoreManager::endWave()
{
	const auto curScore = ScoreManager::GetCurrentScore();

	if (curScore < this->highScoreList[this->maxSizeScores].score)
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
