#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	defence = 0;
	HP = 0;
	max_HP = 0;
	speed = 0;
}

SpaceShip::~SpaceShip()
{
}

void SpaceShip::hit(int attack)
{
	if (getSprite() == NULL) {
		return;
	}
	HP -= (attack - defence);
	if (HP <= 0)
		HP = 0;
}

void SpaceShip::setValue(int def, int hp, int maxhp, int spe)
{
	defence = def;
	HP = hp;
	max_HP = maxhp;
	speed = spe;
}

int SpaceShip::getHP()
{
	return HP;
}

int SpaceShip::getMaxHP()
{
	return max_HP;
}

void SpaceShip::changeHP(int hp)
{
	if (hp >= max_HP)
		HP = max_HP;
	else
		HP = hp;
}

void SpaceShip::changeMaxHp(int hp)
{
	max_HP = hp;
}
