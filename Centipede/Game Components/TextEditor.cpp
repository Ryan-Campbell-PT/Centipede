#include "TextEditor.h"
#include "GameGrid.h"

TextEditor* TextEditor::instance = nullptr;

TextEditor::TextEditor()
	: sizeFont(0)
{
	//the concept of this is that we allocate a size that the player will likely get,
	//and just change the contents of the pointer as we add points
	this->scoreGlyph = new Glyph[this->DEFAULT_SIZE];
	this->waveGlyph = new Glyph[this->DEFAULT_SIZE];

	this->startingPos_Score = sf::Vector2f(
		static_cast<float>(WindowManager::MainWindow.getSize().x - this->myFont.CellWidth()),
		static_cast<float>(this->myFont.CellHeight())
	); //top right

	this->startingPos_Wave = sf::Vector2f(
		static_cast<float>(this->myFont.CellWidth()),
		static_cast<float>(this->myFont.CellWidth())
	); //top left

	this->attractorF();
}

void TextEditor::CurrentScore(const unsigned int score)
{
	GetInstance()->ScoreToText(score);
}

void TextEditor::WaveLevel(const int levelNum)
{
	GetInstance()->waveToText(levelNum);
}

void TextEditor::WriteText(const char & str, const sf::Vector2f & pos)
{
	GetInstance()->listOfGlyphs.push_back(
		instance->myFont.GetGlyph(str, pos)
	);
}

void TextEditor::AttractorMode(const bool & t)
{
	GetInstance()->attractorMode = t;
}

void TextEditor::ScoreToText(const unsigned int score)
{
	auto scoreText = Tools::ToString(score);
	this->sizeFont = scoreText.size();
	//delete[] scoreGlyph;

	//scoreGlyph = new Glyph[(sizeFont = scoreText.size())];

	for (unsigned int iter = 0; iter < sizeFont; ++iter)
	{
		//simply change the contents of the array to the numbers in the given score
		scoreGlyph[iter] = myFont.GetGlyph(scoreText.at(sizeFont - iter - 1),
			sf::Vector2f(startingPos_Score.x - (iter * myFont.CellWidth()), startingPos_Score.y));


	}

}

void TextEditor::waveToText(const int levelNum)
{
	auto levelChar = Tools::ToString(levelNum);

	for (unsigned int i = 0; i < levelChar.size(); ++i)
		waveGlyph[i] = myFont.GetGlyph(levelChar[i],
			sf::Vector2f(
				startingPos_Wave.x + (i * myFont.CellWidth()), startingPos_Wave.y));

}

void TextEditor::Draw()
{
	if (attractorMode)
	{
		for (auto t : this->attractorGlyphs)
			t.Draw();

	}

	else
	{
		//tood: fix all this in the future (sizeWave is one)
		for (unsigned int i = 0; i < sizeFont; ++i)
			this->scoreGlyph[i].Draw();

		for (unsigned int i = 0; i < 1; ++i)
			this->waveGlyph[i].Draw();

	}
	for(auto f : this->highscore)
		f.Draw();
}

TextEditor * TextEditor::GetInstance()
{
	if (instance == nullptr)
		instance = new TextEditor;

	return instance;
}

void TextEditor::attractorF()
{
	this->highScoreInfo.emplace_back(12345, "suh");
	this->highScoreInfo.emplace_back(78945, "dud");
	this->highScoreInfo.emplace_back(56482, "pen");

	auto startingPos = sf::Vector2f(WindowManager::MainWindow.getSize().x / 2 - (SPRITE_SIZE * 5), SPRITE_SIZE * 5);
	//auto firstScore = this->highScoreInfo.front();
	//auto scoreStr;// = Tools::ToString(firstScore.score);

	//display "high scores"
	std::string highScores = "High Scores";

	for(int i = 0; i < highScores.size(); i++)
	{
			this->attractorGlyphs.push_back(myFont.GetGlyph(highScores.at(i), sf::Vector2f(startingPos.x + (SPRITE_SIZE * i), startingPos.y)));
	}
	
	startingPos.y += SPRITE_SIZE;
	startingPos.x += SPRITE_SIZE * 5;
	for (auto hs : this->highScoreInfo)
	{
		auto scoreStr = Tools::ToString(hs.score);
		//score
		for (int i = 0; i < scoreStr.size(); i++)
		{
			this->attractorGlyphs.push_back(myFont.GetGlyph(scoreStr.at(scoreStr.size() - 1 - i), sf::Vector2f(startingPos.x - (SPRITE_SIZE * i), startingPos.y)));

		}
		//string
		for (int j = 0; j < hs.str.size(); j++)
		{
			this->attractorGlyphs.push_back(myFont.GetGlyph(hs.str.at(j), sf::Vector2f(startingPos.x + SPRITE_SIZE * 2 + (SPRITE_SIZE * j), startingPos.y)));
		}

		startingPos.y += SPRITE_SIZE;
	}

	startingPos.y = 0;
	startingPos.x -= SPRITE_SIZE * 2;
	auto highest = Tools::ToString(78945);
	
	for(int i = 0 ;i < highest.size(); i++)
		this->highscore.push_back(myFont.GetGlyph(highest.at(i), sf::Vector2f(startingPos.x + (SPRITE_SIZE * i), startingPos.y)));
}


