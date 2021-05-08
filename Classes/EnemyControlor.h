#ifndef __ENEMYCONTROLOR_H__
#define __ENEMYCONTROLOR_H__
#define ENEMYONE_MAX_NUM 10
#define ENEMYTWO_MAX_NUM 20
#define ENEMYTHREE_MAX_NUM 2

#include "cocos2d.h"
#include "EnemyOne.h"
#include "EnemyTwo.h"
#include "EnemyThree.h"
USING_NS_CC;

class WeaponControlor;
class Phoenix;

class EnemyControlor :public Node {
public:
	CREATE_FUNC(EnemyControlor);
	virtual bool init();

	void initCreat();

	virtual void update(float dt);

	void creatEnemyOne(float dt);
	void creatEnemyTwo(float dt);
	void creatEnemyThree(float dt);

	void EnemyOneAttackMove(float dt);
	void EnemyTwoAttackMove(float dt);
	void EnemyThreeAttackMove(float dt);
	void EnemyThreeAttackMovePlus(float dt);

	void bindPlayer(Phoenix *phoenix);
	void bindWeaponControlor(WeaponControlor *weaponControlor);


	Vector<EnemyOne*> getEnemyOneArr();
	Vector<EnemyTwo*> getEnemyTwoArr();
	Vector<EnemyThree*> getEnemyThreeArr();

private:

	Phoenix*m_phoenix;

	Vector<EnemyOne*>m_ememyOneArr;
	Vector<EnemyTwo*>m_ememyTwoArr;
	Vector<EnemyThree*>m_ememyThreeArr;

	WeaponControlor *m_weaponControlor;
};

#endif
