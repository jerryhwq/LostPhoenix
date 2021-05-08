#ifndef _ENEMYTHREEWEAPON_H__
#define _ENEMYTHREEWEAPON_H__

#include "Weapon.h"
#include "cocos2d.h"
USING_NS_CC;

class EnemyThreeWeapon :public Weapon {
public:
	EnemyThreeWeapon();
	~EnemyThreeWeapon();
	CREATE_FUNC(EnemyThreeWeapon);
	virtual bool init();
public:
	void setAngle(int x1, int y1, int x2, int y2);
	int getPosX1();
	int getPosX2();
	int getPosY1();
	int getPosY2();
private:
	int posX1, posY1, posX2, posY2;

};

#endif
