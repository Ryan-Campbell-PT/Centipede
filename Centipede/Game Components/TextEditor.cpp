#include "TextEditor.h"
#include "GameGrid.h"
#include "HighScoreManager.h"

TextEditor* TextEditor::instance = nullptr;

Glyph TextEditor::WriteText(const char & str, const sf::Vector2f & pos)
{
	return GetInstance()->myFont.GetGlyph(str, pos);
}

//void TextEditor::Terminate(GameObject*)
//{
//	delete instance;
//	instance = nullptr;
//}

TextEditor * TextEditor::GetInstance()
{
	if (instance == nullptr)
		instance = new TextEditor;

	return instance;
}
