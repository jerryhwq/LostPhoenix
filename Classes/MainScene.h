#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos2d.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
#include "Phoenix.h"
#include "WeaponControlor.h"
#include "EnemyControlor.h"
#include "BonusControlor.h"
#include "BossControlor.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;

class MainScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MainScene);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    void onExitClick(Ref*, cocos2d::ui::Widget::TouchEventType type);
	void menuCallRestart(cocos2d::Ref* pSender);

	void phoenixBomb();

	void initBG();

	virtual void update(float delta);
	void continueAttact(float dt);
	void gameOver(float dt);
	void gameWin(float dt);
private:

	Text* score;
	Text*level;
	ImageView*sideWeapon;
	ImageView*bomb;
	LoadingBar* hp;
	LoadingBar* exp;

	Sprite* m_BG1;
	Sprite* m_BG2;


	EnemyControlor *enemyMgr;
	WeaponControlor* weaponMgr;
	BonusControlor*bonusMgr;
	BossControlor*bossMgr;
	Phoenix* m_phoenix;
	bool isWpressed, isApressed, isSpressed, isDpressed,isSpacePressed;
};

#endif // __MAINSCENE_SCENE_H__

