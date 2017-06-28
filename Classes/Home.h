#pragma once
#include "stdafx.h"

class Home : public Layer
{
private:
	Sprite* word;
	Sprite* main;

private:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
public:

	static Scene* createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	void onMenu(Ref* sender);

	void DrawMain();

	void DrawWord();

	void Update(float dt);

	CREATE_FUNC(Home);
};
