#include "Boss.h"

Boss::Boss()
{
	isDead = true;
	isCrashed = false;
}

Boss::~Boss()
{
}

bool Boss::init()
{
	return true;
}

void Boss::randonSet()
{
	if (getSprite() != NULL) {
		setVisible(true);
		isCrashed = false;
		isDead = false;
		changeHP(getMaxHP());
		setPosition(Point((Director::getInstance()->getVisibleSize().width / 2) + ((0.8*Director::getInstance()->getVisibleSize().width) * (CCRANDOM_0_1() - 0.5)), Director::getInstance()->getVisibleSize().height - 324) );
	}
}

void Boss::dead()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isDead = true;
		setVisible(false);
	}
}

bool Boss::getInfo()
{
	return isDead;
}

bool Boss::isCollideWithShip(SpaceShip *spaceship)
{
	if (spaceship->boundingBox().intersectsRect(boundingBox()) == true) {
		isCrashed = true;
		return true;
	}
	else
		return false;
}
