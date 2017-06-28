#pragma once

#include "stdafx.h"

enum MENU
{
	CONTINUE,
	RETRY,
	HOME,
};

class PauseWindow : public Layer
{
private:
	Sprite* _bg;
	Sprite* _resum;
	Sprite* _retry;
	Sprite* _home;
	Sprite* _sound;
	Sprite* _soundSpace;
	Scene *scene;
	EventListenerTouchOneByOne* t_touch;
	bool _playSound;

private:
public:
	PauseWindow()
	{};
	~PauseWindow()
	{};

	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	void doAni1();
	void doAni2();
	void pauseGame();
	void resumGame();

	bool setTouchOnMenu(Touch* touch);

	CREATE_FUNC(PauseWindow);
};