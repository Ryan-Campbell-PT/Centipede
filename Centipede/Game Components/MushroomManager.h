#ifndef MUSHROOM_MANAGER
#define MUSHROOM_MANAGER

#include "TEAL/CommonElements.h"
#include "Observee.h"

class Mushroom;
class Observer;

class MushroomManager : public Observee
{
public:
	///this initialize will setup mushrooms assuming you havent before (fresh start)
	static void InitializeMushroomField(int numShrooms);
	///this initialize assumes youve already been given a setup, and you just want to reinstate them
	static void InitializeMushroomField(std::list<Mushroom*> *shroomField);
	///given a position on screen, the mushroomManager will attempt to spawn a mushroom if avaliable
	static bool AttemptSpawnShroom(sf::Vector2f pos);

	static void RemoveMushroom(Mushroom * const shroom);
	///this will be used for whatever happens when the game ends
	static void EndWave();
	static std::list<Mushroom*>* GetCurrentLayout();

	MushroomManager(const MushroomManager &s) = delete;
	MushroomManager operator = (const MushroomManager &) = delete;

	static void AddNewObserver(Observer *o);
	static void RemoveCurrentObserver(Observer *o);

	static void Terminate();

protected:
	virtual void UpdateObservees() override;
	virtual void AddObservee(Observer* o) override;
	virtual void RemoveObservee(Observer* o) override;

private:
	MushroomManager() = default;
	virtual ~MushroomManager() = default;

	static MushroomManager * GetInstance();
	void SpawnMushroom(sf::Vector2f &pos) const;
	void initializeMushroomField(std::list<Mushroom*> *shroomField);

	std::list<Observer*> observerList;
	static MushroomManager* instance;
};

#endif // !MUSHROOM_MANAGER
