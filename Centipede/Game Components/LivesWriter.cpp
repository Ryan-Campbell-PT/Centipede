#include "LivesWriter.h"
#include "WaveWriter.h"
#include "GameGrid.h"

LivesWriter * LivesWriter::instance = nullptr;

LivesWriter::LivesWriter()
	:startingPos_Lives(WaveWriter::GetStartingPos()), livesToDisplay(0)
{
	startingPos_Lives.x += SPRITE_SIZE;
	spriteToDisplay = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));
	this->liveSprites = new sf::Sprite[3];
}

LivesWriter * LivesWriter::GetInstance()
{
	if(instance == nullptr)
	{
		instance = new LivesWriter;
		instance->SetExternalManagement(Terminate);
	}
	
	return instance;
}

void LivesWriter::Draw()
{
	for(int i = 0; i < livesToDisplay; i++)
		WindowManager::MainWindow.draw(this->liveSprites[i]);
}

void LivesWriter::writeLives(const int & numLives)
{
	this->livesToDisplay = numLives;
	auto tmp = this->startingPos_Lives;
	for(int i = 0 ; i < numLives; i++)
	{
		this->liveSprites[i] = this->spriteToDisplay;
		this->liveSprites[i].setPosition(tmp);
		tmp.x += SPRITE_SIZE;
	}
}

void LivesWriter::WriteLives(const int & numLives)
{
	GetInstance()->writeLives(numLives);
}

void LivesWriter::Terminate(GameObject*)
{
	delete instance;
	instance = nullptr;
}

