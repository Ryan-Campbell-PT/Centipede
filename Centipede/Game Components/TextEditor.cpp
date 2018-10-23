#include "TextEditor.h"

TextEditor* TextEditor::instance = nullptr;

TextEditor::TextEditor()
	: glyphLink(nullptr), startingPos(sf::Vector2f(200, 200)), sizeFont(0)
{
}

void TextEditor::CurrentScore(const unsigned int score)
{
	GetInstance()->ScoreToText(score);
}

void TextEditor::ScoreToText(const unsigned int score)
{	
	auto scoreText = Tools::ToString(score);

	delete[] glyphLink;

	glyphLink = new Glyph[(sizeFont = scoreText.size())];

	for(auto iter = 0; iter < sizeFont; ++iter)
	{
		glyphLink[iter] = myFont.GetGlyph(scoreText.at(sizeFont - iter - 1), 
			sf::Vector2f(startingPos.x - (iter * myFont.CellWidth()), startingPos.y));


	}

}

void TextEditor::Draw()
{
	for(auto i = 0; i < sizeFont; ++i)
		this->glyphLink[i].Draw();
}

TextEditor * TextEditor::GetInstance()
{
	if(instance == nullptr)
		instance = new TextEditor;

	return instance;
}
