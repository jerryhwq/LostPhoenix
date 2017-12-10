#include "EnemyThree.h"

EnemyThree::EnemyThree()
{
	isDead = true;
	isCrashed = false;
}

EnemyThree::~EnemyThree()
{
}

bool EnemyThree::init()
{
	return true;
}

void EnemyThree::randonSet()
{
	if (getSprite() != NULL) {
		setVisible(true);
		isCrashed = false;
		isDead = false;
		changeHP(getMaxHP());
		setPosition(Point((Director::getInstance()->getVisibleSize().width / 2) + ((0.8*Director::getInstance()->getVisibleSize().width) * (CCRANDOM_0_1() - 0.5)), Director::getInstance()->getVisibleSize().height + 200));
	}
}

void EnemyThree::dead()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isDead = true;
		setVisible(false);
	}
}

bool EnemyThree::getInfo()
{
	return isDead;
}

bool EnemyThree::isCollideWithShip(SpaceShip *spaceship)
{
	if (spaceship->boundingBox().intersectsRect(boundingBox()) == true) {
		isCrashed = true;
		return true;
	}
	else
		return false;
}
