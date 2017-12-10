#include "EnemyBossWeapon2.h"

EnemyBossWeapon2::EnemyBossWeapon2()
{
	posX1 = 0;
	posY1 = 0;
	posX2 = 0;
	posY2 = 0;
}

EnemyBossWeapon2::~EnemyBossWeapon2()
{
}

bool EnemyBossWeapon2::init()
{
	return true;
}

void EnemyBossWeapon2::setAngle(int x1, int y1, int x2, int y2)
{
	posX1 = x1;
	posY1 = y1;
	posX2 = x2;
	posY2 = y2;
}

int EnemyBossWeapon2::getPosX1()
{
	if (posX1 != 0)
		return posX1;
}

int EnemyBossWeapon2::getPosY1()
{
	if (posY1 != 0)
		return posY1;
}

int EnemyBossWeapon2::getPosX2()
{
	if (posX2 != 0)
		return posX2;
}

int EnemyBossWeapon2::getPosY2()
{
	if (posY2 != 0)
		return posY2;
}
