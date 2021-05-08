#ifndef _ENEMYWEAPON1_H__
#define _ENEMYWEAPON1_H__

#include"Weapon.h"
#include"cocos2d.h"
USING_NS_CC;

class EnemyWeapon1 :public Weapon {
public:
	EnemyWeapon1();
	~EnemyWeapon1();
	CREATE_FUNC(EnemyWeapon1);
	virtual bool init();
public:
	void setAngle(int x1,int y1,int x2,int y2);
	int getPosX1(); 
	int getPosX2();
	int getPosY1();
	int getPosY2();
	//void remove();
	//void reset(int x, int y);
private:
	int posX1, posY1,posX2,posY2;
	
};

#endif