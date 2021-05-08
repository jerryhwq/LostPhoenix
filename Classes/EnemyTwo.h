#ifndef __ENEMYTWO_H__
#define __ENEMYTWO_H__

#include"SpaceShip.h"
#include"cocos2d.h"
USING_NS_CC;

class EnemyTwo :public SpaceShip {
public:
	EnemyTwo();
	~EnemyTwo();
	CREATE_FUNC(EnemyTwo);
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