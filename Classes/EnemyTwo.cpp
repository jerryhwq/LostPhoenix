#include "EnemyTwo.h"

EnemyTwo::EnemyTwo()
{
	isDead = true;
	isCrashed = false;
}

EnemyTwo::~EnemyTwo()
{
}

bool EnemyTwo::init()
{
	return true;
}

void EnemyTwo::randonSet()
{
	if (getSprite() != NULL) {
		setVisible(true);
		isCrashed = false;
		isDead = false;
		changeHP(getMaxHP());
		setPosition(Point((Director::getInstance()->getVisibleSize().width / 2) + ((0.8*Director::getInstance()->getVisibleSize().width) * (CCRANDOM_0_1() - 0.5)), Director::getInstance()->getVisibleSize().height - 100 * (CCRANDOM_0_1())));
	}
}

void EnemyTwo::dead()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isDead = true;
		setVisible(false);
	}
}

bool EnemyTwo::getInfo()
{
	return isDead;
}

bool EnemyTwo::isCollideWithShip(SpaceShip *spaceship)
{
	if (spaceship->getBoundingBox().intersectsRect(getBoundingBox()) == true) {
		isCrashed = true;
		return true;
	}
	else
		return false;
}
