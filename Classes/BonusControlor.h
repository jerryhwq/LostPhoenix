#ifndef __BONUSCONTROLOR_H__
#define __BONUSCONTROLOR_H__

#include"cocos2d.h"
#include"Bonus.h"
USING_NS_CC;

class Phoenix;


class BonusControlor :public Entity {
public:
	CREATE_FUNC(BonusControlor);
	virtual bool init();

	void initCreat();

	virtual void update(float dt);
	void creatBonus(float dt);
	void sideWeaponOff(float dt);

	void bindPlayer(Phoenix *phoenix);
private:
	Phoenix*m_phoenix;
	Vector<Bonus*>m_bonusOneArr;
};

#endif
