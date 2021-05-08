#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
#include "Entity.h"
#include "SpaceShip.h"

USING_NS_CC;

class Weapon : public Entity {
public:
	Weapon();
	~Weapon();
public:
	bool getInfo();
	void show();
	void remove();
	void reset(int x, int y);
	void timePlus();
	Point getStartPoint();

	int attack, speed;
	bool isCollideWithShip(SpaceShip* spaceship);
protected:
	int time;
	Point startpoint;
private:
	bool isUsed;
};


#endif
