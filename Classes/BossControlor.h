#ifndef __BOSSCONTROLOR_H__
#define __BOSSCONTROLOR_H__

#define BOSSONE_MAX_NUM 6



#include "cocos2d.h"
#include "Boss.h"
#include "BossShip.h"
USING_NS_CC;

class WeaponControlor;
class Phoenix;

class BossControlor :public Node {
public:
	CREATE_FUNC(BossControlor);
	virtual bool init();

	void initCreat();

	virtual void update(float dt);

	void creatBossShip(float dt);

	void BossShipAttack(float dt);
	void BossAttack(float dt);
	void BossAttackPlus(float dt);

	void BossShipStartAttack(float dt);
	void BossStartAttack(float dt);

	void BossShipStopAttack(float dt);
	void BossStopAttack(float dt);

	void bindPlayer(Phoenix *phoenix);
	void bindWeaponControlor(WeaponControlor *weaponControlor);


	Vector<BossShip*> getBossShipArr();
	Boss*getBoss();

private:

	Phoenix*m_phoenix;
	Boss*m_boss;
	Sprite*hp;
	ProgressTimer* bossHp;

	bool isAttack1Enabled, isAttackShipEnabled;

	Vector<BossShip*>m_bossShipArr;

	WeaponControlor *m_weaponControlor;

};

#endif
