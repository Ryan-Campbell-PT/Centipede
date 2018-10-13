#ifndef SCORE_BY_DISTANCE
#define SCORE_BY_DISTANCE

#include "ScoreCmd.h"

class ScoreByDistanceCmd : public ScoreCmd
{
private:
	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;

public:
	ScoreByDistanceCmd(int dNear, int dMed, int dFar,
					   int vNear, int vMed, int vFar);

	virtual void Execute() override;


};

#endif //SCORE_BY_DISTANCE