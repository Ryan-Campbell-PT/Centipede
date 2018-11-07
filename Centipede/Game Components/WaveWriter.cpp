#include "WaveWriter.h"
#include "Glyph.h"
#include "GameGrid.h"
#include "TextEditor.h"

WaveWriter * WaveWriter::instance = nullptr;

void WaveWriter::WriteWave(const int & num)
{
	auto wave = Tools::ToString(num);
	auto tmpStartingPos = GetInstance()->waveTextPosition;

	if (wave.size() < instance->numGlyphsForWave)
	{ //it is a wave that is < 10, so hard code the 0 on
		//todo: dont hard code this
		instance->waveGlyphs[1] = TextEditor::WriteText(wave.at(0), tmpStartingPos);
		instance->waveGlyphs[0] = TextEditor::WriteText('0', sf::Vector2f(tmpStartingPos.x -= SPRITE_SIZE, tmpStartingPos.y));
	}

	else
	{
		for (unsigned int i = wave.size() - 1; i >= 0; i++)
		{
			instance->waveGlyphs[i] = TextEditor::WriteText(wave.at(i), tmpStartingPos);
			tmpStartingPos.x -= SPRITE_SIZE;
		}
	}
}

void WaveWriter::Terminate(GameObject *)
{
	delete[] instance->waveGlyphs;
	instance->waveGlyphs = nullptr;

	delete instance;
	instance = nullptr;
}

sf::Vector2f WaveWriter::GetStartingPos()
{
	return GetInstance()->waveTextPosition;
}

WaveWriter::WaveWriter()
	:numGlyphsForWave(2)
{
	waveTextPosition = sf::Vector2f(SPRITE_SIZE * 3, 0.f);
	GameGrid::GetCenterGridPosition(waveTextPosition);
	this->waveGlyphs = new Glyph[this->numGlyphsForWave];
}

WaveWriter * WaveWriter::GetInstance()
{
	if(instance == nullptr)
	{
		instance = new WaveWriter;
		instance->SetExternalManagement(Terminate);
	}

	return instance;
}

void WaveWriter::Draw()
{	
	if (instance && instance->waveGlyphs)
	{
		for (unsigned int i = 0; i < instance->numGlyphsForWave; i++)
			instance->waveGlyphs[i].Draw();
	}

}
