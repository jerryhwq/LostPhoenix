#ifndef _ENEMYBOSSWEAPON2_H__
#define _ENEMYBOSSWEAPON2_H__

#include"Weapon.h"
#include"cocos2d.h"
USING_NS_CC;

class EnemyBossWeapon2 :public Weapon {
public:
	EnemyBossWeapon2();
	~EnemyBossWeapon2();
	CREATE_FUNC(EnemyBossWeapon2);
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