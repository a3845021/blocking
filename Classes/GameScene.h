#pragma once

#include "stdafx.h"
#include "BallClassl.h"
#include "BrickClass.h"
#include "GoalClass.h"

class PauseWindow;
class GameScene : public LayerColor
{
private:
	void onMenu();

public:
    static Scene* createScene();
    virtual bool init();
	CREATE_FUNC(GameScene);

public:
	// Goal
	GoalClass* Goal;

	// Layer
	Layer* ObjectLayer;

	PauseWindow* pause;
	Sprite* Menu;

	// Ball,Brick
	BallClass* Ball;
	Brick* temporarilyBrick;

	// Vector Brick
	Vector<Brick*> BrickVector;
	Vector<Brick*> WallVector;
	// GameStart
	bool GameStart;

	virtual void onEnter();
	virtual void onExit();
public:
	// Update
	void update(float dt);
	void CollideUpdate(float dt);
	bool isToBrickTouch = false;
	bool isTouch;

	// ��ġ�������� true�� ��
	// ����� �ٸ����� ��������
	bool doTouch = false;
	bool ifClear = false;

	// ȭ������� �Ѿ�� ���� ����
	bool first = false;
public:
	//Tutorial ����
	Sprite* Tu;
	int count = 0;
public:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);


	// ����� ��ġ�ϸ� ���� ���ư�
	void touchBrickAndTurn(Vec2 touch);

	Vec2 This_Touch;

	void CollideBrickToBall();
	void BrickAnima(Brick* target);
public:
	void BoundingAni(Brick* target);
	void CrashAni(Brick* target);

	void removeShadow(cocos2d::CCObject *pSender);
	void removeBrickVector(Object* pSender);
	
	void GameOverUpdate(float dt);
};
