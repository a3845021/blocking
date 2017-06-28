#pragma once

#include "stdafx.h"

class Logo : public Layer
{
private:
	Sprite* _logo;
	Sprite* _bapdoduk;

private:
	void Update(float dt);

public:

public:
	Logo(){};
	~Logo(){};

	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Logo);
};
