#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "TEAL/CommonElements.h"

#define ROW 32 
#define COLUMN 30 
#define SPRITE_SIZE 16

///the concept of this will be in regards to a 30 x 32 grid that will store the mushrooms
///each grid will be the size of a mushroom (16 pixels)

///each mushroom is 16x16 pixels in height (subject to change depending on scale size)

enum class GameGridEnum;

class GameGrid
{
public:
	///set the grid regardless of what is there (typically when a critter gets destroyed)
	static void SetGridStatus(sf::Vector2f v, GameGridEnum e);

	///this method will attempt to set the grid using a location on the map
	static bool AttemptToSetGrid(sf::Vector2f v, GameGridEnum e);

	static GameGridEnum GetGridStatus(sf::Vector2f v);
	///the purpose of this function is to set the sprite in the middle of the grid, so minimal sprite collision occurs
	static void GetCenterGridPosition(sf::Vector2f & pos);

	///this functions purpose is centered around critters, who dont care about their X pos, but need to be centered in the Y without altering X
	static void GetCenterYPosition(sf::Vector2f &pos);
	static void GetCenterXPosition(sf::Vector2f &pos);

	GameGrid &operator=(const GameGrid &c) = delete;
	GameGrid(const GameGrid &c) = delete;

private:
	static GameGrid *GetInstance();

	GameGrid() = default;
	virtual ~GameGrid();

	///when using the vector, this function may be unneeded due to being unable to move beyond the bounds
	bool BoundsCheck(const sf::Vector2f &v);

	static GameGrid *instance;

	//row x column
	int grid[ROW][COLUMN];
};

//enums to tell what is located at this grid
enum class GameGridEnum
{
	Error = -1,
	Unoccupied = 0,
	Mushroom = 1,
	PoisonMushroom = 2,
	Glyph = 3
};

#endif //GAMEGRID_H