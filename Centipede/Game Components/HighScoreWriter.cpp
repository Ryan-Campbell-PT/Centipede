#include "HighScoreWriter.h"
#include "GameGrid.h"
#include "TextEditor.h"

HighScoreWriter * HighScoreWriter::instance = nullptr;

HighScoreWriter::HighScoreWriter()
	:maxCharacters_Dynamic(5), currentScoreSize_Dynamic(0)
{
	this->highScore_Dynamic = new Glyph[maxCharacters_Dynamic];
	this->startingPosition_List = sf::Vector2f(
		WindowManager::MainWindow.getSize().x / 2.f - SPRITE_SIZE * 2, WindowManager::MainWindow.getSize().y / 3.f);
	this->startingPos_DynamicHS = sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f - SPRITE_SIZE, 0.f);

	GameGrid::GetCenterGridPosition(this->startingPosition_List);
	GameGrid::GetCenterGridPosition(this->startingPos_DynamicHS);
}

HighScoreWriter * HighScoreWriter::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new HighScoreWriter;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void HighScoreWriter::Draw()
{
	for (auto hs : this->highScoreList_Characters)
		hs.Draw();

	for (unsigned int i = 0; i < currentScoreSize_Dynamic; i++)
		this->highScore_Dynamic[i].Draw();
}

void HighScoreWriter::drawHighScore(const int& score)
{
	auto hs = Tools::ToString(score);
	this->currentScoreSize_Dynamic = hs.size();
	auto tmpStart = this->startingPos_DynamicHS; //dont want to modify the real starting pos (for when we write again)

	for (unsigned int i = 0; i < this->currentScoreSize_Dynamic; i++)
	{
		this->highScore_Dynamic[i] = TextEditor::WriteText(hs.at(i), tmpStart);
		
		tmpStart.x += SPRITE_SIZE;
	}
}

void HighScoreWriter::drawHighScoreList(const std::vector<HighScoreManager::HighScore>& scoreList)
{
	auto tmpPos = startingPosition_List; //dont want to modify current position

	//bring me the loops, bruder
	for (unsigned int i = 0; i < scoreList.size() ; i++)
	{
		std::string scoreText;
		
		if (scoreList[i].score == 0)
			for (unsigned int i = 0; i < this->maxCharacters_Dynamic; i++)
				scoreText += '0'; //add a bunch of 0's because just having score == 0 will only be one char
		else
			scoreText = Tools::ToString(scoreList[i].score);

		for (unsigned int j = 0; j < scoreText.size(); j++)
		{//write the score to the left of the starting position
			auto g = TextEditor::WriteText(scoreText.at(scoreText.size() - j - 1), sf::Vector2f(tmpPos.x - (SPRITE_SIZE * j), tmpPos.y));
			this->highScoreList_Characters.push_back(g);
		}

		//string
		for (unsigned int j = 0; j < scoreList[i].text.size(); j++)
		{//write the text associated with it to the right
			auto g = TextEditor::WriteText(scoreList[i].text.at(j), sf::Vector2f(tmpPos.x + SPRITE_SIZE * 2 + (SPRITE_SIZE * j), tmpPos.y));

			this->highScoreList_Characters.push_back(g);
		}

		tmpPos.y += SPRITE_SIZE;

	}
}

void HighScoreWriter::DrawHighScore(const int & score)
{
	GetInstance()->drawHighScore(score);
}

void HighScoreWriter::DrawHighScoreList(const std::vector<HighScoreManager::HighScore>& scoreList)
{
	GetInstance()->drawHighScoreList(scoreList);
}

void HighScoreWriter::Cleanup()
{	
	for(auto f : GetInstance()->highScoreList_Characters)
	{
		f.Cleanup(); //do whatever necessary to remove from screen
		instance->highScoreList_Characters.pop_back(); //remove from list
	}
}

void HighScoreWriter::Terminate(GameObject*)
{
	delete instance;
	instance = nullptr;
}
