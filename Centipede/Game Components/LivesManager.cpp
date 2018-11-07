#include "LivesManager.h"
#include "WaveManager.h"
#include "WaveWriter.h"

LivesManager* LivesManager::instance = nullptr;

void LivesManager::DisplayLives(const int & lives)
{
	GetInstance()->currentNumLives = lives;

	for (int i = 0; i < lives; i++)
		instance->liveSprites[i] = instance->spriteToDisplay;
}

int LivesManager::GetStartingLives()
{
	return GetInstance()->maxNumLives;
}

LivesManager::LivesManager()
	:maxNumLives(3),
	currentNumLives(0),
	startingPos_Lives(WaveWriter::GetStartingPos()) 
	//the lives are always next to the wave. no need to center cuz already centered by WaveManager()
{
	this->liveSprites = new sf::Sprite[maxNumLives];
	this->spriteToDisplay = sf::Sprite(ResourceManager::GetTexture("PlayerShip"));
}

LivesManager* LivesManager::GetInstance()
{
	if (instance == nullptr)
		instance = new LivesManager;

	return instance;
}

void LivesManager::Draw()
{
	for (int i = 0; i < this->currentNumLives - 1; i++)
		WindowManager::MainWindow.draw(this->liveSprites[i]);
}
