#include "Weapon.h"

Weapon::Weapon()
{
	attack = 0;
	speed = 0;
	isUsed = false;
	time = 0;
	startpoint = Point(0, 0);
}

Weapon::~Weapon()
{
}

bool Weapon::getInfo()
{
	return isUsed;
}

void Weapon::show()
{
	if (getSprite() != NULL) {
		setVisible(true);
		isUsed = true;
	}
}

void Weapon::remove()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isUsed = false;
		setVisible(false);
		time = 0;
	}
}

void Weapon::reset(int x, int y)
{
	if (getSprite() != NULL) {
		setPosition(Point(x, y));
		startpoint = getPosition();
	}
}

void Weapon::timePlus()
{
	time++;
}

Point Weapon::getStartPoint()
{
	return startpoint;
}

bool Weapon::isCollideWithShip(SpaceShip *spaceship)
{
	if (spaceship->getBoundingBox().intersectsRect(getBoundingBox()) == true)
		return true;
	else
		return false;
}
