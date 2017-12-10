#include "EnemyTwoWeapon.h"

EnemyTwoWeapon::EnemyTwoWeapon()
{
	posX1 = 0;
	posY1= 0;
	posX2 = 0;
	posY2 = 0;
}

EnemyTwoWeapon::~EnemyTwoWeapon()
{
}

bool EnemyTwoWeapon::init()
{
	return true;
}

void EnemyTwoWeapon::setAngle(int x1, int y1, int x2, int y2)
{
	posX1 = x1;
	posY1 = y1;
	posX2 = x2;
	posY2 = y2;
}

int EnemyTwoWeapon::getPosX1()
{
	if(posX1!=0)
		return posX1;
}

int EnemyTwoWeapon::getPosY1()
{
	if(posY1!=0)
		return posY1;
}

int EnemyTwoWeapon::getPosX2()
{
	if (posX2 != 0)
		return posX2;
}

int EnemyTwoWeapon::getPosY2()
{
	if (posY2 != 0)
		return posY2;
}
