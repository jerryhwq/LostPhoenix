#ifndef __BONUS_H__
#define __BONUS_H__

#define BONUS_SIDEWEAPOM 1
#define BONUS_LIFE 2
#define BONUS_BOMB 3
#define BONUS_SCORE 4

#include"cocos2d.h"
#include"Entity.h"

USING_NS_CC;

class Phoenix;

class Bonus :public Entity {
public:
	Bonus();
	~Bonus();
	CREATE_FUNC(Bonus);
	virtual bool init();

	bool isCollideWithShip(Phoenix * phoenix);
	void randomSet();
	bool getInfo();
	void remove();
	void setType(int t);
	int getType();
	void giveBonus(Phoenix * phoenix);
private:
	bool isUsed;
	int type;
	
};

#endif