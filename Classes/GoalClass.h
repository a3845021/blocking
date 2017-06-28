#pragma once

#include "stdafx.h"
#include "GoalClass.h"

class GoalClass : public Node
{
private:
	Sprite* Goal;
	Color3B color;
public:
	Sprite* getGoal()
	{
		return Goal;
	}

	Color3B getGoalColor()
	{
		return color;
	}

	bool IfGoal(Sprite* sprite, Sprite* sprite2)
	{
		if (sprite->getBoundingBox().containsPoint(sprite2->getPosition()))
		{
			return true;
		}
	}

	void setSpinGoal(float speed, float angle)
	{
		auto action = RotateBy::create(speed, angle);
		Goal->runAction(RepeatForever::create(action));
	}

	void setGoalColor(int color)
	{
		if (color == BLUE)
		{
			Goal = Sprite::create("BBH.png");
			this->color = Color3B(255, 156, 0);
		}
		else if (color == YELLOW)
		{
			Goal = Sprite::create("YBH.png");
			this->color = Color3B(0, 99,255);
		}
	}

	void setGoalPosition(float x, float y)
	{
		Goal->setPosition(x, y);
	}

	void setGoalPosition(Point point)
	{
		Goal->setPosition(point);
	}

};