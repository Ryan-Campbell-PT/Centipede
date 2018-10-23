// SpriteSheet
// Andre Berthiaume, May 2013

#include "SpriteSheet.h"
#include "TEAL\WindowManager.h" 

SpriteSheet::SpriteSheet( sf::Texture& tex, int CellCountHor, int CellCountVert )
	:SCALE(2.F)
{
	MainSprite = sf::Sprite(tex);
	MainSprite.setScale(SCALE, SCALE); //may have to change this when doing collision

	// Rectangle dimension corresponding to a single cell of the sprite sheet
	cellWidth = tex.getSize().x / CellCountHor;
	cellHeight = tex.getSize().y / CellCountVert;

	cells.resize(CellCountHor * CellCountVert);

	// Determine the rectangle for each cell
	int left;
	int top;
	for (int j = 0; j < CellCountVert; j++)
	{
		top = j * cellHeight;
		for (int i = 0; i < CellCountHor; i++)
		{
			left = i * cellWidth;
			cells[j*CellCountHor + i] = sf::IntRect(left, top, cellWidth, cellHeight);
		}
	}
}

int SpriteSheet::CellWidth(){ 
	return cellWidth * SCALE; //may have to change this when doing collision
}

int SpriteSheet::CellHeight(){
	return cellHeight * SCALE; //may have to change this when doing collision
}

Glyph SpriteSheet::GetGlyph( char c, sf::Vector2f pos )
{
	return Glyph( this, CharToIndex(c), pos);	// as an extra efficiency, we should add a glyph recycling factory to use here
}

void SpriteSheet::Draw( int i, sf::Vector2f pos )
{
	MainSprite.setTextureRect(cells[i]);		// These two operations are fast to perform
	MainSprite.setPosition(pos);

	WindowManager::MainWindow.draw( MainSprite );
}