#ifndef _Level_Attractor
#define _Level_Attractor

#include "TEAL/CommonElements.h"

class LevelAttractor : public Scene
{
public:
	virtual void Initialize() override;
	void Terminate() override;
};

#endif _Level_Attractor