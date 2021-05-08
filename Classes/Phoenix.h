#ifndef __PHOENIX_H__
#define __PHOENIX_H__

#include"cocos2d.h"
#include"SpaceShip.h"

USING_NS_CC;

class Phoenix :public SpaceShip {
public:
	Phoenix();
	~Phoenix();
	CREATE_FUNC(Phoenix);
	virtual bool init();

	int getExp();
	void giveExp(int extra);
	void setExp(int e);

	int getLevel();
	void levelUp();
	void setLevel(int l);

	int getDifficulty();
	void setDifficulty(int d);

	void setSideWeapon(bool have);
	void setBomb(bool have);
	bool getSideWeapon();
	bool getBomb();

	void setScore(int s);
	int getScore();

	void dead();
	bool getInfo();

	bool isBossAppear;
	bool isBossDead;

private:
	int exp,level;
	int m_score,difficulty;
	bool isSideWeaponEquiped, isBombEnabled,isDead;
};

#endif