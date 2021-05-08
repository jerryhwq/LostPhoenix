#ifndef __PHOENIXWEAPON_H__
#define __PHOENIXWEAPON_H__

#include"cocos2d.h"
#include"Weapon.h"
USING_NS_CC;

class PhoenixWeapon :public Weapon {
public:
	PhoenixWeapon();
	~PhoenixWeapon();
	CREATE_FUNC(PhoenixWeapon);
	virtual bool init();
	void move();
public:
	bool isSideWeapon;
	int type;
};

#endif
