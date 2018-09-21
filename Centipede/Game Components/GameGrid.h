#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "TEAL/CommonElements.h"

#define ROW 32 
#define COLUMN 30 
#define SPRITE_SIZE 16

///the concept of this will be in regards to a 30 x 31 grid that will store the mushrooms
///each grid will be the size of a mushroom (16 pixels)

///each mushroom is 16x16 pixels in height (subject to change depending on scale size)

enum class GameGridEnum;

class GameGrid
{
public:
	static GameGrid *GetInstance();

	///set the grid regardless of what is there (typically when a critter gets destroyed)
	void SetGridStatus(sf::Vector2f v, GameGridEnum e);

	///this method will attempt to set the grid using a location on the map
	bool AttemptToSetGrid(sf::Vector2f v, GameGridEnum e);

	GameGridEnum GetGridStatus(sf::Vector2f v);
	///the purpose of this function is to set the sprite in the middle of the grid, so minimal sprite collision occurs
	void GetCenterGridPosition(sf::Vector2f & pos);

private:
	GameGrid();
	~GameGrid();
	GameGrid &operator=(const GameGrid &c) = delete;
	GameGrid(const GameGrid &c) = delete;
	
	///when using the vector, this function may be unneeded due to being unable to move beyond the bounds
	bool BoundsCheck(const sf::Vector2f &v); 

	static GameGrid *instance;

	//row x column
	int grid[ROW][COLUMN];
};

//enums to tell what is located at this grid
enum class GameGridEnum
{
	Unoccupied = 0,
	Mushroom = 1
};


#endif //GAMEGRID_H