#include "TextEditor.h"

TextEditor* TextEditor::instance = nullptr;

TextEditor::TextEditor()
	: sizeFont(0)
{
	//the concept of this is that we allocate a size that the player will likely get,
	//and just change the contents of the pointer as we add points
	this->glyphLink = new Glyph[this->DEFAULT_SIZE];
	startingPos = sf::Vector2f(static_cast<float>(WindowManager::MainWindow.getSize().x - this->myFont.CellWidth()),
	                           static_cast<float>(this->myFont.CellHeight()));
}

void TextEditor::CurrentScore(const unsigned int score)
{
	GetInstance()->ScoreToText(score);
}

void TextEditor::ScoreToText(const unsigned int score)
{	
	auto scoreText = Tools::ToString(score);
	this->sizeFont = scoreText.size();
	//delete[] glyphLink;

	//glyphLink = new Glyph[(sizeFont = scoreText.size())];

	for(unsigned int iter = 0; iter < sizeFont; ++iter)
	{
		//simply change the contents of the array to the numbers in the given score
		glyphLink[iter] = myFont.GetGlyph(scoreText.at(sizeFont - iter - 1), 
			sf::Vector2f(startingPos.x - (iter * myFont.CellWidth()), startingPos.y));


	}

}

void TextEditor::Draw()
{
	for(unsigned int i = 0; i < sizeFont; ++i)
		this->glyphLink[i].Draw();
}

TextEditor * TextEditor::GetInstance()
{
	if(instance == nullptr)
		instance = new TextEditor;

	return instance;
}
