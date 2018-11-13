#include "Ship_Player.h"
#include "TEAL/CommonElements.h"
#include "PlayerInput.h"
#include "KeyboardCommand.h"
#include "BulletManager.h"

bool Ship_Player::MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed)
{
	if (sf::Keyboard::isKeyPressed(input->keyLeft->GetCommand())) pos.x -= speed;
	if (sf::Keyboard::isKeyPressed(input->keyUp->GetCommand())) pos.y -= speed;
	if (sf::Keyboard::isKeyPressed(input->keyDown->GetCommand())) pos.y += speed;
	if (sf::Keyboard::isKeyPressed(input->keyRight->GetCommand())) pos.x += speed;

	if (sf::Keyboard::isKeyPressed(input->keyFire->GetCommand()))
		return BulletManager::AttemptSpawnBullet();

	return false;
}

void Ship_Player::MushroomCollision(const PlayerInput * input, sf::Vector2f &pos, const float &speed)
{
	if (sf::Keyboard::isKeyPressed(input->keyLeft->GetCommand())) pos.x += speed;
	if (sf::Keyboard::isKeyPressed(input->keyUp->GetCommand())) pos.y += speed;
	if (sf::Keyboard::isKeyPressed(input->keyDown->GetCommand())) pos.y -= speed;
	if (sf::Keyboard::isKeyPressed(input->keyRight->GetCommand())) pos.x -= speed;
}
