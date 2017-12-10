#include"Phoenix.h"
#include"SimpleAudioEngine.h"

Phoenix::Phoenix()
{
	difficulty = 1;
	m_score = 0;
	level = 1;
	exp = 0;
	isBombEnabled = true;
	isSideWeaponEquiped = false;
	isDead = false;
	isBossAppear = false;
	isBossDead = false;
}

Phoenix::~Phoenix()
{
}


bool Phoenix::init()
{
	
	return true;
}

int Phoenix::getExp()
{
	return exp;
}

void Phoenix::giveExp(int extra)
{
	exp += extra;
	if (exp >= 50+50*level) {
		exp -= 50 + 50 * level;
		levelUp();
	}
}

void Phoenix::setExp(int e)
{
	exp = e;
}

int Phoenix::getLevel()
{
	return level;
}

void Phoenix::levelUp()
{
	level += 1;
	changeMaxHp(getMaxHP() + (4-difficulty)*3);
	changeHP(getHP()+20);
}

void Phoenix::setLevel(int l)
{
	level = l;
}

int Phoenix::getDifficulty()
{
	return difficulty;
}

void Phoenix::setDifficulty(int d)
{
	difficulty = d;
}

void Phoenix::setSideWeapon(bool have)
{
	isSideWeaponEquiped = have;
}

void Phoenix::setBomb(bool have)
{
	isBombEnabled = have;
}

bool Phoenix::getSideWeapon()
{
	return isSideWeaponEquiped;
}

bool Phoenix::getBomb()
{
	return isBombEnabled;
}

void Phoenix::setScore(int s)
{
	m_score = s;
}

int Phoenix::getScore()
{
	return m_score;
}

void Phoenix::dead()
{
	isDead = true;
	setVisible(false);
	setPosition(Point(500, -300));
}

bool Phoenix::getInfo()
{
	return isDead;
}

