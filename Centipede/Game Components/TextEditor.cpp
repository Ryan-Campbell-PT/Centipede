#include "TextEditor.h"

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

	for(unsigned int i = 0; i < levelChar.size(); ++i)
		waveGlyph[i] = myFont.GetGlyph(levelChar[i],
			sf::Vector2f(
				startingPos_Wave.x + (i * myFont.CellWidth()), startingPos_Wave.y));

}

void TextEditor::Draw()
{
	//tood: fix all this in the future (sizeWave is one)
	for (unsigned int i = 0; i < sizeFont; ++i)
		this->scoreGlyph[i].Draw();

	for (unsigned int i = 0; i < 1; ++i)
		this->waveGlyph[i].Draw();
}

TextEditor * TextEditor::GetInstance()
{
	if (instance == nullptr)
		instance = new TextEditor;

	return instance;
}
