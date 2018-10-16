#include "CentipedeHead.h"
#include "CentiMovement.h"
#include "GameGrid.h"
#include "MoveFSM.h"
#include "CentipedeBody.h"
#include "CentipedePart.h"
#include "CentiBodyManager.h"
#include "Bullet.h"
#include "CentiHeadManager.h"
#include "MushroomManager.h"

#include <list>

CentipedeHead::CentipedeHead()
	:currentDirectionState(nullptr), animationCounter(0), active(false), prevDirection(0)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(0.f, 0.f);

	SetCollider(this->sprite, this->bitmap, true);

	this->SetWhosFollowingYou(nullptr);
	this->SetWhoYoureFollowing(nullptr);
}

void CentipedeHead::InitializeHead(sf::Vector2f& pos, const int & numBodies, CentipedeDirectionState const & direction)
{
	GameGrid::GetCenterGridPosition(pos);
	this->InitializeHead(pos, direction);
	SetupBodies(direction.GetDirectionEnum(), numBodies);
}

void CentipedeHead::InitializeHead(const sf::Vector2f & pos, CentipedeDirectionState const & direction, const bool &setDirection)
{
	this->active = true;
	this->position = pos;

	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(pos);

	RegisterCollision<CentipedeHead>(*this);

	this->currentDirectionState = &direction;
	this->CheckGridAhead(pos);
	yCounter = 0;
	//if(setDirection)
	//	SetDirection(&direction, false);
}

void CentipedeHead::Update()
{
	if (!active)
		return;

	++animationCounter;

	//this->currentDirectionState->MoveDirection(this, this->position);
	this->position.x += (this->currentDirectionState->GetOffsetArray()).coloffset * CENTI_SPEED;
	this->position.y += (this->currentDirectionState->GetOffsetArray()).rowoffset * CENTI_SPEED;

	if (this->currentDirectionState->GetOffsetArray().rowoffset != 0) //we are moving in the Y
	{
		yCounter += (this->currentDirectionState->GetOffsetArray()).rowoffset * CENTI_SPEED;
	
		if (yCounter % SPRITE_SIZE == 0)
			this->SetDirection(this->currentDirectionState->NextState(this));
	}

	this->sprite.setPosition(this->position);
	
	if (this->animationCounter % 3 == 0)
		this->sprite.NextFrame();

	if (this->animationCounter % (SPRITE_SIZE / 2) == 0)
	{
		auto ppos = sf::Vector2f(
			this->position.x + (this->currentDirectionState->GetOffsetArray()).coloffset * SPRITE_SIZE,
			this->position.y + (this->currentDirectionState->GetOffsetArray()).rowoffset * SPRITE_SIZE);

		//ConsoleMsg::WriteLine("Users X: " + Tools::ToString(position.x) + " Users Y: " + Tools::ToString(position.y));
		//ConsoleMsg::WriteLine("Created X: " + Tools::ToString(ppos.x) + " Created Y: " + Tools::ToString(ppos.y) + "\n");
		if(this->GetWhosFollowingYou())
		{
			static_cast<CentipedeBody*>( this->GetWhosFollowingYou())->GetDataFromFront(this->currentDirectionState->GetOffsetArray());
		}
		this->CheckGridAhead(ppos);
	}
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void CentipedeHead::Collide(Bullet * const bullet)
{
	bullet->RemoveBullet(); //remove the bullet

	this->RemoveHead(); //remove the head from screen, and recycle

	MushroomManager::AttemptSpawnShroom(this->position); //drop the mushroom where it died (if no mushroom is there)
}

sf::Vector2f CentipedeHead::GetPosition()
{
	return this->position;
}

void CentipedeHead::SetAnimationFrames(const int & startFrame, const int & endFrame)
{
	this->sprite.SetAnimation(startFrame, endFrame);
}

CentiMovementDirectionEnum CentipedeHead::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Error;
}

void CentipedeHead::Collision(Bullet * bullet)
{
	bullet->RemoveBullet();
	this->RemoveHead();
	MushroomManager::AttemptSpawnShroom(this->GetPosition());
}

void CentipedeHead::CenterOnX()
{
	GameGrid::GetCenterXPosition(this->position);
}

void CentipedeHead::CenterOnY()
{
	GameGrid::GetCenterYPosition(this->position);
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	//if we are reaching the end of the window,or see a shroom, switch to next state
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Mushroom)// ||
		this->SetDirection(this->currentDirectionState->NextState(this));

	else if (pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.x < 0.f)
		this->SetDirection(this->currentDirectionState->NextState(this));

	//if we are at the tops of the window, swap to up or down
	else if (pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y))
		this->SetDirection(&MoveSFM::upThenLeft);

	else if (pos.y < 0.f)
		this->SetDirection(&MoveSFM::downThenLeft);

//	if(GetWhosFollowingYou() && this->prevDirection)
//		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->TellBoiMyName(this->prevDirection->GetDirectionEnum());

}

void CentipedeHead::SetDirection(const CentipedeDirectionState * direction)
{
	direction->Initialize(this);
	this->prevDirection = this->currentDirectionState;
	this->currentDirectionState = direction;

/*	if (this->GetWhosFollowingYou())
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->AddOffset(
			this->position, this->currentDirectionState->GetDirectionEnum());*/
	if(this->GetWhosFollowingYou())
	{//todo: work on how this information is passed down. Incorrect atm
		//static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->TellBoiMyName(this->prevDirection->GetDirectionEnum());
	}
}

void CentipedeHead::SetSpriteRotation(const float & rotation)
{
	this->sprite.setRotation(rotation);
}

CentipedeDirectionState * CentipedeHead::GetDirection(CentiMovementDirectionEnum direction)
{
	if (static_cast<int>(direction) >= 0 && static_cast<int>(direction) < DIRECTION_SIZE)
		return this->directionArray[static_cast<int>(direction)];

	return nullptr;
}

const CentipedeDirectionState * CentipedeHead::GetDirection()
{
	return this->currentDirectionState;
}

void CentipedeHead::SetupBodies(CentiMovementDirectionEnum direction, int numBodies)
{
	numBodies = 7;
	if (numBodies > 0)
	{
		CentipedePart *prev(this), *curr(nullptr);

		for (int i = 0; i < numBodies; ++i)
		{//create number of bodies needed, and connect all the links at the creation of them
			curr = CentiBodyManager::GetInitializedCentiBody(sf::Vector2f(this->position.x, this->position.y - (SPRITE_SIZE * (i + 1))), direction);

			curr->SetWhoYoureFollowing(prev);
			prev->SetWhosFollowingYou(curr);

			prev = prev->GetWhosFollowingYou();
		}
	}
}

void CentipedeHead::RemoveHead()
{
	//remove from screen
	this->sprite.setScale(0.f, 0.f);
	DeregisterCollision<CentipedeHead>(*this);
	this->active = false;

	CentiHeadManager::RemoveCentiHead(this); //recycle

	CentiBodyManager::SetBodyToHead(static_cast<CentipedeBody*>(this->GetWhosFollowingYou()));
}
