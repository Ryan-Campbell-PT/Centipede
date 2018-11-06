#include "MushroomManager.h"
#include "MushroomFactory.h"
#include "GameGrid.h"
#include "MushroomPool.h"
#include "Mushroom.h"

MushroomManager* MushroomManager::instance = nullptr;

void MushroomManager::InitializeMushroomField(const int numShrooms)
{
	if(!MushroomPool::GetActiveMushroomList().empty())
		return; //no need to make a mushroom field if there already is one

	sf::Vector2f pos;

	const int windowX = static_cast<int>(WindowManager::MainWindow.getView().getSize().x);
	const int windowY = static_cast<int>(WindowManager::MainWindow.getView().getSize().y);
	const int gridUnoccupied = static_cast<int>(GameGridEnum::Unoccupied);

	for (int i = 0; i < numShrooms; ++i)
	{
		do
		{
			pos.x = static_cast<float>(rand() % windowX);
			pos.y = static_cast<float>(rand() % windowY);
		} while (static_cast<int>(GameGrid::GetGridStatus(pos)) >= gridUnoccupied);
		//the choice to use >= 0 is b/c when the array space is unused, its garbage data, typically -ABigNumber
		//so this tests whether its unusued, or Unoccupied

		GetInstance()->SpawnMushroom(pos);
	}
}

void MushroomManager::InitializeMushroomField(std::list<Mushroom*>* shroomField)
{
	GetInstance()->initializeMushroomField(shroomField);
}

bool MushroomManager::AttemptSpawnShroom(sf::Vector2f pos)
{
	if (GameGrid::GetGridStatus(pos) <= GameGridEnum::Unoccupied)
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

void MushroomManager::EndWave()
{
	MushroomFactory::RepairMushrooms();
}

std::list<Mushroom*>* MushroomManager::GetCurrentLayout()
{
	return MushroomFactory::GetCurrentLayout();
}

void MushroomManager::Terminate()
{
	delete instance;
	instance = nullptr;

	MushroomFactory::Terminate();
}

MushroomManager * MushroomManager::GetInstance()
{
	if (instance == nullptr)
		instance = new MushroomManager;

	return instance;
}

void MushroomManager::SpawnMushroom(sf::Vector2f & pos) const
{
	GameGrid::SetGridStatus(pos, GameGridEnum::Mushroom);
	GameGrid::GetCenterGridPosition(pos);

	auto shroom = MushroomFactory::GetMushroom();
	shroom->InitializeMushroom(pos);
}

void MushroomManager::initializeMushroomField(std::list<Mushroom*>* shroomField)
{
	for(auto shroom : *this->GetCurrentLayout())
		shroom->MarkForDestroy();

	for(auto shroom : *shroomField)
		shroom->InitializeMushroom();
}
