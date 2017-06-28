#pragma once
#include "stdafx.h"

class BallClass : public Node
{
private:
	Sprite* Ball;
	Sprite* BallDirectionCursor;
	Color3B BallColor;
public:
	void	BallInit()
	{
		Ball = Sprite::create("Ball.png");
		BallDirectionCursor = Sprite::create("line.png");
		Ball->setPosition(Vec2(500, 200));
		this->addChild(Ball);
	}

	Sprite* getBall()
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

	void BlockUpdate()
	{
		BallDirectionCursor->setPosition(Vec2(Ball->getPosition().x + 60, Ball->getPosition().y));
		BallDirectionCursor->setScale(0.5);

		MoveBy* move = MoveBy::create(1.0f, Vec2(10, 0));
		FadeOut* visible = FadeOut::create(1.3f);

		BallDirectionCursor->runAction(RepeatForever::create(Sequence::create(move,visible,MoveBy::create(0.3,Vec2(-10,0)),FadeIn::create(0.4),NULL)));
		this->addChild(BallDirectionCursor);
	}

	void BallDirectionCursorRemove()
	{
		BallDirectionCursor->removeAllChildrenWithCleanup(true);
		BallDirectionCursor->setVisible(false);
	}
};