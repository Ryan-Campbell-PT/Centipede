#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "CentipedeBody.h"
#include "CentiHeadManager.h"
#include "CentipedeHead.h"
#include "MushroomManager.h"

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
	auto direction = GetInstance()->GetBodysHeadDirection(body);
	GetInstance()->MakeBodyHead(body, direction);
}

void CentiBodyManager::MakeBodyHead(CentipedeBody * body, const CentipedeDirectionState * direction)
{
	body->SetWhoYoureFollowing(0); //head, so wont be following anyone
	
	CentiBodyFactory::RemoveCentiBody(GetInstance(), body);
	auto head = CentiHeadManager::GetCentiHead();
	head->InitializeHead(head->GetPosition(), *direction);




	//todo: make function that has it so the body has access to how many followers, and the head theyre following
		//todo: or make it so you can initialize, without the number of heads, so you just can link the linkss
}

void CentiBodyManager::RemoveCentiBody(CentipedeBody * body)
{
	MushroomManager::AttemptSpawnShroom(body->GetPosition()); //spawn the shroom where the body died

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
