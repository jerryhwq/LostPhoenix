#include "EnemyControlor.h"
#include "WeaponControlor.h"
#include "Phoenix.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"
#include "scripting/deprecated/CCDeprecated.h"

bool EnemyControlor::init()
{
	initCreat();
	return true;
}


void EnemyControlor::initCreat()
{
	EnemyOne* enemyone = NULL;
	for (int i = 0; i < ENEMYONE_MAX_NUM; i++) {
		enemyone = EnemyOne::create();
		enemyone->bindSprite(Sprite::create("./texture/EnemyOne.png"));
		this->addChild(enemyone);
		enemyone->dead();
		enemyone->setValue(0, 50, 50, 0);
		m_ememyOneArr.pushBack(enemyone);
	}
	EnemyTwo* enemytwo = NULL;
	for (int i = 0; i < ENEMYTWO_MAX_NUM; i++) {
		enemytwo = EnemyTwo::create();
		enemytwo->bindSprite(Sprite::create("./texture/EnemyTwo.png"));
		this->addChild(enemytwo);
		enemytwo->dead();
		enemytwo->setValue(0, 20, 20, 0);
		m_ememyTwoArr.pushBack(enemytwo);
	}
	EnemyThree* enemythree = NULL;
	for (int i = 0; i < ENEMYTHREE_MAX_NUM; i++) {
		enemythree = EnemyThree::create();
		enemythree->bindSprite(Sprite::create("./texture/EnemyThree.png"));
		this->addChild(enemythree);
		enemythree->dead();
		enemythree->setValue(0, 200, 200, 0);
		m_ememyThreeArr.pushBack(enemythree);
	}
}

void EnemyControlor::update(float dt)
{
	for (auto enemyone : m_ememyOneArr) {
		if ((enemyone->getHP() == 0 && enemyone->getInfo() == false)||enemyone->isCollideWithShip(m_phoenix) && enemyone->getInfo() == false)
			if (enemyone->getSprite() != NULL) {

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
				boom->setPosition(Point(enemyone->getPositionX()+40, enemyone->getPositionY()+26));
				this->addChild(boom, 5);

				enemyone->dead();
				if (enemyone->isCrashed == true)
					m_phoenix->hit(30);
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/boom.wav", false, 1.0f, 0.0f, 1.0f);
				m_phoenix->giveExp(10);
				m_phoenix->setScore(m_phoenix->getScore() + 20* m_phoenix->getDifficulty());
			}
	}
	for (auto enemytwo : m_ememyTwoArr) {
		enemytwo->setPositionY(enemytwo->getPositionY() - 1);
		if ((enemytwo->getHP() == 0 && enemytwo->getInfo() == false) || enemytwo->isCollideWithShip(m_phoenix) && enemytwo->getInfo() == false)
			if (enemytwo->getSprite() != NULL) {

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
				boom->setPosition(Point(enemytwo->getPositionX() + 30, enemytwo->getPositionY() + 30));
				this->addChild(boom, 5);

				enemytwo->dead();
				if (enemytwo->isCrashed == true)
					m_phoenix->hit(30);
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/boom.wav", false, 1.0f, 0.0f, 1.0f);
				m_phoenix->giveExp(5);
				m_phoenix->setScore(m_phoenix->getScore() + 10* m_phoenix->getDifficulty());
			}
	}
	for (auto enemythree : m_ememyThreeArr) {
		//enemythree->setPositionX(enemythree->getPositionX() - (5*(CCRANDOM_0_1()-0.5)));
		if ((enemythree->getHP() == 0 && enemythree->getInfo() == false) || enemythree->isCollideWithShip(m_phoenix) && enemythree->getInfo() == false)
			if (enemythree->getSprite() != NULL) {

				ParticleExplosion* boom = ParticleExplosion::create();
				boom->setAutoRemoveOnFinish(true);
				boom->setEmitterMode(kCCParticleModeRadius);
				boom->setEndRadius(80);
				boom->setEndRadiusVar(20);
				boom->setStartRadius(5);
				boom->setStartRadiusVar(5);
				boom->setStartColorVar(Color4F(0, 0, 0, 0));
				boom->setEndColorVar(Color4F(0, 0, 0, 0));
				boom->setDuration(0.5);
				boom->setLife(0.5);
				boom->setLifeVar(0);
				boom->setTexture(Director::getInstance()->getTextureCache()->addImage("./texture/EnemyExplosion.png"));
				boom->setPosition(Point(enemythree->getPositionX() + 75, enemythree->getPositionY() + 80));
				this->addChild(boom, 5);

				enemythree->dead();
				if (enemythree->isCrashed == true)
					m_phoenix->hit(120);
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/boom.wav", false, 1.0f, 0.0f, 1.0f);
				m_phoenix->giveExp(50);
				m_phoenix->setScore(m_phoenix->getScore() + 75* m_phoenix->getDifficulty());
			}
	}
	if (m_phoenix->isBossAppear) {
		for (auto enemythree : m_ememyThreeArr) {
			if (enemythree->getSprite() != NULL) {
				enemythree->dead();
			}
		}
		for (auto enemytwo : m_ememyTwoArr) {
			if (enemytwo->getSprite() != NULL) {
				enemytwo->dead();
			}
		}
		for (auto enemyone : m_ememyOneArr) {
			if (enemyone->getSprite() != NULL) {
				enemyone->dead();
			}
		}
        unscheduleAllCallbacks();
		unscheduleUpdate();
	}
}

