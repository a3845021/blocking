#pragma once

#include "stdafx.h"

class Clear : public Layer
{
private:
	Sprite* _bg;
	Sprite* _retry;
	Sprite* _home;
	Sprite* _next;

private:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

public:

public:
	Clear(){};
	~Clear(){};

	static Scene* createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(Clear);
};