#pragma once

#include "stdafx.h"

enum class Slide
{
	NORMAL,
	LEFT,
	RIGHT,
};
class Stage : public Layer
{
private:
	Layer* _scene;

	Sprite* _bg;
	Sprite* St1;
	Sprite* St2;
	Sprite* St3;
	Sprite* St4;
	Sprite* St5;
	Sprite* St6;
	Sprite* St7;
	Sprite* St8;
	Sprite* St9;
	Sprite* St10;

	Sprite* lock;

	float clock = 0.f;

	// 스프라이트 터치 유무
	bool TouchInside(Sprite * sprite, Touch * touch);

	float fSceneX = 0.f; // 현재 있는 X씬
	int iSceneNum = 1; // 현재 선택한 씬 넘버

private:
	Vec2 BegineTouch;
	Vec2 EndTouch;

	Slide SlideState;
private:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

	void Update(float dt);

public:
	//Lerp 함수
	template<typename T> 
	T Lerp(T value1, T value2, float amount)
	{
		return T(value1 + ((T)(value2 - value1) * amount));
	}

public:
	Stage(){};
	~Stage(){};

	static Scene* createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(Stage);
};