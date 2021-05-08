#ifndef __ENEMYONE_H__
#define __ENEMYONE_H__

#include"SpaceShip.h"
#include"cocos2d.h"
USING_NS_CC;

class EnemyOne :public SpaceShip {
public:
	EnemyOne();
	~EnemyOne();
	CREATE_FUNC(EnemyOne);
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