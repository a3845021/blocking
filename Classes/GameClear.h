#pragma once

#include "stdafx.h"

class GameClear : public Layer
{
private:
	Sprite* _bg;
	Sprite* _retry;
	Sprite* _home;
	Sprite* _next;

public:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

public:
	GameClear(){};
	~GameClear(){};

	static Scene* createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	void NextStage(Ref* sender);
	CREATE_FUNC(GameClear);
};