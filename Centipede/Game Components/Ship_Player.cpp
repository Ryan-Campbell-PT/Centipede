#include "Ship_Player.h"
#include "TEAL/CommonElements.h"
#include "PlayerInput.h"
#include "KeyboardCommand.h"

void Ship_Player::MoveShip(const PlayerInput * input, sf::Vector2f &pos, const float &speed)
{
	if (sf::Keyboard::isKeyPressed(input->keyLeft->GetCommand())) pos.x -= speed;
	if (sf::Keyboard::isKeyPressed(input->keyUp->GetCommand())) pos.y -= speed;
	if (sf::Keyboard::isKeyPressed(input->keyDown->GetCommand())) pos.y += speed;
	if (sf::Keyboard::isKeyPressed(input->keyRight->GetCommand())) pos.x += speed;

}

void Ship_Player::MushroomCollision(const PlayerInput * input, sf::Vector2f &pos, const float &speed)
{
	if (sf::Keyboard::isKeyPressed(input->keyLeft->GetCommand())) pos.x += speed;
	if (sf::Keyboard::isKeyPressed(input->keyUp->GetCommand())) pos.y += speed;
	if (sf::Keyboard::isKeyPressed(input->keyDown->GetCommand())) pos.y -= speed;
	if (sf::Keyboard::isKeyPressed(input->keyRight->GetCommand())) pos.x -= speed;
}