void EnemyControlor::creatEnemyOne(float dt)
{
	EnemyOne* enemyone = NULL;
	for (auto enemyone:m_ememyOneArr)
	{
		if (enemyone->getInfo()) {
			enemyone->randonSet();
			return;
		}
	}
	
}

void EnemyControlor::creatEnemyTwo(float dt)
{
	EnemyTwo* enemytwo = NULL;
	for (auto enemytwo : m_ememyTwoArr)
	{
		if (enemytwo->getInfo()) {
			enemytwo->randonSet();
			return;
		}
	}
}

void EnemyControlor::creatEnemyThree(float dt)
{
	EnemyThree* enemythree = NULL;
	for (auto enemythree : m_ememyThreeArr)
	{
		if (enemythree->getInfo()) {
			enemythree->randonSet();
			MoveBy*move = MoveBy::create(6.0f, Point(0, -360));
			enemythree->runAction(move);
			return;
		}
	}
}

void EnemyControlor::EnemyOneAttackMove(float dt)
{
	for (auto enemyone : m_ememyOneArr) {

		if (enemyone->getPositionX() <= -60 || enemyone->getPositionX() >= Director::getInstance()->getVisibleSize().width +10||
			enemyone->getPositionY() <= -66 || enemyone->getPositionY() >= Director::getInstance()->getVisibleSize().height + 4 )
		{
			enemyone->dead();
		}
		if(enemyone->getInfo() == false){
			m_weaponControlor->EnemyOneShoot(enemyone);
			ccBezierConfig bezier;
			bezier.controlPoint_1 = ccp(30 * (CCRANDOM_0_1()-0.5), 20 * (CCRANDOM_0_1() - 0.5));
			bezier.controlPoint_2 = ccp(40 * (CCRANDOM_0_1() - 0.5), 30 * (CCRANDOM_0_1() - 0.5));
			bezier.endPosition = ccp(100 * (CCRANDOM_0_1() - 0.5), 50 * (CCRANDOM_0_1() - 0.7));
			BezierBy*move = BezierBy::create(0.8, bezier);
			enemyone->runAction(move);
		}

	}
}

void EnemyControlor::EnemyTwoAttackMove(float dt)
{
	for (auto enemytwo : m_ememyTwoArr) {

		if (enemytwo->getPositionX() <= -60 || enemytwo->getPositionX() >= Director::getInstance()->getVisibleSize().width + 10 ||
			enemytwo->getPositionY() <= -66 || enemytwo->getPositionY() >= Director::getInstance()->getVisibleSize().height + 4)
		{
			enemytwo->dead();
		}
		if (enemytwo->getInfo() == false) {
			m_weaponControlor->EnemyTwoShoot(enemytwo);
		}
	}
}

void EnemyControlor::EnemyThreeAttackMove(float dt)
{
	for (auto enemythree : m_ememyThreeArr) {

		if (enemythree->getPositionX() <= -60 || enemythree->getPositionX() >= Director::getInstance()->getVisibleSize().width + 10 ||
			enemythree->getPositionY() <= -66 || enemythree->getPositionY() >= Director::getInstance()->getVisibleSize().height + 500)
		{
			enemythree->dead();
		}
		if (enemythree->getInfo() == false) {
			m_weaponControlor->EnemyThreeShoot(enemythree);
		}
	}
}

void EnemyControlor::EnemyThreeAttackMovePlus(float dt)
{
	for (auto enemythree : m_ememyThreeArr) {

		if (enemythree->getPositionX() <= -60 || enemythree->getPositionX() >= Director::getInstance()->getVisibleSize().width + 10 ||
			enemythree->getPositionY() <= -66 || enemythree->getPositionY() >= Director::getInstance()->getVisibleSize().height + 500)
		{
			enemythree->dead();
		}
		if (enemythree->getInfo() == false) {
			m_weaponControlor->EnemyThreeShootPlus(enemythree);
		}
	}
}

void EnemyControlor::bindPlayer(Phoenix * phoenix)
{
	m_phoenix = phoenix;


	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::creatEnemyOne), (float)(7 - (m_phoenix->getDifficulty()/2)) - 0.58*m_phoenix->getLevel());
	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::EnemyOneAttackMove), 1.0-(0.12*m_phoenix->getDifficulty()));

	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::creatEnemyTwo), 4.0 - (float)(m_phoenix->getDifficulty() / 4) - 0.35*m_phoenix->getLevel());
	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::EnemyTwoAttackMove), 1.5f);

	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::creatEnemyThree), 35.0 - (3 * m_phoenix->getDifficulty())-2*m_phoenix->getLevel());
	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::EnemyThreeAttackMove), (10.0-m_phoenix->getDifficulty()*1.52));
	this->schedule(CC_SCHEDULE_SELECTOR(EnemyControlor::EnemyThreeAttackMovePlus), (6.0 - m_phoenix->getDifficulty()*0.55));

	this->scheduleUpdate();

}

void EnemyControlor::bindWeaponControlor(WeaponControlor * weaponControlor)
{
	m_weaponControlor = weaponControlor;
}

Vector<EnemyOne*> EnemyControlor::getEnemyOneArr()
{
	return m_ememyOneArr;
}

Vector<EnemyTwo*> EnemyControlor::getEnemyTwoArr()
{
	return m_ememyTwoArr;
}

Vector<EnemyThree*> EnemyControlor::getEnemyThreeArr()
{
	return m_ememyThreeArr;
}
