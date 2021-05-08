#include "PhoenixWeapon.h"

PhoenixWeapon::PhoenixWeapon()
{
	isSideWeapon = false;
	type = 0; 
}

PhoenixWeapon::~PhoenixWeapon()
{
}

bool PhoenixWeapon::init()
{
	return true;
}

void PhoenixWeapon::move()
{
	if (getInfo() && isSideWeapon == true) {
		setPosition(startpoint + Point((type * 2 - 3)*8*time, ((cos(1) * 1 * time*time) + (sin(1) * 1 * time))));
	}
	else {
		setPosition(startpoint + Point((type * 2 - 3)*((15 * cos(1)*time) - (sin(1)*0.24*time*time)), ((cos(1) * 1 * time*time) + (sin(1) * 1 * time))));
	}
}

/*
void PhoenixWeapon::remove()
{
	if (getSprite() != NULL) {
		removeAllChildrenWithCleanup(true);
	}
}
void PhoenixWeapon::reset(int x, int y)
{
	if (getSprite() != NULL) {
		setPosition(Point(x, y));
	}
}

*/