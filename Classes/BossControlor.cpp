#include "BossControlor.h"
#include"WeaponControlor.h"
#include"Phoenix.h"
#include"SimpleAudioEngine.h"

bool BossControlor::init()
{
	isAttack1Enabled = false;
	isAttackShipEnabled = false;
	initCreat();
	return true;
}

void BossControlor::initCreat()
{
	BossShip* bossShip = NULL;
	for (int i = 0; i < BOSSONE_MAX_NUM; i++) {
		bossShip = BossShip::create();
		bossShip->bindSprite(Sprite::create("./texture/BossShip.png"));
		this->addChild(bossShip);
		bossShip->dead();
		bossShip->setValue(0, 50, 50, 0);
		m_bossShipArr.pushBack(bossShip);
	}
	m_boss = Boss::create();
	m_boss->bindSprite(Sprite::create("./texture/Boss.png"));
	this->addChild(m_boss);
	m_boss->dead();
	m_boss->setValue(0, 2000, 2000, 0);
	hp = Sprite::create("./texture/bossHp.png");
	bossHp = ProgressTimer::create(hp);
	this->addChild(bossHp);
	bossHp->setPosition(m_boss->getPosition() + Point(200, 100));
	bossHp->setType(kCCProgressTimerTypeBar);
	bossHp->setVisible(false);
}

void BossControlor::update(float dt)
{
	for (auto bossShip : m_bossShipArr) {
		if ((bossShip->getHP() == 0 && bossShip->getInfo() == false) || bossShip->isCollideWithShip(m_phoenix) && bossShip->getInfo() == false)
			if (bossShip->getSprite() != NULL) {

				ParticleExplosion* boom = ParticleExplosion::create();
				boom->setAutoRemoveOnFinish(true);
				boom->setEmitterMode(kCCParticleModeRadius);
				boom->setEndRadius(60);
				boom->setEndRadiusVar(20);
				boom->setStartRadius(5);
				boom->setStartRadiusVar(5);
				boom->setStartColorVar(Color4F(0, 0, 0, 0));
				boom->setEndColorVar(Color4F(0, 0, 0, 0));
				boom->setDuration(0.5);
				boom->setLife(0.5);
				boom->setLifeVar(0);
				boom->setTexture(Director::getInstance()->getTextureCache()->addImage("./texture/EnemyExplosion.png"));
				boom->setPosition(Point(bossShip->getPositionX() + 30, bossShip->getPositionY() + 48));
				this->addChild(boom, 5);

				bossShip->dead();
				if (bossShip->isCrashed == true)
					m_phoenix->hit(30);
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/boom.wav", false, 1.0f, 0.0f, 1.0f);
				m_phoenix->giveExp(10);
				m_phoenix->setScore(m_phoenix->getScore() + 20* m_phoenix->getDifficulty());
			}
	}
	if ((m_boss->getHP() == 0 && m_boss->getInfo() == false))
		if (m_boss->getSprite() != NULL) {

			ParticleExplosion* boom = ParticleExplosion::create();
			boom->setAutoRemoveOnFinish(true);
			boom->setEmitterMode(kCCParticleModeRadius);
			boom->setEndRadius(250);
			boom->setEndRadiusVar(20);
			boom->setStartRadius(50);
			boom->setStartRadiusVar(5);
			boom->setStartColorVar(Color4F(0, 0, 0, 0));
			boom->setEndColorVar(Color4F(0, 0, 0, 0));
			boom->setDuration(0.5);
			boom->setLife(1.0);
			boom->setLifeVar(0);
			boom->setTexture(Director::getInstance()->getTextureCache()->addImage("./texture/EnemyExplosion.png"));
			boom->setPosition(Point(m_boss->getPositionX() + 200, m_boss->getPositionY() + 162));
			this->addChild(boom, 5);

			m_boss->dead();
			m_phoenix->setScore(m_phoenix->getScore() + 1000* m_phoenix->getDifficulty());
			m_phoenix->isBossDead = true;
			unscheduleAllSelectors();
			unscheduleUpdate();
			if (m_boss->isCrashed == true)
				m_phoenix->hit(99999);
		}
	if ((m_boss->isCollideWithShip(m_phoenix) && m_boss->getInfo() == false))
		if (m_boss->getSprite() != NULL) {
				m_phoenix->hit(99999);
		}
	if (m_phoenix->getLevel() == 7&&!m_phoenix->isBossDead) {
		if (m_boss->getInfo()) {
			m_boss->randonSet();
			bossHp->setVisible(true);
		}
		this->schedule(schedule_selector(BossControlor::BossShipStartAttack), 5.0f);
		this->schedule(schedule_selector(BossControlor::BossShipAttack), 0.32f);
		this->schedule(schedule_selector(BossControlor::BossStartAttack), 6.0f);
		this->schedule(schedule_selector(BossControlor::BossAttack), 1.0f);
		this->schedule(schedule_selector(BossControlor::BossAttackPlus), 4.5f);
		this->schedule(schedule_selector(BossControlor::creatBossShip), 2.5f);
		m_phoenix->isBossAppear = true;
	}
	m_boss->setPositionX(m_boss->getPositionX() - ((m_boss->getPositionX() + 200 - m_phoenix->getPositionX() - 30) / (abs(m_boss->getPositionX() + 200 - m_phoenix->getPositionX() - 30)) * 1));
	for (auto bossShip : m_bossShipArr) {
		if (bossShip->getInfo() == false) {
			bossShip->setPositionX(bossShip->getPositionX() - ((m_boss->getPositionX() + 200 - m_phoenix->getPositionX() - 30) / (abs(m_boss->getPositionX() + 200 - m_phoenix->getPositionX() - 30)) * 1));
			if ((bossShip->getPosition()+Point(30,48)).getDistance(m_boss->getPosition()+Point(200,162)) >= 250) {
				bossShip->endMoving();
			}
			if (bossShip->getMoving()) {
				bossShip->setPositionX(bossShip->getPositionX() - 2 * ((m_boss->getPositionX()+200 - bossShip->getPositionX()-30) / ((m_boss->getPosition() + Point(200, 162)).getDistance(bossShip->getPosition() + Point(30, 48)))));
				bossShip->setPositionY(bossShip->getPositionY() - 2 * ((m_boss->getPositionY()+162 - bossShip->getPositionY()-48) / ((m_boss->getPosition() + Point(200, 162)).getDistance(bossShip->getPosition() + Point(30, 48)))));
			}
			bossShip->setPositionX(bossShip->getPositionX() - 1 * ((m_boss->getPositionY() + 162 - bossShip->getPositionY() - 48) / ((m_boss->getPosition() + Point(200, 162)).getDistance(bossShip->getPosition() + Point(30, 48)))));
			bossShip->setPositionY(bossShip->getPositionY() + 1 * ((m_boss->getPositionX() + 200 - bossShip->getPositionX() - 30) / ((m_boss->getPosition() + Point(200, 162)).getDistance(bossShip->getPosition() + Point(30, 48)))));
		}
	}
	bossHp->setPercentage(((float)m_boss->getHP() / m_boss->getMaxHP())*100);
	bossHp->setPosition(m_boss->getPosition() + Point(200, 310));
}


