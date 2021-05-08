#ifndef __ENEMYTHREE_H__
#define __ENEMYTHREE_H__

#include"SpaceShip.h"
#include"cocos2d.h"
USING_NS_CC;

class EnemyThree :public SpaceShip {
public:
	EnemyThree();
	~EnemyThree();
	CREATE_FUNC(EnemyThree);
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
