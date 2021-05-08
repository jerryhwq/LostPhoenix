#include "BossShip.h"

BossShip::BossShip()
{
	isDead = true;
	isCrashed = false;
	isMoving = true;
}

BossShip::~BossShip()
{
}

bool BossShip::init()
{
	return true;
}

void BossShip::Set(SpaceShip*boss)
{
	if (getSprite() != NULL) {
		setVisible(true);
		isCrashed = false;
		isDead = false;
		isMoving = true;
		changeHP(getMaxHP());
		setPosition(boss->getPosition()+Point(200,162)+Point(300*(CCRANDOM_0_1()-0.5),  150*(CCRANDOM_0_1()-1)));
	}
}

void BossShip::dead()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isDead = true;
		setVisible(false);
	}
}

bool BossShip::getInfo()
{
	return isDead;
}

bool BossShip::isCollideWithShip(SpaceShip *spaceship)
{
	if (spaceship->getBoundingBox().intersectsRect(getBoundingBox()) == true) {
		isCrashed = true;
		return true;
	}
	else
		return false;
}

bool BossShip::getMoving()
{
	return isMoving;
}

void BossShip::endMoving()
{
	isMoving = false;
}
