#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "TEAL/CommonElements.h"

//the concept of this will be in regards to a 40 x 32 grid that will store the mushrooms
//each grid will be the size of a mushroom (16 pixels)

//each mushroom is 24 pixels in height (subject to change depending on scale size)

enum class GameGridEnum;

class GameGrid
{
public:

	static GameGrid *GetInstance();

	bool SetGridOccupied(sf::Vector2f v, GameGridEnum e);
	bool SetGridOccupied(int x, int y, GameGridEnum e);

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