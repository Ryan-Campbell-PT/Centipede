// Glyph
// Andre Berthiaume, May 2013

#include "Glyph.h"
#include "SpriteSheet.h"
#include "TEAL\ResourceManager.h"
#include <assert.h>
#include "GameGrid.h"

Glyph::Glyph()
{
	sprsheet = nullptr;
	cellIndex = 0; 
	position = sf::Vector2f(0,0);
}

Glyph::~Glyph()
{
	//todo: this is constanyl being called because we are always making new glyphs in the text writing
	//will want to add a facotry
	//delete sprsheet;
}

Glyph::Glyph( SpriteSheet* sheet, int cellInd, sf::Vector2f pos )
{
	sprsheet = sheet;
	position = pos;
	cellIndex = cellInd;
	GameGrid::SetGridStatus(pos, GameGridEnum::Glyph);
}

void Glyph::Draw()
{
	assert(sprsheet != nullptr);

	sprsheet->Draw(cellIndex, position);
}
