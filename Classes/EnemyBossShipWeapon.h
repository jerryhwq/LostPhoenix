#ifndef _ENEMYBOSSSHIPWEAPON_H__
#define _ENEMYBOSSSHIPWEAPON_H__

#include"Weapon.h"
#include"cocos2d.h"
USING_NS_CC;

class EnemyBossShipWeapon :public Weapon {
public:
	EnemyBossShipWeapon();
	~EnemyBossShipWeapon();
	CREATE_FUNC(EnemyBossShipWeapon);
	virtual bool init();
public:
	void setAngle(int x1, int y1, int x2, int y2);
	int getPosX1();
	int getPosX2();
	int getPosY1();
	int getPosY2();
	//void remove();
	//void reset(int x, int y);
private:
	int posX1, posY1, posX2, posY2;

};

#endif
