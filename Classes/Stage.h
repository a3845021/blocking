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

	// ��������Ʈ ��ġ ����
	bool TouchInside(Sprite * sprite, Touch * touch);

	float fSceneX = 0.f; // ���� �ִ� X��
	int iSceneNum = 1; // ���� ������ �� �ѹ�

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
	//Lerp �Լ�
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