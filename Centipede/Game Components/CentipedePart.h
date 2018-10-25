#ifndef CENTI_PART
#define CENTI_PART

class CentipedePart
{
public:
	CentipedePart()
		: yourFollower(nullptr), whoYoureFollowing(nullptr) {}
	virtual ~CentipedePart() = default;
	CentipedePart &operator=(const CentipedePart &c) = delete;
	CentipedePart(const CentipedePart &c) = delete;

	void SetWhosFollowingYou(CentipedePart  * const follower) { this->yourFollower = follower; }
	void SetWhoYoureFollowing(CentipedePart * const followee) { this->whoYoureFollowing = followee; }

	CentipedePart *GetWhosFollowingYou() const { return this->yourFollower; }
	CentipedePart *GetWhoYoureFollowing() const { return this->whoYoureFollowing; }

private:
	///each centipede part will have somebody it follows, and sometimes whoever is following it
	CentipedePart * yourFollower, *whoYoureFollowing;
};

#endif // CENTI_PART
