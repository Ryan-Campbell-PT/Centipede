#include "ScoreByDistanceCmd.h"
#include <iostream>
#include "ScoreManager.h"

ScoreByDistanceCmd::ScoreByDistanceCmd(int dn, int dm, int df,
									   int vn, int vm, int vf)
	: dNear(dn), dMed(dm), dFar(df), vNear(vn), vMed(vm), vFar(vf)
{
	printf("Score by distance command created\n");
	printf("\tdist <= %i  is worth %i points\n", dNear, vNear);
	printf("\tdist <= %i  is worth %i points\n", dMed, vMed);
	printf("\tdist <= %i  is worth %i points\n", dFar, vFar);
}

void ScoreByDistanceCmd::Execute()
{
	int ans;
	std::cout << "Score By Distance Command: Simulating distance computation\n";
	std::cout << "Distance to player ? ";
	std::cin >> ans;

	// processing distance to score:
	if (ans <= dNear)
	{
		printf("Near range detected:\n");
		ScoreManager::AddScore(vNear);
	}
	else if (ans <= dMed)
	{
		printf("Medium range detected:\n");
		ScoreManager::AddScore(vMed);
	}
	else
	{
		printf("Far range detected:\n");
		ScoreManager::AddScore(vFar);
	}
}