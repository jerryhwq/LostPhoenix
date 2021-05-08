#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__

#include"cocos2d.h"
#include"Entity.h"

USING_NS_CC;

class SpaceShip :public Entity {
public:
	SpaceShip();
	~SpaceShip();

	void hit(int attack);
	void setValue(int def, int hp, int maxhp, int spe);
	int getHP();
	int getMaxHP();
	void changeHP(int hp);
	void changeMaxHp(int hp);
private:
	int defence, HP,max_HP, speed;
};

#endif
