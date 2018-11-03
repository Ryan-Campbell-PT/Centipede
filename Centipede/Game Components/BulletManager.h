#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

class BulletManager
{
public:
	static bool AttemptSpawnBullet();

	void SetBulletInactive() { this->bulletIsActive = false; }

	static void Terminate();

private:
	BulletManager();
	virtual ~BulletManager() = default;
	static BulletManager* GetInstance();
	static BulletManager* instance;

	void spawnBullet();
	bool bulletIsActive;
};

#endif // BULLETMANAGER_H
