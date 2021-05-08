#include "EnemyThreeWeaponPlus.h"

EnemyThreeWeaponPlus::EnemyThreeWeaponPlus()
{
	posX1 = 0;
	posY1 = 0;
	posX2 = 0;
	posY2 = 0;
}

EnemyThreeWeaponPlus::~EnemyThreeWeaponPlus()
{
}

bool EnemyThreeWeaponPlus::init()
{
	return true;
}

void EnemyThreeWeaponPlus::setAngle(int x1, int y1, int x2, int y2)
{
	posX1 = x1;
	posY1 = y1;
	posX2 = x2;
	posY2 = y2;
}

int EnemyThreeWeaponPlus::getPosX1()
{
	if (posX1 != 0)
		return posX1;
}

int EnemyThreeWeaponPlus::getPosY1()
{
	if (posY1 != 0)
		return posY1;
}

int EnemyThreeWeaponPlus::getPosX2()
{
	if (posX2 != 0)
		return posX2;
}

int EnemyThreeWeaponPlus::getPosY2()
{
	if (posY2 != 0)
		return posY2;
}
