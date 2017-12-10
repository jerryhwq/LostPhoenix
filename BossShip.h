#ifndef __BOSSSHIP_H__
#define __BOSSSHIP_H__

#include"SpaceShip.h"
#include"cocos2d.h"
USING_NS_CC;

class BossShip :public SpaceShip {
public:
	BossShip();
	~BossShip();
	CREATE_FUNC(BossShip);
	virtual bool init();

	void Set(SpaceShip* boss);
	void dead();
	bool getInfo();

	bool isCollideWithShip(SpaceShip * spaceship);
	bool getMoving();
	void endMoving();

	bool isCrashed;

private:
	bool isDead;
	bool isMoving;
};


#endif
