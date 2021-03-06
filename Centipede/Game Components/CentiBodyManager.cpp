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

CentipedeBody * CentiBodyManager::GetInitializedCentiBody(sf::Vector2f const & pos, const int &speed, OffsetArray const & direction)
{
	auto body = CentiBodyFactory::GetCentiBody();
	body->InitializeBody(pos, speed, direction);

	return body;
}

void CentiBodyManager::SetBodyToHead(CentipedeBody * body, const CentipedeDirectionState *direction)
{
	if (body == nullptr)
		return; //nobody is following you, no need to do anything

	body->MarkForDestroy(); //take off screen, no longer care about body
	auto head = CentiHeadManager::GetCentiHead();
	//const auto direction = GetInstance()->GetBodysHeadDirection(body);

	//align links

	if (body->GetWhosFollowingYou())
		body->GetWhosFollowingYou()->SetWhoYoureFollowing(head); //set the behind body to the newly created head

	if (body->GetWhoYoureFollowing())
		body->GetWhoYoureFollowing()->SetWhosFollowingYou(nullptr); //make the body infront of you the tail of that centi

	head->SetWhosFollowingYou(body->GetWhosFollowingYou()); //set the current head, to have the same follower as the body did
	head->SetWhoYoureFollowing(nullptr); //youre the head, you dont have anyone to follow

	CentiHeadManager::InitializeHead(head, body->GetPosition(), *direction);

	body->SetWhosFollowingYou(nullptr);
	body->SetWhoYoureFollowing(nullptr);
}

void CentiBodyManager::SetBodyToHead(CentipedeBody* body)
{
	SetBodyToHead(body, GetInstance()->GetBodysHeadDirection(body));
}

void CentiBodyManager::EndWave()
{
}

void CentiBodyManager::Terminate()
{
	delete instance;
	instance = nullptr;

	CentiBodyFactory::Terminate();
}

const CentipedeDirectionState * CentiBodyManager::GetBodysHeadDirection(CentipedeBody * body) const
{
	/*
	 * this function felt like a lesser of two evils. Either I have the head constantly
	 * send its direction with every check, so that way when a body is destroyed it knows in constant time
	 * what direction to go. but that takes much more computation. So instead i just have the body search for its
	 * heads direction only when destroyed, which is at most N time (as opposted to N every check)
	 */

	if(body == nullptr)
		return nullptr;

	CentipedePart *tmp = body;

	//chase down to the top of the list, and get (what we assume to be) the head
	while (tmp->GetWhoYoureFollowing() != nullptr)
		tmp = tmp->GetWhoYoureFollowing();

	return static_cast<CentipedeHead*>(tmp)->GetDirection();
}

CentiBodyManager * CentiBodyManager::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiBodyManager;

	return instance;
}
