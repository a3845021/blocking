#pragma once

#include "stdafx.h"

class Credit : public Layer
{
private:
	Sprite*sprite;
	Sprite* _back;

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);

public:
	static Scene* createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	void addChile(Node*child, int z, const Point&parallaxRatio, const Point&positionOffset);

	//!< ¾ÀÀ» µî·Ï ½ÃÅ´
	CREATE_FUNC(Credit);
};