#ifndef GAMEGRID_H
#define GAMEGRID_H

class GameGrid
{
public:
	GameGrid();
	~GameGrid();
	GameGrid &operator=(const GameGrid &c) = delete;
	GameGrid(const GameGrid &c) = delete;

	static GameGrid *getInstance();

private:
	static GameGrid *instance;

};

GameGrid *GameGrid::instance = 0;

#endif //GAMEGRID_H