#include "MushroomManager.h"
#include "MushroomFactory.h"
#include "GameGrid.h"
#include "MushroomPool.h"
#include "Mushroom.h"

MushroomManager* MushroomManager::instance = 0;

void MushroomManager::InitializeMushroomField(int numShrooms)
{
	float x, y;
	sf::Vector2f pos;

	int windowX = static_cast<int>(WindowManager::MainWindow.getView().getSize().x);
	int windowY = static_cast<int>(WindowManager::MainWindow.getView().getSize().y);
	int gridUnoccupied = static_cast<int>(GameGridEnum::Unoccupied);

	//for now, mushroom spawning is randomized by the given grid set in GameGrid
	for (int i = 0; i < numShrooms; ++i)
	{
		do
		{
			x = static_cast<float>(rand() % windowX);
			y = static_cast<float>(rand() % windowY);
		} while ((int)GameGrid::GetGridStatus(sf::Vector2f(x, y)) >= gridUnoccupied);
		//the choice to use >= 0 is b/c when the array space is unused, its garbage data, typically -ABigNumber
		//so this tests whether its unusued, or Unoccupied

		pos.x = static_cast<float>(x);
		pos.y = static_cast<float>(y);

		GetInstance()->SpawnMushroom(pos);
	}

}

bool MushroomManager::AttemptSpawnShroom(sf::Vector2f & pos)
{
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Unoccupied)
	{
		GetInstance()->SpawnMushroom(pos);
		return true;
	}

	else
		return false;
}

void MushroomManager::RemoveMushroom(Mushroom * const shroom)
{
	GameGrid::SetGridStatus(shroom->GetPosition(), GameGridEnum::Unoccupied);

	MushroomFactory::RemoveMushroom(shroom);
}

MushroomManager * MushroomManager::GetInstance()
{
	if (instance == 0)
		instance = new MushroomManager;

	return instance;
}

void MushroomManager::SpawnMushroom(sf::Vector2f & pos)
{
	GameGrid::SetGridStatus(pos, GameGridEnum::Mushroom);
	GameGrid::GetCenterGridPosition(pos);

	MushroomFactory::SpawnMushroom(pos);
}
