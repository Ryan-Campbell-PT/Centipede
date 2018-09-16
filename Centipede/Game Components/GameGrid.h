#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "TEAL/CommonElements.h"

//the concept of this will be in regards to a 40 x 32 grid that will store the mushrooms
//each grid will be the size of a mushroom (16 pixels)

//each mushroom is 24 pixels in height (subject to change depending on scale size)

enum class GameGridEnum;

//TODO: figure out how to correcly do the math for locating where something goes in the grid
class GameGrid
{
public:
	static GameGrid *GetInstance();

	//set the grid regardless of what is there
	bool SetGridStatus(sf::Vector2f v, GameGridEnum e);
	bool SetGridStatus(int x, int y, GameGridEnum e);
	//this method will be different in that it will first check if anything is there, then set it if so
	bool CheckThenSetGrid(sf::Vector2f v, GameGridEnum e);

private:
	GameGrid();
	~GameGrid();
	GameGrid &operator=(const GameGrid &c) = delete;
	GameGrid(const GameGrid &c) = delete;
	
	static GameGrid *instance;

	//row x column (rough estimate)
	int grid[40][32];
};

//enums to tell what is located at this grid
static enum class GameGridEnum
{
	Unoccupied = 0,
	Mushroom = 1
};


#endif //GAMEGRID_H