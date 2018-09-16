#include "GameGrid.h"

GameGrid *GameGrid::instance = 0;

GameGrid::GameGrid()
{
}

GameGrid::~GameGrid()
{
	delete instance;
}

GameGrid * GameGrid::GetInstance()
{
	if (instance == 0)
		instance = new GameGrid;

	return instance;
}

bool GameGrid::SetGridOccupied(sf::Vector2f v, GameGridEnum e)
{
	//todo: the math here will likely be incorrect in edge cases, look over it
	return this->SetGridOccupied(v.x / 24, v.y / 24, e); //24 because of scale factor
}

bool GameGrid::SetGridOccupied(int x, int y, GameGridEnum e)
{
	//set the grid location to whatever is being asked
	if (this->grid[x][y] == (int) GameGridEnum::Unoccupied)
	{
		this->grid[x][y] = (int) e;
		return true;
	}

	return false; //return false if the location already has something there
}
