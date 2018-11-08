#ifndef WAVEWRITER_H
#define WAVEWRITER_H

#include "TEAL/GameObject.h"

class Glyph;

class WaveWriter : public GameObject
{
public:
	static void WriteWave(const int &num);

	static void Terminate(GameObject*);

	static sf::Vector2f GetStartingPos();

private:
	WaveWriter();
	static WaveWriter* GetInstance();
	static WaveWriter* instance;

	virtual void Draw() override;

	sf::Vector2f waveTextPosition;
	unsigned int numGlyphsForWave;
	Glyph *waveGlyphs;

};

#endif // WAVEWRITER_H
