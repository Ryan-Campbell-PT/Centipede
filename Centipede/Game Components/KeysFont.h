// KeysFont
// Andre Berthiaume, May 2013

#ifndef _KeysFont
#define _KeysFont

#include "SpriteSheet.h"

class KeysFont : public SpriteSheet
{
public:
	KeysFont();

	KeysFont(const KeysFont&) = delete;
	KeysFont& operator=(const KeysFont&) = delete;
	virtual ~KeysFont() = default;

private:
	virtual int CharToIndex( char& c ); 
};


#endif _KeysFont