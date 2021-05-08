#include "BonusControlor.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"
#include "Phoenix.h"

bool BonusControlor::init()
{

	initCreat();
	return true;
}

void BonusControlor::initCreat()
{
	Bonus* bonus = NULL;
	for (int i = 0; i < 4; i++) {
		bonus = Bonus::create();
		bonus->setType(i + 1);
		switch (bonus->getType())
		{
		case BONUS_SIDEWEAPOM:
			bonus->bindSprite(Sprite::create("./texture/BonusSideWeapon.png"));
			break;
		case BONUS_LIFE:
			bonus->bindSprite(Sprite::create("./texture/BonusLife.png"));
			break;
		case BONUS_BOMB:
			bonus->bindSprite(Sprite::create("./texture/BonusBomb.png"));
			break;
		case BONUS_SCORE:
			bonus->bindSprite(Sprite::create("./texture/bonusScore.png"));
			break;
		default:
			break;
		}
		this->addChild(bonus);
		bonus->remove();
		m_bonusOneArr.pushBack(bonus);
	}
}

void BonusControlor::update(float dt)
{
	for (auto bonus : m_bonusOneArr) {
		if (bonus->getInfo()) {
			bonus->setPositionY(bonus->getPositionY()-1);
			if (bonus->getPositionY() <=-30)
			{
				bonus->remove();
			}
			else if (bonus->isCollideWithShip(m_phoenix)) {
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/getBonus.wav", false, 1.0f, 0.0f, 1.0f);
				bonus->giveBonus(m_phoenix);
				if (bonus->getType() == BONUS_SIDEWEAPOM)
					this->scheduleOnce(CC_SCHEDULE_SELECTOR(BonusControlor::sideWeaponOff), 60.0f);
				bonus->remove();
			}
		}
	}
}

void BonusControlor::creatBonus(float dt)
{
	if (m_phoenix->getSideWeapon() == false && m_phoenix->getBomb() == false) {
		int ran = CCRANDOM_0_1() * 100;
		if (ran < 25) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_SIDEWEAPOM&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran >= 25 && ran < 50) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_BOMB&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran >= 50 && ran < 75) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_LIFE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran >= 75) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_SCORE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
	}
	else if (m_phoenix->getBomb() && m_phoenix->getSideWeapon() == false)
	{
		int ran = CCRANDOM_0_1() * 100;
		if (ran < 33) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_SIDEWEAPOM&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran >= 33 && ran < 66) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_LIFE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran >= 66) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_SCORE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
	}
	else if (m_phoenix->getBomb() == false && m_phoenix->getSideWeapon()) {
		int ran = CCRANDOM_0_1() * 100;
		if (ran >= 25 && ran < 50) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_BOMB&&!bonus->getInfo()) {
				bonus->randomSet();
				break;
				}
			}
		}
		else if (ran >= 33 && ran < 66) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_LIFE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran >= 66) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_SCORE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
	}
	else {
		int ran = CCRANDOM_0_1() * 100;
		if (ran >= 50 ) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_LIFE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
		else if (ran < 50) {
			for (auto bonus : m_bonusOneArr) {
				if (bonus->getType() == BONUS_SCORE&&!bonus->getInfo()) {
					bonus->randomSet();
					break;
				}
			}
		}
	}


	/*for (auto bonus : m_bonusOneArr) {
		
		if (!bonus->getInfo()) {
			if (bonus->getType() == BONUS_SIDEWEAPOM&&m_phoenix->getSideWeapon() == false ){
				bonus->randomSet();
				break;
			}
			else if (bonus->getType() == BONUS_BOMB&&m_phoenix->getBomb() == false ){
				bonus->randomSet();
				break;
			}
			else if (bonus->getType() == BONUS_LIFE){
				bonus->randomSet();
				break;
			}
		}
	}*/
}

void BonusControlor::sideWeaponOff(float dt)
{
	m_phoenix->setSideWeapon(false);
}

void BonusControlor::bindPlayer(Phoenix * phoenix)
{
	m_phoenix = phoenix;


	this->schedule(CC_SCHEDULE_SELECTOR(BonusControlor::creatBonus), (float)(30 + m_phoenix->getDifficulty()));
	this->scheduleUpdate();

}
