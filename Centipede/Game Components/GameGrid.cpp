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

void GameGrid::SetGridStatus(sf::Vector2f v, GameGridEnum e)
{
	//todo: the math here will likely be incorrect in edge cases, look over it
	if (BoundsCheck(v)) //make sure we arent out of bounds
		this->grid[static_cast<int>(v.x / 24)][static_cast<int>(v.y / 24)] = static_cast<int>(e); //24 b/c of scale factor
}

GameGridEnum GameGrid::GetGridStatus(sf::Vector2f v)
{
	if(this->BoundsCheck(v))
		return static_cast<GameGridEnum>(this->grid[static_cast<int>(v.x / 24)][static_cast<int>(v.y / 24)]);
}

bool GameGrid::AttemptToSetGrid(sf::Vector2f v, GameGridEnum e)
{
		if (this->GetGridStatus(v) == GameGridEnum::Unoccupied) //can we place here
		{
			this->SetGridStatus(v, e); //if it isnt occupied, confirm can be placed
			return true;
		}
		else
			return false; //the grid wasnt unoccupied
}

bool GameGrid::BoundsCheck(const sf::Vector2f & v)
{
	int tmpX = (v.x / 24);
	int tmpY = (v.y / 24);

	return (
		tmpX >= 0 && 
		tmpX < ROW && 
		tmpY < COLUMN && 
		tmpY >= 0);
}