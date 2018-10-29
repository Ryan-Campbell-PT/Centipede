#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "CentipedeBody.h"
#include "CentiHeadManager.h"
#include "CentipedeHead.h"
#include "MushroomManager.h"
#include "CentipedeDirectionState.h"

CentiBodyManager * CentiBodyManager::instance = nullptr;

CentipedeBody * CentiBodyManager::GetCentiBody()
{
	return CentiBodyFactory::GetCentiBody();
}

CentipedeBody * CentiBodyManager::GetInitializedCentiBody(sf::Vector2f const & pos, OffsetArray const & direction)
{
	auto body = CentiBodyFactory::GetCentiBody();
	body->InitializeBody(pos, direction);

	return body;
}

void CentiBodyManager::SetBehindBodyToHead(CentipedeBody * body)
{
	if (body != nullptr)
		if (body->GetWhoYoureFollowing()) //whoever you were following
			body->GetWhoYoureFollowing()->SetWhosFollowingYou(nullptr); //tell them nobody is following anymore

	SetBodyToHead(static_cast<CentipedeBody*>(body->GetWhosFollowingYou()));
}

void CentiBodyManager::SetBodyToHead(CentipedeBody * body)
{
	if (body == nullptr)
		return; //nobody is following you, no need to do anything

	body->MarkForDestroy(); //take off screen, no longer care about body
	auto head = CentiHeadManager::GetCentiHead();
	const auto direction = GetInstance()->GetBodysHeadDirection(body);

	//align links

	if (body->GetWhosFollowingYou())
		body->GetWhosFollowingYou()->SetWhoYoureFollowing(head); //set the behind body to the newly created head

	if (body->GetWhoYoureFollowing())
		body->GetWhoYoureFollowing()->SetWhosFollowingYou(nullptr); //make the body infront of you the tail of that centi

	head->SetWhosFollowingYou(body->GetWhosFollowingYou()); //set the current head, to have the same follower as the body did
	head->SetWhoYoureFollowing(nullptr); //youre the head, you dont have anyone to follow

	//head->InitializeHead(body->GetPosition(), *direction);
	CentiHeadManager::InitializeHead(head, body->GetPosition(), *direction);

	body->SetWhosFollowingYou(nullptr);
	body->SetWhoYoureFollowing(nullptr);
}

void CentiBodyManager::EndWave()
{
}

const CentipedeDirectionState * CentiBodyManager::GetBodysHeadDirection(CentipedeBody * body)
{
	CentipedePart *tmp = body;

	//chase down to the top of the list, and get (what we assume to be) the head
	while (tmp->GetWhoYoureFollowing() != nullptr)
		tmp = tmp->GetWhoYoureFollowing();

	if (tmp != nullptr)
		return static_cast<CentipedeHead*>(tmp)->GetDirection();
}

CentiBodyManager * CentiBodyManager::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyManager;

	return instance;
}
