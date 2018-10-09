#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "CentipedeBody.h"
#include "CentiHeadManager.h"
#include "CentipedeHead.h"

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
	//GetInstance()->MakeBodyHead(body, body->GetHeadDirection());
}

void CentiBodyManager::MakeBodyHead(CentipedeBody * body, CentipedeDirectionState * direction)
{
	body->SetWhoYoureFollowing(0); //head, so wont be following anyone

	CentiBodyFactory::RemoveCentiBody(GetInstance(), body);
	auto head = CentiHeadManager::GetCentiHead();
	head->InitializeHead(); //todo: make function that has it so the body has access to how many followers, and the head theyre following
		//todo: or make it so you can initialize, without the number of heads, so you just can link the linkss
}

CentiBodyManager * CentiBodyManager::GetInstance()
{
	if(instance == 0)
		instance = new CentiBodyManager;

	return instance;
}
