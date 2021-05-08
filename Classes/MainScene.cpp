#include "MainScene.h"
#include "extensions/cocos-ext.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"
#include "scripting/deprecated/CCDeprecated.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool MainScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("./sound/bgm.mp3",true);
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("./texture/Phoenix_1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI, 1);

	Button* exitButton = (Button*)Helper::seekWidgetByName(UI, "exitButton");
	score = (Text*)Helper::seekWidgetByName(UI, "Score");
	level = (Text*)Helper::seekWidgetByName(UI, "Level");
	sideWeapon = (ImageView*)::Helper::seekWidgetByName(UI, "sideWeapon");
	bomb = (ImageView*)Helper::seekWidgetByName(UI, "bomb");
	hp = (LoadingBar*)Helper::seekWidgetByName(UI, "HP_bar");
	exp = (LoadingBar*)Helper::seekWidgetByName(UI, "exp_bar");

	exitButton->addTouchEventListener(CC_CALLBACK_2(MainScene::onExitClick, this));

	initBG();
	//creat phoenix
	m_phoenix = Phoenix::create();
	m_phoenix->bindSprite(Sprite::create("./texture/Phoenix.png"));
	m_phoenix->setPosition(Point(visibleSize.width / 2-30, 0));
//	extern int difficulty;
	m_phoenix->setDifficulty(1);
	this->addChild(m_phoenix, 3);
	m_phoenix->setValue(0, 50, 50, 8);

	isWpressed = false; isApressed = false; isSpressed = false; isDpressed = false; isSpacePressed = false;

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(MainScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	weaponMgr = WeaponControlor::create();
	this->addChild(weaponMgr, 4);
	weaponMgr->bindPlayer(m_phoenix);

	enemyMgr = EnemyControlor::create();
	this->addChild(enemyMgr, 4);
	enemyMgr->bindPlayer(m_phoenix);

	bonusMgr = BonusControlor::create();
	this->addChild(bonusMgr, 4);
	bonusMgr->bindPlayer(m_phoenix);

	bossMgr = BossControlor::create();
	this->addChild(bossMgr, 4);
	bossMgr->bindPlayer(m_phoenix);

	bossMgr->bindWeaponControlor(weaponMgr);
	enemyMgr->bindWeaponControlor(weaponMgr);
	weaponMgr->bindEnemyControlor(enemyMgr);
	weaponMgr->bindBossControlor(bossMgr);
	
	this->scheduleUpdate();
	this->schedule(CC_SCHEDULE_SELECTOR(MainScene::continueAttact), 0.25f);

	return true;
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{
	
	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
		isSpacePressed = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		isWpressed = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		isDpressed = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		isSpressed = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		isApressed = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_X:
		phoenixBomb();
		break;
	default:
		break;
	}
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{

	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
		isSpacePressed = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		isWpressed = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		isDpressed = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		isSpressed = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		isApressed = false;
		break;
	default:
		break;
	}
}

void MainScene::onExitClick(Ref *, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
    case cocos2d::ui::Widget::TouchEventType::BEGAN:
		break;
    case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
    case cocos2d::ui::Widget::TouchEventType::ENDED:
		Director::getInstance()->end();
		break;
	default:
		break;
	}
}

