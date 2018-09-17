#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "TEAL/CommonElements.h"

//the concept of this will be in regards to a 30 x 30 grid that will store the mushrooms
//each grid will be the size of a mushroom (16 pixels)

//each mushroom is 24 pixels in height (subject to change depending on scale size)

enum class GameGridEnum;

//TODO: figure out how to correcly do the math for locating where something goes in the grid
class GameGrid
{
public:
	static GameGrid *GetInstance();

	//set the grid regardless of what is there (typically when a critter gets destroyed)
	bool SetGridStatus(sf::Vector2f v, GameGridEnum e);

	//this method will attempt to set the grid using a location on the map
	bool AttemptToSetGrid(sf::Vector2f v, GameGridEnum e);

	GameGridEnum GetGridStatus(sf::Vector2f v);

	int grid[30][30];

private:
	GameGrid();
	~GameGrid();
	GameGrid &operator=(const GameGrid &c) = delete;
	GameGrid(const GameGrid &c) = delete;
	
	bool BoundsCheck(int x, int y);

	static GameGrid *instance;

	//row x column (rough estimate)
};

//enums to tell what is located at this grid
static enum class GameGridEnum
{
	Unoccupied = 0,
	Mushroom = 1
};


#endif //GAMEGRID_H