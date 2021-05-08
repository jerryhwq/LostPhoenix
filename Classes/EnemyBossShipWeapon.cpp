#include "EnemyBossShipWeapon.h"

EnemyBossShipWeapon::EnemyBossShipWeapon()
{
	posX1 = 0;
	posY1 = 0;
	posX2 = 0;
	posY2 = 0;
}

EnemyBossShipWeapon::~EnemyBossShipWeapon()
{
}

bool EnemyBossShipWeapon::init()
{
	return true;
}

void EnemyBossShipWeapon::setAngle(int x1, int y1, int x2, int y2)
{
	posX1 = x1;
	posY1 = y1;
	posX2 = x2;
	posY2 = y2;
}

int EnemyBossShipWeapon::getPosX1()
{
	if (posX1 != 0)
		return posX1;
}

int EnemyBossShipWeapon::getPosY1()
{
	if (posY1 != 0)
		return posY1;
}

int EnemyBossShipWeapon::getPosX2()
{
	if (posX2 != 0)
		return posX2;
}

int EnemyBossShipWeapon::getPosY2()
{
	if (posY2 != 0)
		return posY2;
}
