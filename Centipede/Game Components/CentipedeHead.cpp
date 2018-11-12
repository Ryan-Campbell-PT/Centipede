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
#include "Ship.h"

#include <list>
#include "ScoreManager.h"

CentipedeHead::CentipedeHead()
	:currentDirectionState(nullptr), prevDirection(nullptr), animationCounter(0),
	speed(2), yCounter(0), concent(false)
{
	this->bitmap = ResourceManager::GetTextureBitmap("CentiHead");
	this->sprite = AnimatedSprite(ResourceManager::GetTexture("CentiHead"), 8, 2);
	this->sprite.SetAnimation(SPRITE_BEGIN, SPRITE_END);

	this->sprite.setOrigin(sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f);
	this->sprite.setScale(2.f, 2.f);

	SetCollider(this->sprite, this->bitmap, true);

	this->SetWhosFollowingYou(nullptr);
	this->SetWhoYoureFollowing(nullptr);
	this->pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiHeadKilled);
}

CentipedeHead::~CentipedeHead()
{
	delete this->pDeath;
	//todo: currently breaking at the Destroy(), look into
#if false
	auto tmp = this->GetWhosFollowingYou();
	CentipedePart* prev = nullptr;

	while (tmp)
	{
		prev = tmp;
		tmp = tmp->GetWhosFollowingYou();
		static_cast<CentipedeBody*>(prev)->Destroy();
		//delete prev;
		//tmp = tmp->GetWhosFollowingYou();
	}
#endif
}

void CentipedeHead::InitializeHead(sf::Vector2f& pos, const int & numBodies, CentipedeDirectionState const & direction)
{
	GameGrid::GetCenterGridPosition(pos);
	this->InitializeHead(pos, direction);
	SetupBodies(direction.GetOffsetArray(), numBodies);
}

void CentipedeHead::InitializeHead(const sf::Vector2f & pos, CentipedeDirectionState const & direction, const bool &setDirection)
{
	this->position = pos;

	this->sprite.setPosition(pos);

	RegisterCollision<CentipedeHead>(*this);
	
	this->currentDirectionState = &direction;
	yCounter = 0;
	concent = false;
}

void CentipedeHead::Update()
{
	++animationCounter;

	this->position.x += (this->currentDirectionState->GetOffsetArray()).coloffset * speed;
	this->position.y += (this->currentDirectionState->GetOffsetArray()).rowoffset * speed;

	if (this->currentDirectionState->GetOffsetArray().rowoffset != 0) //we are moving in the Y
	{
		yCounter += (this->currentDirectionState->GetOffsetArray()).rowoffset * speed;

		if (yCounter % SPRITE_SIZE == 0)
		{
			if (this->GetWhosFollowingYou())
				static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->currentDirectionState->GetOffsetArray());

			this->SetDirection(this->currentDirectionState->NextState(this));
		}
	}

	else if (this->animationCounter % (SPRITE_SIZE / 2) == 0)
	{
		if (this->GetWhosFollowingYou())
			static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->currentDirectionState->GetOffsetArray());

		this->CheckGridAhead(sf::Vector2f(
			this->position.x + this->currentDirectionState->GetOffsetArray().coloffset * SPRITE_SIZE,
			this->position.y + this->currentDirectionState->GetOffsetArray().rowoffset * SPRITE_SIZE));
	}

	this->sprite.setPosition(this->position);
	
	if (this->animationCounter % 3 == 0)
		this->sprite.NextFrame();
}

void CentipedeHead::Draw()
{
	WindowManager::MainWindow.draw(this->sprite);
}

void CentipedeHead::Destroy()
{	
	DeregisterCollision<CentipedeHead>(*this);

	CentiBodyManager::SetBodyToHead(static_cast<CentipedeBody*>(this->GetWhosFollowingYou()));
}

void CentipedeHead::Alarm0()
{
	Ship::ReinitializeShip();
	PlayerManager::ReinitializeShip();
}

void CentipedeHead::SetAnimationFrames(const int & startFrame, const int & endFrame)
{
	this->sprite.SetAnimation(startFrame, endFrame);
}

CentiMovementDirectionEnum CentipedeHead::GetDirectionEnum()
{
	return CentiMovementDirectionEnum::Error;
}

void CentipedeHead::Collision(Bullet *)
{
	this->concent = true; //he concented to being shot
	this->MarkForDestroy(); //remove the head from screen, and recycle

	MushroomManager::AttemptSpawnShroom(this->position); //drop the mushroom where it died (if no mushroom is there)
	ScoreManager::SendScoreCmd(this->pDeath);
}

void CentipedeHead::CheckGridAhead(sf::Vector2f pos)
{
	//if we are reaching the end of the window,or see a shroom, switch to next state
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Mushroom ||
		GameGrid::GetGridStatus(pos) == GameGridEnum::Glyph)
		this->SetDirection(this->currentDirectionState->NextState(this));

	else if(GameGrid::GetGridStatus(pos) == GameGridEnum::PoisonMushroom)
	{}//todo: bezerk

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
	if (direction->GetOffsetArray().rowoffset != 0)
		if (this->GetWhosFollowingYou())
		{//todo: work on how this information is passed down. Incorrect atm
			static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->prevDirection->GetOffsetArray());
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

void CentipedeHead::SetupBodies(OffsetArray direction, int numBodies)
{
	if (numBodies > 0)
	{
		CentipedePart *prev(this), *curr(nullptr);

		for (int i = 0; i < numBodies; ++i)
		{//create number of bodies needed, and connect all the links at the creation of them
			//todo: you could possibly dynamically create the bodies depending on the offset
			curr = CentiBodyManager::GetInitializedCentiBody(sf::Vector2f(this->position.x, this->position.y - (SPRITE_SIZE * (i + 1))), direction);

			curr->SetWhoYoureFollowing(prev);
			prev->SetWhosFollowingYou(curr);

			prev = prev->GetWhosFollowingYou();
		}
	}
}

/*void CentipedeHead::RemoveHead()
{
	//remove from screen
	DeregisterCollision<CentipedeHead>(*this);

	CentiBodyManager::SetBodyToHead(static_cast<CentipedeBody*>(this->GetWhosFollowingYou()));

	CentiHeadManager::RemoveCentiHead(this); //recycle
}*/
