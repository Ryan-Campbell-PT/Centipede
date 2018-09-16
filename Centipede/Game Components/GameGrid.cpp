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

bool GameGrid::SetGridStatus(sf::Vector2f v, GameGridEnum e)
{
	
	//todo: the math here will likely be incorrect in edge cases, look over it
	return this->SetGridStatus(v.x / 24, v.y / 24, e); //24 because of scale factor
}

bool GameGrid::SetGridStatus(int x, int y, GameGridEnum e)
{
	//make sure not to get out of bounds
	if (x >= 0 && x < 40 && y >= 0 && y < 32)
	{
		this->grid[x][y] = (int) e;
		return true;
	}

	return false; //return false if the location is out of bounds
}

bool GameGrid::CheckThenSetGrid(sf::Vector2f v, GameGridEnum e)
{
	//if the grid location is untouched
	if (GetInstance()->grid[(int)v.x / 24][(int)v.y / 24] == (int)GameGridEnum::Unoccupied)
		return SetGridStatus(v, e);

	else
		return false;
}
