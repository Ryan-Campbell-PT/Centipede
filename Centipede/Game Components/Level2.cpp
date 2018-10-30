#include "Level2.h"
#include "WaveManager.h"

void Level2::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 0, 255)); //set background color black

	WaveManager::SetupLevel(2);
	//no need to initialize mushroom field bc its already made in 1
}
