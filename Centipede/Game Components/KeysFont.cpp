// KeysFont
// Andre Berthiaume, May 2013

#include "KeysFont.h"
#include "TEAL\ResourceManager.h"

KeysFont::KeysFont()
	: SpriteSheet( ResourceManager::GetTexture("Keys"), 11, 4 )
{}

// Computing the magic value of the cellIndex for each char
int KeysFont::CharToIndex( char& c )
{
	int cellIndex = 0;

	// This converts any lowercase key into an uppercase key
	if ( c >= 'a' && c <= 'z')
		c -= 32;

	// Now selects which symbol to use
	if ( c >= 'A' && c <= 'Z')
		cellIndex = (int) c - (int) 'A';	
	else if ( c >= '0' && c <= '9')
		cellIndex = (int) c - (int) '0' + 26;
	else if (c == ' ')
		cellIndex = 37;
	else
		cellIndex = 37;  // This branch is the default symbol when all else fails. Set to space for now
	return cellIndex;
}