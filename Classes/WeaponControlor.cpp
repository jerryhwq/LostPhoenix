#include "WeaponControlor.h"
#include"EnemyControlor.h"
#include"BossControlor.h"
#include"Phoenix.h"
#include"SimpleAudioEngine.h"


bool WeaponControlor::init()
{
	
	initCreatPhoenix();
	return true;
}


void WeaponControlor::update(float dt)
{
	for (auto weapon : m_PhoenixWeaponArr) {
		if (weapon->getInfo()) {
			if (weapon->getInfo() && weapon->isSideWeapon == true) {
				//weapon->setPositionY(weapon->getPositionY() + (weapon->speed));
				//weapon->setPositionX(weapon->getPositionX() + ((weapon->type * 2 - 3)*(weapon->speed) / 2));
				weapon->timePlus();
				weapon->move();
			}
			else{
				weapon->timePlus();
				//weapon->setPositionY(weapon->getPositionY() + weapon->speed);
				weapon->move();
			}

			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height)
			{
				weapon->isSideWeapon = false;
				weapon->remove();
			}
			else {
				for (auto enemyone : m_enemyColtrolor->getEnemyOneArr()) {
					if (weapon->isCollideWithShip(enemyone) && !enemyone->getInfo()) {
						enemyone->hit(weapon->attack);
						weapon->isSideWeapon = false;
						weapon->remove();
					}
				}
				for (auto enemytwo : m_enemyColtrolor->getEnemyTwoArr()) {
					if (weapon->isCollideWithShip(enemytwo) && !enemytwo->getInfo()) {
						enemytwo->hit(weapon->attack);
						weapon->isSideWeapon = false;
						weapon->remove();
					}
				}
				for (auto enemythree : m_enemyColtrolor->getEnemyThreeArr()) {
					if (weapon->isCollideWithShip(enemythree) && !enemythree->getInfo()) {
						enemythree->hit(weapon->attack);
						weapon->isSideWeapon = false;
						weapon->remove();
					}
				}
				for (auto enemyBoss : m_bossControlor->getBossShipArr()) {
					if (weapon->isCollideWithShip(enemyBoss) && !enemyBoss->getInfo()) {
						enemyBoss->hit(weapon->attack);
						weapon->isSideWeapon = false;
						weapon->remove();
					}
				}
				if (weapon->isCollideWithShip(m_bossControlor->getBoss()) && !m_bossControlor->getBoss()->getInfo()) {
					m_bossControlor->getBoss()->hit(weapon->attack);
					weapon->isSideWeapon = false;
					weapon->remove();
				}
			}
		}
	}
	for (auto weapon : m_enemyWeapon1Arr) {
		if (weapon->getInfo()) {
			weapon->setPositionX(weapon->getPositionX() - weapon->speed * ((weapon->getPosX1() - weapon->getPosX2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			weapon->setPositionY(weapon->getPositionY() - weapon->speed * ((weapon->getPosY1() - weapon->getPosY2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1*m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
	for (auto weapon : m_enemyTwoWeaponArr) {
		if (weapon->getInfo()) {
			weapon->setPositionY(weapon->getPositionY() - weapon->speed);
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1 * m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
	for (auto weapon : m_enemyThreeWeaponPlusArr) {
		if (weapon->getInfo()) {
			weapon->setPositionY(weapon->getPositionY() - weapon->speed);
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1 * m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
	for (auto weapon : m_enemyThreeWeaponArr) {
		if (weapon->getInfo()) {
			weapon->setPositionX(weapon->getPositionX() - weapon->speed * ((weapon->getPosX1() - weapon->getPosX2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			weapon->setPositionY(weapon->getPositionY() - weapon->speed * ((weapon->getPosY1() - weapon->getPosY2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0|| weapon->getPositionX() >= Director::getInstance()->getVisibleSize().width || weapon->getPositionX() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1 * m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
	for (auto weapon : m_enemyBoss1Arr) {
		if (weapon->getInfo()) {
			weapon->setPositionX(weapon->getPositionX() - weapon->speed * ((weapon->getPosX1() - weapon->getPosX2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			weapon->setPositionY(weapon->getPositionY() - weapon->speed * ((weapon->getPosY1() - weapon->getPosY2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0 || weapon->getPositionX() >= Director::getInstance()->getVisibleSize().width || weapon->getPositionX() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1 * m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
	for (auto weapon : m_enemyBoss2Arr) {
		if (weapon->getInfo()) {
			weapon->setPositionY(weapon->getPositionY() - weapon->speed);
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1 * m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
	for (auto weapon : m_enemyBossShipArr) {
		if (weapon->getInfo()) {
			weapon->setPositionX(weapon->getPositionX() - weapon->speed * ((weapon->getPosX1() - weapon->getPosX2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			weapon->setPositionY(weapon->getPositionY() - weapon->speed * ((weapon->getPosY1() - weapon->getPosY2()) / (Point(weapon->getPosX1(), weapon->getPosY1()).getDistance(Point(weapon->getPosX2(), weapon->getPosY2())))));
			if (weapon->getPositionY() >= Director::getInstance()->getVisibleSize().height || weapon->getPositionY() <= 0 || weapon->getPositionX() >= Director::getInstance()->getVisibleSize().width || weapon->getPositionX() <= 0)
			{
				weapon->remove();
				m_phoenix->setScore(m_phoenix->getScore() + 1 * m_phoenix->getDifficulty());
			}
			else if (weapon->isCollideWithShip(m_phoenix)) {
				m_phoenix->hit(weapon->attack);
				weapon->remove();
			}
		}
	}
}

void WeaponControlor::EnemyOneShoot(EnemyOne *ship)
{
	if (ship->getInfo() == false)
	{
		for(auto weapon:m_enemyWeapon1Arr){
			if (weapon->getInfo()==false) {
				weapon->setAngle(ship->getPositionX()+40, ship->getPositionY()-5, m_phoenix->getPositionX()+30, m_phoenix->getPositionY()+28);
				weapon->reset(ship->getPositionX()+40, ship->getPositionY() -5);
				weapon->show();
				return;
			}
		}
	
	}
}

void WeaponControlor::EnemyTwoShoot(EnemyTwo * ship)
{
	if (ship->getInfo() == false)
	{
		for (auto weapon : m_enemyTwoWeaponArr) {
			if (weapon->getInfo() == false) {
				weapon->reset(ship->getPositionX() + 30, ship->getPositionY() - 5);
				weapon->show();
				return;
			}
		}
	}
}

void WeaponControlor::EnemyThreeShoot(EnemyThree * ship)
{

	if (ship->getInfo() == false)
	{
		for (int i = 0; i < 10; i++) {
			for (auto weapon : m_enemyThreeWeaponArr) {
				if (weapon->getInfo() == false) {
					weapon->setAngle(ship->getPositionX() + 75, ship->getPositionY() - 5, ship->getPositionX() + 75+ (100*cos(DEGREE15*(i+1))), ship->getPositionY() - 5 - (100*sin(DEGREE15*(i + 1))));
					weapon->reset(ship->getPositionX() + 75, ship->getPositionY() - 5);
					weapon->show();
					break;
				}
			}
		}
	}
}
void WeaponControlor::EnemyThreeShootPlus(EnemyThree * ship)
{
	if (ship->getInfo() == false)
	{
		for (auto weapon : m_enemyThreeWeaponPlusArr) {
			if (weapon->getInfo() == false) {
				weapon->reset(ship->getPositionX() + 75, ship->getPositionY() - 5);
				weapon->show();
				return;
			}
		}
	}
}

void WeaponControlor::EnemyBossShoot1(Boss * ship)
{

	if (ship->getInfo() == false)
	{
		for (int i = 0; i < 16; i++) {
			for (auto weapon : m_enemyBoss1Arr) {
				if (weapon->getInfo() == false) {
					weapon->setAngle(ship->getPositionX() + 200, ship->getPositionY() + 162, ship->getPositionX() + 200 + (100 * cos(DEGREE10*(i + 1))), ship->getPositionY() + 162 - (100 * sin(DEGREE10*(i + 1))));
					weapon->reset(ship->getPositionX() + 200, ship->getPositionY() + 162);
					weapon->show();
					break;
				}
			}
		}
	}
}

void WeaponControlor::EnemyBossShoot2(Boss * ship)
{
	for (int i = 0; i < 8; i++) {
		for (auto weapon : m_enemyBoss2Arr) {
			if (weapon->getInfo() == false) {
				weapon->reset(ship->getPositionX()+(i * 50), ship->getPositionY()+ (abs(3.5 - i) * 40)-30);
				weapon->show();
				break;
			}
		}
	}
}

void WeaponControlor::EnemyBossShipShoot1(BossShip * ship)
{
	if (ship->getInfo() == false)
	{
		for (auto weapon : m_enemyBossShipArr) {
			if (weapon->getInfo() == false) {
				weapon->setAngle(ship->getPositionX() + 30, ship->getPositionY() - 5, m_phoenix->getPositionX() + 30, m_phoenix->getPositionY() + 28);
				weapon->reset(ship->getPositionX() + 30, ship->getPositionY() - 5);
				weapon->show();
				return;
			}
		}

	}
}

void WeaponControlor::phoenixShoot()
{
	for (int i = 0; i < 2; i++) {
		for (auto weapon : m_PhoenixWeaponArr) {
			if (weapon->getInfo() == false) {
				weapon->reset(m_phoenix->getPositionX() - 30 + (i + 1) * 30, m_phoenix->getPositionY() + 40);
				weapon->type = i + 1;
				weapon->show();
				//CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/shoot.wav", false, 1.0f, 0.0f, 1.0f);
				break;
			}
		}
	}
	if (m_phoenix->getSideWeapon()) {
		for (int i = 0; i < 2; i++) {
			for (auto weapon : m_PhoenixWeaponArr) {
				if (weapon->getInfo() == false) {
					weapon->reset(m_phoenix->getPositionX() - 150 + (i + 1) * 120, m_phoenix->getPositionY() + 40);
					weapon->isSideWeapon = true;
					weapon->type = i + 1;
					weapon->show();
					break;
				}
			}
		}
	}
}


void WeaponControlor::bindPlayer(Phoenix * phoenix)
{
	m_phoenix = phoenix;

	initCreatEnemyOne();
	initCreatEnemyTwo();
	initCreatEnemyThree();
	initCreatEnemyThreePlus();
	initCreatBoss1();
	initCreatBoss2();
	initCreatBossShip();



	this->scheduleUpdate();
}

void WeaponControlor::bindEnemyControlor(EnemyControlor* enemyControlor)
{
	m_enemyColtrolor = enemyControlor;
}

void WeaponControlor::bindBossControlor(BossControlor * bossControlor)
{
	m_bossControlor = bossControlor;
}

void WeaponControlor::initCreatEnemyOne()
{
	EnemyWeapon1*weapon = NULL;
	for (int i = 0; i < MAX_NUM_ENEMYONE; i++) {
		weapon = EnemyWeapon1::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyWeapon1.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 38+(12*(m_phoenix->getDifficulty()-3));
		weapon->speed = 7;
		m_enemyWeapon1Arr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatEnemyTwo()
{
	EnemyTwoWeapon*weapon = NULL;
	for (int i = 0; i < MAX_NUM_ENEMYTWO; i++) {
		weapon = EnemyTwoWeapon::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyTwoWeapon.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 40+(10* (m_phoenix->getDifficulty() - 3));
		weapon->speed = 4;
		m_enemyTwoWeaponArr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatEnemyThree()
{
	EnemyThreeWeapon*weapon = NULL;
	for (int i = 0; i < MAX_NUM_ENEMYTHREE; i++) {
		weapon = EnemyThreeWeapon::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyThreeWeapon.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 37 +(13 * (m_phoenix->getDifficulty() - 3));
		weapon->speed = 3;
		m_enemyThreeWeaponArr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatEnemyThreePlus()
{
	EnemyThreeWeaponPlus*weapon = NULL;
	for (int i = 0; i < MAX_NUM_ENEMYTHREEPLUS; i++) {
		weapon = EnemyThreeWeaponPlus::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyThreeWeaponPlus.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 60 + (10 * (m_phoenix->getDifficulty() - 3));
		weapon->speed = 5+ m_phoenix->getDifficulty();
		m_enemyThreeWeaponPlusArr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatBoss1()
{
	EnemyBossWeapon1*weapon = NULL;
	for (int i = 0; i < MAX_NUM_BOSSONE; i++) {
		weapon = EnemyBossWeapon1::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyBossWeapon1.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 40 + (15 * (m_phoenix->getDifficulty() - 3));
		weapon->speed = 4;
		m_enemyBoss1Arr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatBoss2()
{
	EnemyBossWeapon2*weapon = NULL;
	for (int i = 0; i < MAX_NUM_BOSSONE; i++) {
		weapon = EnemyBossWeapon2::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyBossWeapon2.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 40 + (10 * (m_phoenix->getDifficulty() - 3));
		weapon->speed = 3;
		m_enemyBoss2Arr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatBossShip()
{
	EnemyBossShipWeapon*weapon = NULL;
	for (int i = 0; i < MAX_NUM_BOSSONE; i++) {
		weapon = EnemyBossShipWeapon::create();
		weapon->bindSprite(Sprite::create("./texture/EnemyBossShipWeapon.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 37 + (13 * (m_phoenix->getDifficulty() - 3));
		weapon->speed = 5;
		m_enemyBossShipArr.pushBack(weapon);
	}
}

void WeaponControlor::initCreatPhoenix()
{
	PhoenixWeapon*weapon = NULL;
	for (int i = 0; i < MAX_NUM_PHOENIX; i++) {
		weapon = PhoenixWeapon::create();
		weapon->bindSprite(Sprite::create("./texture/PhoenixWeapon.png"));
		this->addChild(weapon);
		weapon->remove();
		weapon->attack = 10;
		weapon->speed = 24;
		m_PhoenixWeaponArr.pushBack(weapon);
	}
}

Vector<EnemyWeapon1*> WeaponControlor::getEnemyOne()
{
	return m_enemyWeapon1Arr;;
}

Vector<EnemyTwoWeapon*> WeaponControlor::getEnemyTwo()
{
	return m_enemyTwoWeaponArr;
}

Vector<EnemyThreeWeapon*> WeaponControlor::getEnemyThree()
{
	return m_enemyThreeWeaponArr;
}

Vector<EnemyThreeWeaponPlus*> WeaponControlor::getEnemyThreePlus()
{
	return m_enemyThreeWeaponPlusArr;
}

Vector<EnemyBossWeapon1*> WeaponControlor::getEnemyBoss1()
{
	return m_enemyBoss1Arr;
}

Vector<EnemyBossWeapon2*> WeaponControlor::getEnemyBoss2()
{
	return m_enemyBoss2Arr;
}

Vector<EnemyBossShipWeapon*> WeaponControlor::getEnemyBossShip()
{
	return m_enemyBossShipArr;
}
