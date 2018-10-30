#include "Ship_Ai.h"
#include "TEAL/WindowManager.h"
#include "GameGrid.h"
#include "Ship.h"

Ship_Ai::Ship_Ai()
	:up(false),
	left(true), down(true),
	right(false),
	yTopBounds(WindowManager::MainWindow.getSize().y - (SPRITE_SIZE * SHIP_BOUNDS)),
	yBottomBounds(static_cast<float>(WindowManager::MainWindow.getSize().y)),
	xLeftBounds(0.f),
	xRightBounds(static_cast<float>(WindowManager::MainWindow.getSize().x))
{
}

void Ship_Ai::MoveShip(const PlayerInput* const input, sf::Vector2f &pos, const float &speed)
{//we dont care about the player in put for the AI version
	if (up)
	{
		pos.y -= speed;

		if (pos.y < yTopBounds)
			down = true;
	}

	else if (down)
	{
		pos.y += speed;

		if (pos.y > yBottomBounds)
			up = true;
	}

	if (right)
	{
		pos.x += speed;

		if (pos.x < xRightBounds)
			left = true;
	}

	else if (left)
	{
		pos.x -= speed;

		if (pos.y < xLeftBounds)
			right = true;
	}
}
