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
	if (BoundsCheck(v)) //make sure we arent out of bounds
		this->grid[static_cast<int>(v.x / SPRITE_SIZE)][static_cast<int>(v.y / SPRITE_SIZE)] = static_cast<int>(e);
}

GameGridEnum GameGrid::GetGridStatus(sf::Vector2f v)
{
	if(this->BoundsCheck(v))
		return static_cast<GameGridEnum>(this->grid[static_cast<int>(v.x / SPRITE_SIZE)][static_cast<int>(v.y / SPRITE_SIZE)]);
}

void GameGrid::GetCenterGridPosition(sf::Vector2f & pos)
{	
	//the math behind this is so: you divide the vectors position by the sprite size and the int conversion floor()'s it.
	//once you have the grid location (the floor()'ing), you multiply it again by the sprite size to get it back to
	//its grids location in game. Then add half a sprite to x and y to get it centered in the grid, and have them sprite distance apart.

	//without this function, sprites very often overlap eachother
	pos.x = static_cast<int>(pos.x / SPRITE_SIZE) * SPRITE_SIZE + (SPRITE_SIZE / 2);
	pos.y = static_cast<int>(pos.y / SPRITE_SIZE) * SPRITE_SIZE + (SPRITE_SIZE / 2);

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
	int tmpX = (v.x / SPRITE_SIZE);
	int tmpY = (v.y / SPRITE_SIZE);

	return (
		tmpX >= 0 && 
		tmpX < ROW && 
		tmpY < COLUMN && 
		tmpY >= 0);
}