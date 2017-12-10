#include "EnemyThreeWeapon.h"

EnemyThreeWeapon::EnemyThreeWeapon()
{
	posX1 = 0;
	posY1 = 0;
	posX2 = 0;
	posY2 = 0;
}

EnemyThreeWeapon::~EnemyThreeWeapon()
{
}

bool EnemyThreeWeapon::init()
{
	return true;
}

void EnemyThreeWeapon::setAngle(int x1, int y1, int x2, int y2)
{
	posX1 = x1;
	posY1 = y1;
	posX2 = x2;
	posY2 = y2;
}

int EnemyThreeWeapon::getPosX1()
{
	if (posX1 != 0)
		return posX1;
}

int EnemyThreeWeapon::getPosY1()
{
	if (posY1 != 0)
		return posY1;
}

int EnemyThreeWeapon::getPosX2()
{
	if (posX2 != 0)
		return posX2;
}

int EnemyThreeWeapon::getPosY2()
{
	if (posY2 != 0)
		return posY2;
}
