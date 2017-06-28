#pragma once
#include "stdafx.h"

class BallClass : public Node
{
private:
	Sprite* Ball;
	Color3B BallColor;
public:
	void	BallInit()
	{
		Ball = Sprite::create("CloseSelected.png");
		Ball->setPosition(Vec2(500, 200));
		this->addChild(Ball);
	}

	Sprite* getBlock()
	{
		return Ball; 
	}

	void	setBallColor(Color3B color)
	{
		BallColor = color;
		Ball->setColor(BallColor);
	}

	Color3B getBallColor()
	{
		return BallColor;
	}

	void	BlockUpdate(float dt)
	{

	}
};