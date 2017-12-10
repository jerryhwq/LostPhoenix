#include "EnemyBossWeapon1.h"

EnemyBossWeapon1::EnemyBossWeapon1()
{
	posX1 = 0;
	posY1 = 0;
	posX2 = 0;
	posY2 = 0;
}

EnemyBossWeapon1::~EnemyBossWeapon1()
{
}

bool EnemyBossWeapon1::init()
{
	return true;
}

void EnemyBossWeapon1::setAngle(int x1, int y1, int x2, int y2)
{
	posX1 = x1;
	posY1 = y1;
	posX2 = x2;
	posY2 = y2;
}

int EnemyBossWeapon1::getPosX1()
{
	if (posX1 != 0)
		return posX1;
}

int EnemyBossWeapon1::getPosY1()
{
	if (posY1 != 0)
		return posY1;
}

int EnemyBossWeapon1::getPosX2()
{
	if (posX2 != 0)
		return posX2;
}

int EnemyBossWeapon1::getPosY2()
{
	if (posY2 != 0)
		return posY2;
}
