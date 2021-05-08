#ifndef __WEAPONCONTROLOR_H__
#define __WEAPONCONTROLOR_H__
#define MAX_NUM_ENEMYONE 80
#define MAX_NUM_ENEMYTWO 160
#define MAX_NUM_ENEMYTHREE 60
#define MAX_NUM_ENEMYTHREEPLUS 4
#define MAX_NUM_BOSSSHIP 60
#define MAX_NUM_BOSSONE 80
#define MAX_NUM_BOSSTWO 16
#define MAX_NUM_PHOENIX 20
#define DEGREE15 0.26179938779915
#define DEGREE10 0.17453292519943

#include "cocos2d.h"
#include "PhoenixWeapon.h"
#include "EnemyWeapon1.h"
#include "EnemyOne.h"
#include "EnemyTwoWeapon.h"
#include "EnemyTwo.h"
#include "EnemyThreeWeapon.h"
#include "EnemyThreeWeaponPlus.h"
#include "EnemyThree.h"
#include "Boss.h"
#include "BossShip.h"
#include "EnemyBossWeapon1.h"
#include "EnemyBossWeapon2.h"
#include "EnemyBossShipWeapon.h"
USING_NS_CC;

class EnemyControlor;
class BossControlor;
class Phoenix;

class WeaponControlor :public Node {
public:
	CREATE_FUNC(WeaponControlor);
	virtual bool init();

	virtual void update(float dt);

	void EnemyOneShoot(EnemyOne *ship);
	void EnemyTwoShoot(EnemyTwo *ship);
	void EnemyThreeShoot(EnemyThree *ship);
	void EnemyThreeShootPlus(EnemyThree *ship);
	void EnemyBossShoot1(Boss*ship);
	void EnemyBossShoot2(Boss*ship);
	void EnemyBossShipShoot1(BossShip*ship);
	void phoenixShoot();

	void bindPlayer(Phoenix *phoenix);
	void bindEnemyControlor(EnemyControlor *enemyControlor);
	void bindBossControlor(BossControlor *bossControlor);

	void initCreatEnemyOne();
	void initCreatEnemyTwo();
	void initCreatEnemyThree();
	void initCreatEnemyThreePlus();
	void initCreatBoss1();
	void initCreatBoss2();
	void initCreatBossShip();

	void initCreatPhoenix();

	Vector<EnemyWeapon1*> getEnemyOne();
	Vector<EnemyTwoWeapon*> getEnemyTwo();
	Vector<EnemyThreeWeapon*> getEnemyThree();
	Vector<EnemyThreeWeaponPlus*> getEnemyThreePlus();
	Vector<EnemyBossWeapon1*> getEnemyBoss1();
	Vector<EnemyBossWeapon2*> getEnemyBoss2();
	Vector<EnemyBossShipWeapon*> getEnemyBossShip();
private:
	Phoenix*m_phoenix;

	Vector<PhoenixWeapon*> m_PhoenixWeaponArr;
	Vector<EnemyWeapon1*>m_enemyWeapon1Arr;
	Vector<EnemyTwoWeapon*>m_enemyTwoWeaponArr;
	Vector<EnemyThreeWeapon*>m_enemyThreeWeaponArr;
	Vector<EnemyThreeWeaponPlus*>m_enemyThreeWeaponPlusArr;
	Vector<EnemyBossWeapon1*>m_enemyBoss1Arr;
	Vector<EnemyBossWeapon2*>m_enemyBoss2Arr;
	Vector<EnemyBossShipWeapon*>m_enemyBossShipArr;


	EnemyControlor *m_enemyColtrolor;
	BossControlor *m_bossControlor;
};


#endif