void MainScene::menuCallRestart(cocos2d::Ref * pSender)
{
	auto scene = MainScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

void MainScene::phoenixBomb()
{
	if (m_phoenix->getBomb()&&m_phoenix->getInfo()==false) {
		m_phoenix->setBomb(false);
		for (auto weapon : weaponMgr->getEnemyOne())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		for (auto enemyone : enemyMgr->getEnemyOneArr()) {
			if (enemyone->getInfo() == false) {
				if (enemyone->getSprite() != NULL) {
					enemyone->hit(100);
				}
			}
		}
		for (auto weapon : weaponMgr->getEnemyTwo())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		for (auto enemytwo : enemyMgr->getEnemyTwoArr()) {
			if (enemytwo->getInfo() == false) {
				if (enemytwo->getSprite() != NULL) {
					enemytwo->hit(100);
				}
			}
		}
		for (auto weapon : weaponMgr->getEnemyThree())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		for (auto weapon : weaponMgr->getEnemyThreePlus())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		for (auto enemythree : enemyMgr->getEnemyThreeArr()) {
			if (enemythree->getInfo() == false) {
				if (enemythree->getSprite() != NULL) {
					enemythree->hit(100);
				}
			}
		}
		for (auto bossShip : bossMgr->getBossShipArr()) {
			if (bossShip->getInfo() == false) {
				if (bossShip->getSprite() != NULL) {
					bossShip->hit(100);
				}
			}
		}
		for (auto weapon : weaponMgr->getEnemyBoss1())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		for (auto weapon : weaponMgr->getEnemyBoss2())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		for (auto weapon : weaponMgr->getEnemyBossShip())
		{
			if (weapon->getInfo()) {
				weapon->remove();
			}
		}
		if (bossMgr->getBoss()->getInfo() == false) {
			if (bossMgr->getBoss()->getSprite() != NULL) {
				bossMgr->getBoss()->hit(100);
			}
		}
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/bomb.wav", false, 1.0f, 0.0f, 1.0f);
		ParticleExplosion* bomb = ParticleExplosion::create();
		bomb->setAutoRemoveOnFinish(true);
		bomb->setEmitterMode(kCCParticleModeRadius);
		bomb->setEndRadius(1000);
		bomb->setEndRadiusVar(200);
		bomb->setStartRadius(60);
		bomb->setStartRadiusVar(10);
		bomb->setStartColor(Color4F(255, 255, 255 ,255));
		bomb->setStartColorVar(Color4F(0, 0, 0, 0));
		bomb->setEndColor(Color4F(255, 255, 255, 255));
		bomb->setEndColorVar(Color4F(0, 0, 0, 0));
		bomb->setDuration(0.5);
		bomb->setLife(0.5);
		bomb->setLifeVar(0);
		bomb->setTexture(Director::getInstance()->getTextureCache()->addImage("./texture/bomb.png"));
		bomb->setPosition(Point(m_phoenix->getPositionX() + 30, m_phoenix->getPositionY() + 28
			
			
			
			));
		this->addChild(bomb, 6);
	}
}

void MainScene::initBG()
{
	m_BG1 = Sprite::create("./texture/bg1.png");
	m_BG1->setPosition(Point(512,0));
	this->addChild(m_BG1, 0);

	m_BG2= Sprite::create("./texture/bg2.png");
	m_BG2->setPosition(Point(512, 1024));
	this->addChild(m_BG2, 0);

}

void MainScene::update(float delta) {
	if (isWpressed&&m_phoenix->getPositionY() < Director::getInstance()->getVisibleSize().height - 60 && m_phoenix->getPositionY() >= -10 && m_phoenix->getInfo() == false)
		m_phoenix->setPositionY(m_phoenix->getPositionY() + 6);
	if (isSpressed&&m_phoenix->getPositionY() < Director::getInstance()->getVisibleSize().height - 50 && m_phoenix->getPositionY() >= 0 && m_phoenix->getInfo() == false)
		m_phoenix->setPositionY(m_phoenix->getPositionY() - 6);
	if (isApressed&&m_phoenix->getPositionX() < Director::getInstance()->getVisibleSize().width - 50 && m_phoenix->getPositionX() >= 0 && m_phoenix->getInfo() == false)
		m_phoenix->setPositionX(m_phoenix->getPositionX() - 6);
	if (isDpressed&&m_phoenix->getPositionX() < Director::getInstance()->getVisibleSize().width - 60 && m_phoenix->getPositionX() >= -10 && m_phoenix->getInfo() == false)
		m_phoenix->setPositionX(m_phoenix->getPositionX() + 6);
	if (m_phoenix->getHP()==0)
	{
		ParticleExplosion* boom = ParticleExplosion::create();
		boom->setAutoRemoveOnFinish(true);
		boom->setEmitterMode(kCCParticleModeRadius);
		boom->setEndRadius(40);
		boom->setEndRadiusVar(20);
		boom->setStartRadius(5);
		boom->setStartRadiusVar(5);
		boom->setStartColor(Color4F(255, 255, 255, 255));
		boom->setStartColorVar(Color4F(0, 0, 0, 0));
		boom->setEndColor(Color4F(255, 255, 255, 255));
		boom->setEndColorVar(Color4F(0, 0, 0, 0));
		boom->setDuration(0.5);
		boom->setLife(0.8);
		boom->setLifeVar(0);
		boom->setTexture(Director::getInstance()->getTextureCache()->addImage("./texture/bomb.png"));
		boom->setPosition(Point(m_phoenix->getPositionX() + 30, m_phoenix->getPositionY() + 30));
		this->addChild(boom, 5);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("./sound/PhoenixDead.wav", false, 1.0f, 0.0f, 1.0f);

		m_phoenix->dead(); 
		this->unscheduleUpdate();
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(MainScene::gameOver), 1.5f);
	}
	hp->setPercent(((float)(m_phoenix->getMaxHP() - m_phoenix->getHP()) / m_phoenix->getMaxHP()) * 100);
	exp->setPercent(100*((float)((50 + 50 * m_phoenix->getLevel()) - m_phoenix->getExp()) / (50 + 50 * m_phoenix->getLevel())));
	level->setString(Value(m_phoenix->getLevel()).asString());
	score->setString(Value(m_phoenix->getScore()).asString());
	if(m_phoenix->getSideWeapon())
		sideWeapon->setVisible(true);
	else
		sideWeapon->setVisible(false);
	if (m_phoenix->getBomb())
		bomb->setVisible(true);
	else
		bomb->setVisible(false);
	m_BG1->setPositionY(m_BG1->getPositionY() - 2);
	m_BG2->setPositionY(m_BG2->getPositionY() - 2);
	if(m_BG1->getPositionY()<-m_BG1->getContentSize().height/2)
		m_BG1->setPositionY(m_BG1->getContentSize().height / 2*3);
	if (m_BG2->getPositionY()<-m_BG2->getContentSize().height / 2)
		m_BG2->setPositionY(m_BG2->getContentSize().height / 2 * 3);
	if (m_phoenix->isBossDead) {
		this->unscheduleUpdate();
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(MainScene::gameWin), 1.5f);
	}
}

