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

bool GameGrid::SetGridOccupied(int gridX, int gridY, GameGridEnum e)
{
	//set the grid location to whatever is being asked
	if (this->grid[gridX][gridY] == (int) GameGridEnum::Unoccupied)
	{
		this->grid[gridX][gridY] = (int) e;
		return true;
	}

	return false; //return false if the location already has something there
}
