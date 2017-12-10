#include "Bonus.h"
#include"Phoenix.h"

Bonus::Bonus()
{
	isUsed = false;
	type = 0;
}

Bonus::~Bonus()
{
}

bool Bonus::init()
{
	return true;
}

bool Bonus::isCollideWithShip(Phoenix * phoenix)
{
	if (phoenix->boundingBox().intersectsRect(boundingBox()) == true) {
		return true;
	}
	else
		return false;
}

void Bonus::randomSet()
{
	if (getSprite() != NULL) {
		setVisible(true);
		isUsed = true;
		setPosition(Point((Director::getInstance()->getVisibleSize().width/2)+500*(CCRANDOM_0_1()-0.5), Director::getInstance()->getVisibleSize().height - 200 * (CCRANDOM_0_1())));
	}
}

bool Bonus::getInfo()
{
	return isUsed;
}

void Bonus::remove()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(0, 0));
		isUsed = false;
		setVisible(false);
	}
}

void Bonus::setType(int t)
{
	type = t;
}

int Bonus::getType()
{
	return type;
}

void Bonus::giveBonus(Phoenix * phoenix)
{
	switch (type)
	{
	case BONUS_SIDEWEAPOM:
		phoenix->setSideWeapon(true);
		break;
	case BONUS_LIFE:
		phoenix->changeHP(phoenix->getMaxHP());
		break;
	case BONUS_BOMB:
		phoenix->setBomb(true);
		break;
	case BONUS_SCORE:
		phoenix->setScore(phoenix->getScore() + 300*phoenix->getDifficulty());
	default:
		break;
	}
}
