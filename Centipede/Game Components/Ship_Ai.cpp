#include "Ship_Ai.h"
#include "TEAL/WindowManager.h"
#include "GameGrid.h"
#include "Ship.h"

Ship_Ai::Ship_Ai()
	:up(false),
	left(true), down(true),
	right(false),
	yTopBounds(WindowManager::MainWindow.getSize().y - (SPRITE_SIZE * SHIP_BOUNDS)),
	yBottomBounds(static_cast<float>(WindowManager::MainWindow.getSize().y - SPRITE_SIZE)),
	xLeftBounds(SPRITE_SIZE / 2),
	xRightBounds(static_cast<float>(WindowManager::MainWindow.getSize().x - (SPRITE_SIZE / 2)	))
{
}

void Ship_Ai::MoveShip(const PlayerInput* const input, sf::Vector2f &pos, const float &speed)
{//we dont care about the player in put for the AI version
	if (up)
	{
		pos.y -= speed;

		if (pos.y < yTopBounds)
		{
			down = true;
			up = false;
			//pos.y += speed;
		}
	}

	else if (down)
	{
		pos.y += speed;

		if (pos.y > yBottomBounds)
		{
			up = true;
			down = false;
			//pos.y -= speed;
		}
	}

	if (right)
	{
		pos.x += speed;

		if (pos.x > xRightBounds)
		{
			left = true;
			right = false;
			//pos.x -= speed;
		}
	}

	else if (left)
	{
		pos.x -= speed;

		if (pos.x < xLeftBounds)
		{
			right = true;
			left = false;
			//pos.x += speed;
		}
	}
}