void MainScene::continueAttact(float dt)
{
	if (isSpacePressed&&m_phoenix->getInfo()==false)
		weaponMgr->phoenixShoot();
}

void MainScene::gameOver(float dt)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	Sprite*overItem = Sprite::create("./texture/OverItem.png");
	overItem->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(overItem, 7);

	auto restartItem = MenuItemImage::create(
		"./texture/restart.png",
		"./texture/restart.png",
		CC_CALLBACK_1(MainScene::menuCallRestart, this));
	restartItem->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2-200));
	auto menu = Menu::create(restartItem, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu, 7);

	auto score = Label::createWithSystemFont("Final Score:", "Arial", 30);
	score->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2-30, Director::getInstance()->getVisibleSize().height / 2 - 125));
	this->addChild(score, 7);

	auto score2 = Label::createWithSystemFont(Value(m_phoenix->getScore()).asString(), "Arial", 30);
	score2->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2 +100, Director::getInstance()->getVisibleSize().height / 2 - 125));
	this->addChild(score2, 7);

}

void MainScene::gameWin(float dt)
{
	Sprite*overItem = Sprite::create("./texture/winItem.png");
	overItem->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(overItem, 7);

	auto restartItem = MenuItemImage::create(
		"./texture/restart.png",
		"./texture/restart.png",
		CC_CALLBACK_1(MainScene::menuCallRestart, this));
	restartItem->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2 - 200));
	auto menu = Menu::create(restartItem, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu, 7);

	auto score = Label::createWithSystemFont("Final Score:", "Arial", 30);
	score->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2 - 30, Director::getInstance()->getVisibleSize().height / 2 - 125));
	this->addChild(score, 7);

	auto score2 = Label::createWithSystemFont(Value(m_phoenix->getScore()).asString(), "Arial", 30);
	score2->setPosition(Point(Director::getInstance()->getVisibleSize().width / 2 + 80, Director::getInstance()->getVisibleSize().height / 2 - 125));
	this->addChild(score2, 7);
}
