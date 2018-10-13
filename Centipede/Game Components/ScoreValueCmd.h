#ifndef SCORE_VALUE_CMD
#define SCORE_VALUE_CMD

#include "ScoreCmd.h"
#include "ScoreManager.h"

class ScoreValueCmd : public ScoreCmd
{
protected:
	int points;	// points to add
	
public:
	ScoreValueCmd() = delete;
	ScoreValueCmd(int val)
		:points(val)
	{
	};

    virtual void Execute() override
    {
	    ScoreManager::AddScore(this->points);
    };

};

#endif //SCORE_VALUE_CMD