void BossControlor::creatBossShip(float dt)
{
	BossShip* bossShip = NULL;
	for (auto bossShip : m_bossShipArr)
	{
		if (bossShip->getInfo()&&!m_boss->getInfo()) {
			bossShip->Set(m_boss);
			return;
		}
	}
}


void BossControlor::BossShipAttack(float dt)
{
	if (isAttackShipEnabled == true) {
		for (auto bossShip : m_bossShipArr) {

			if (bossShip->getPositionX() <= -60 || bossShip->getPositionX() >= Director::getInstance()->getVisibleSize().width + 10 ||
				bossShip->getPositionY() <= -66 || bossShip->getPositionY() >= Director::getInstance()->getVisibleSize().height + 300)
			{
				bossShip->dead();
			}
			if (bossShip->getInfo() == false) {
				m_weaponControlor->EnemyBossShipShoot1(bossShip);
			}
		}
	}
}

void BossControlor::BossAttack(float dt)
{
	if (m_boss->getInfo() == false&&isAttack1Enabled) {
		m_weaponControlor->EnemyBossShoot1(m_boss);
	}
}

void BossControlor::BossAttackPlus(float dt)
{
	if (m_boss->getInfo() == false) {
		m_weaponControlor->EnemyBossShoot2(m_boss);
	}
}

void BossControlor::BossShipStartAttack(float dt)
{
	isAttackShipEnabled = true;
	scheduleOnce(schedule_selector(BossControlor::BossShipStopAttack), 0.8f);
}

void BossControlor::BossStartAttack(float dt)
{
	isAttack1Enabled = true;
	scheduleOnce(schedule_selector(BossControlor::BossStopAttack), 1.0f);
}

void BossControlor::BossShipStopAttack(float dt)
{
	isAttackShipEnabled = false;
}

void BossControlor::BossStopAttack(float dt)
{
	isAttack1Enabled = false;
}

void BossControlor::bindPlayer(Phoenix * phoenix)
{
	m_phoenix = phoenix;
	

	
	this->scheduleUpdate();
}

void BossControlor::bindWeaponControlor(WeaponControlor * weaponControlor)
{
	m_weaponControlor = weaponControlor;
}

Vector<BossShip*> BossControlor::getBossShipArr()
{
	return m_bossShipArr;
}

Boss * BossControlor::getBoss()
{
	return m_boss;
}
