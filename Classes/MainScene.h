#pragma once

#include "stdafx.h"

class MainScene : public Layer
{
private:
	Sprite* _bg;
	Sprite* _credit;
	Sprite* _mute;
	Sprite* _stage;
	Sprite* _speaker;
	Sprite* _speaker2;

	bool _Mute;

private:
	void Update(float dt);
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void gotoStage();
	void gotoCredit();

public:

public:
	MainScene(){};
	~MainScene(){};

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	static Scene* createScene();


	CREATE_FUNC(MainScene);
};
