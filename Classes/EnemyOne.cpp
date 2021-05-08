#include "EnemyOne.h"

EnemyOne::EnemyOne()
{
	isDead = true;
	isCrashed = false;
}

EnemyOne::~EnemyOne()
{
}

bool EnemyOne::init()
{
	return true;
}

void EnemyOne::randonSet()
{
	if (getSprite() != NULL) {
		setVisible(true);
		isCrashed = false;
		isDead = false;
		changeHP(getMaxHP());
		setPosition(Point((Director::getInstance()->getVisibleSize().width / 2) + ((0.8*Director::getInstance()->getVisibleSize().width) * (CCRANDOM_0_1() - 0.5)), Director::getInstance()->getVisibleSize().height - 80* (CCRANDOM_0_1())));
	}
}

void EnemyOne::dead()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isDead = true;
		setVisible(false);
	}
}

bool EnemyOne::getInfo()
{
	return isDead;
}

bool EnemyOne::isCollideWithShip(SpaceShip *spaceship)
{
	if (spaceship->getBoundingBox().intersectsRect(getBoundingBox()) == true) {
		isCrashed = true;
		return true;
	}
	else
		return false;
}
