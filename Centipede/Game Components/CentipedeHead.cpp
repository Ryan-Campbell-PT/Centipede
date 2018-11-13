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
	:currentDirectionState(nullptr), animationCounter(0),
	speed(1), yCounter(0), concent(false)
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

void CentipedeHead::InitializeHead(sf::Vector2f& pos, const int & numBodies, const int &speed, CentipedeDirectionState const & direction)
{
	GameGrid::GetCenterGridPosition(pos);
	this->InitializeHead(pos, speed, direction);
	SetupBodies(direction.GetOffsetArray(), numBodies);
}

void CentipedeHead::InitializeHead(const sf::Vector2f & pos, const int &speed, CentipedeDirectionState const & direction)
{
	this->position = pos;
	this->sprite.setPosition(pos);
	this->speed = speed;
	this->currentDirectionState = &direction;

	RegisterCollision<CentipedeHead>(*this);

	yCounter = 0;
	concent = false;
}

void CentipedeHead::Update()
{
	this->currentDirectionState->CheckAhead(this, this->animationCounter, this->yCounter);
	
	this->position.x += this->currentDirectionState->GetOffsetArray().coloffset * this->speed;
	this->position.y += this->currentDirectionState->GetOffsetArray().rowoffset * this->speed;

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

	CentiBodyManager::SetBodyToHead(static_cast<CentipedeBody*>(this->GetWhosFollowingYou()), this->currentDirectionState);
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

void CentipedeHead::Collision(Bullet *)
{
	this->concent = true; //he concented to being shot
	this->MarkForDestroy(); //remove the head from screen, and recycle

	MushroomManager::AttemptSpawnShroom(this->position); //drop the mushroom where it died (if no mushroom is there)
	ScoreManager::SendScoreCmd(this->pDeath);
}

void CentipedeHead::CheckGridAhead(const sf::Vector2f &pos)
{
	//if we are reaching the end of the window,or see a shroom, switch to next state
	if (GameGrid::GetGridStatus(pos) == GameGridEnum::Mushroom ||
		GameGrid::GetGridStatus(pos) == GameGridEnum::Glyph)
		this->SetDirection(this->currentDirectionState->NextState(this));

	else if (GameGrid::GetGridStatus(pos) == GameGridEnum::PoisonMushroom)
		this->SetDirection(this->currentDirectionState->ExtraState(this));

	else if (pos.x > static_cast<float>(WindowManager::MainWindow.getView().getSize().x) ||
		pos.x < 0.f)
		this->SetDirection(this->currentDirectionState->NextState(this));

	//if we are at the tops of the window, swap to up or down
	else if (pos.y > static_cast<float>(WindowManager::MainWindow.getView().getSize().y))
		this->SetDirection(this->currentDirectionState->ExtraState(this));

	else if (pos.y < 0.f)
		this->SetDirection(this->currentDirectionState->ExtraState(this));

	else
		//if all else fails, and you never have to change directions due to things ahead,
		//still inform the body behind you whats going on
		if (this->GetWhosFollowingYou())
			static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->currentDirectionState->GetOffsetArray());

}

void CentipedeHead::SetDirection(const CentipedeDirectionState * direction, bool change)
{
	if (this->GetWhosFollowingYou())
		static_cast<CentipedeBody*>(this->GetWhosFollowingYou())->GetDataFromFront(this->currentDirectionState->GetOffsetArray());

	if(change) //strictly for poison
		this->currentDirectionState = direction;
}

void CentipedeHead::SetSpriteRotation(const float & rotation)
{
	this->sprite.setRotation(rotation);
}

const CentipedeDirectionState * CentipedeHead::GetDirection() const
{
	return this->currentDirectionState;
}

void CentipedeHead::SetupBodies(OffsetArray direction, int numBodies)
{
	if (numBodies > 0)
	{
		CentipedePart *prev(this), *curr(nullptr);
		sf::Vector2f pos(this->position);

		for (int i = 0; i < numBodies; ++i)
		{//create number of bodies needed, and connect all the links at the creation of them
			pos.y = this->position.y - SPRITE_SIZE * (i + 1);
			curr = CentiBodyManager::GetInitializedCentiBody(pos, this->speed, direction);

			curr->SetWhoYoureFollowing(prev);
			prev->SetWhosFollowingYou(curr);

			prev = prev->GetWhosFollowingYou();
		}
	}
}