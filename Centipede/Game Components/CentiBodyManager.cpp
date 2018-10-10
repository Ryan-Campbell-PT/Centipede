#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "CentipedeBody.h"
#include "CentiHeadManager.h"
#include "CentipedeHead.h"
#include "MushroomManager.h"
#include "CentipedeDirectionState.h"

CentiBodyManager * CentiBodyManager::instance = 0;

CentipedeBody * CentiBodyManager::GetCentiBody()
{
	return CentiBodyFactory::GetCentiBody(GetInstance());
}

CentipedeBody * CentiBodyManager::GetInitializedCentiBody(sf::Vector2f const & pos, CentiMovementDirectionEnum const & direction)
{
	auto body = CentiBodyFactory::GetCentiBody(GetInstance());
	body->InitializeBody(pos, direction);

	return body;
}

void CentiBodyManager::MakeBodyHead(CentipedeBody * body)
{
	if (body == nullptr)
		return;

	auto direction = GetInstance()->GetBodysHeadDirection(body);
	GetInstance()->MakeBodyHead(body, direction);
}

void CentiBodyManager::MakeBodyHead(CentipedeBody * body, const CentipedeDirectionState * direction)
{
	if (body == nullptr)
		return; //destroyed the current tail, no need to do anything
	
	CentiBodyFactory::RemoveCentiBody(GetInstance(), body); //recycle that body part
	auto head = CentiHeadManager::GetCentiHead(); //get a head to be used
	body->RemoveBodyFromScreen(false, false);

	//setup the links
	if(body->GetWhoYoureFollowing())
		body->GetWhoYoureFollowing()->SetWhosFollowingYou(nullptr); //set the person infront to the tail

	if(body->GetWhosFollowingYou())
		body->GetWhosFollowingYou()->SetWhoYoureFollowing(head); //set the person behind (if anyone) to follow the newly created head

	head->SetWhosFollowingYou(body->GetWhosFollowingYou()); //set the heads follower
	head->SetWhoYoureFollowing(nullptr);

	body->SetWhosFollowingYou(nullptr); //remove any links
	body->SetWhoYoureFollowing(nullptr);

	head->InitializeHead(body->GetPosition(), *direction, false);
	head->SetDirection(direction->NextState(head), false);
}

void CentiBodyManager::RemoveCentiBody(CentipedeBody * body, const bool &makeBehindHead, const bool &spawnShroom)
{
	if(spawnShroom)
		MushroomManager::AttemptSpawnShroom(body->GetPosition()); //spawn the shroom where the body died

	if(makeBehindHead)
		MakeBodyHead(static_cast<CentipedeBody*>(body->GetWhosFollowingYou()));

	CentiBodyFactory::RemoveCentiBody(GetInstance(), body); //recycle
}

const CentipedeDirectionState * CentiBodyManager::GetBodysHeadDirection(CentipedeBody * body)
{
	CentipedePart *tmp = body;

	//chase down to the top of the list, and get (what we assume to be) the head
	while (tmp->GetWhoYoureFollowing() != nullptr)
		tmp = tmp->GetWhoYoureFollowing();

	if(tmp != nullptr)
	{
		auto direction = static_cast<CentipedeHead*>(tmp)->GetDirection();
		return direction;
	}
}

CentiBodyManager * CentiBodyManager::GetInstance()
{
	if(instance == 0)
		instance = new CentiBodyManager;

	return instance;
}
