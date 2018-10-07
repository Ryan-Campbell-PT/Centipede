#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"
#include "MoveFSM.h"
#include "CentipedeBody.h"
#include "CentipedePart.h"

#include <list>

CentipedeHead::CentipedeHead(const sf::Vector2f & pos, const int &numBodies)
	:bodies(0), position(pos), currentDirectionState(0), animationCounter(0), BSCounter(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(pos);

	SetCollider(this->sprite, this->bitmap, true);
	RegisterCollision<CentipedeHead>(*this);

	SetupBodies(MoveSFM::downThenLeft.GetDirectionEnum(), numBodies);
	SetDirection(&MoveSFM::downThenLeft, false);
}

void CentipedeHead::Update()
{
	++animationCounter;

	this->currentDirectionState->MoveDirection(this, this->position);
	this->sprite.setPosition(this->position);

	if (this->animationCounter % 3 == 0)
		this->sprite.NextFrame();
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

sf::Vector2f CentipedeHead::GetPosition()
{
	return this->position;
}

void CentipedeHead::SetAnimationFrames(const int & startFrame, const int & endFrame)
{
	this->sprite.SetAnimation(startFrame, endFrame);
}

void CentipedeHead::CorrectXDirection()
{
	GameGrid::GetCenterYPosition(this->position);
}

CentiMovementDirectionEnum CentipedeHead::GetCurrentMovementDirection()
{
	return CentiMovementDirectionEnum::Error;
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	//if we are reaching the end of the window,or see a shroom, switch to next state
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Mushroom ||
		pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.x < 0.f)
		this->SetDirection(this->currentDirectionState->NextState(this), false);

	//if we are at the tops of the window, swap to up or down
	else if (pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y))
		this->SetDirection(&MoveSFM::upThenLeft, true);

	else if (pos.y < 0.f)
		this->SetDirection(&MoveSFM::downThenLeft, true);

}

void CentipedeHead::SetDirection(const CentipedeDirectionState * direction, bool centerToYPos)
{
	direction->Initialize(this);
	this->currentDirectionState = direction;

	static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->AddOffset(this->position, this->currentDirectionState->GetDirectionEnum());
}

void CentipedeHead::SetSpriteRotation(const float & rotation)
{
	this->sprite.setRotation(rotation);
}

CentipedeDirectionState * CentipedeHead::GetDirection(CentiMovementDirectionEnum direction)
{
	if (static_cast<int>(direction) >= 0 && static_cast<int>(direction) < DIRECTION_SIZE)
		return this->directionArray[static_cast<int>(direction)];
	else
		return nullptr;
}

void CentipedeHead::SetupBodies(CentiMovementDirectionEnum direction, const int &numBodies)
{
	if (numBodies > 0)
	{
		//this->bodies = new CentipedeBody(this, this->position, this->currentDirectionState->GetDirectionEnum());
		CentipedePart *prev (this), *curr(0);
		
		for (int i = 0; i < numBodies; ++i)
		{
			curr = new CentipedeBody(sf::Vector2f(this->position.x, this->position.y - (SPRITE_SIZE * (i + 1))), direction);

			curr->SetWhoYoureFollowing(prev);
			prev->SetWhosFollowingYou(curr);

			prev = prev->GetWhosFollowingYou();
		}
	}
}

