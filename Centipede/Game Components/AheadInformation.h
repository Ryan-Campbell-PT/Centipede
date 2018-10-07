#include "TEAL/CommonElements.h"

enum class CentiMovementDirectionEnum;

///this class holds the information that the bodies will look towards to know when to turn
///the vector records the point that the ahead body turned at
///while the direction holds the direction the ahead went, so the body can then go that way
class AheadInformation
{
public:
	AheadInformation() {};
	AheadInformation(sf::Vector2f const &turningPoint, CentiMovementDirectionEnum const &direction)
		:turningPoint(turningPoint), direction(direction) {}

	sf::Vector2f turningPoint;
	CentiMovementDirectionEnum direction;
};
