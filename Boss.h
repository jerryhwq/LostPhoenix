#ifndef __BOSS_H__
#define __BOSS_H__

#include"SpaceShip.h"
#include"cocos2d.h"
USING_NS_CC;

class Boss :public SpaceShip {
public:
	Boss();
	~Boss();
	CREATE_FUNC(Boss);
	virtual bool init();

	void randonSet();
	void dead();
	bool getInfo();

	bool isCollideWithShip(SpaceShip * spaceship);


	bool isCrashed;

private:
	bool isDead;
private:
};


#endif