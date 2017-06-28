#pragma once
#include "stdafx.h"

class Brick : public Node
{
private:
	Sprite* brick;
	Color3B brickColor;
	bool	selected;
protected:

public:
	bool	enable;
	int		damage;
	bool	CollideBlock = false;
	void InitBrick(float x,float y,int damage)
	{
		brick = Sprite::create();
		brick->setPosition(Vec2(x, y));
		this->damage = damage;
		this->enable = true;

		this->addChild(brick);
	}

	void InitBrick(Vec2 xy, int damage)
	{
		brick = Sprite::create();
		brick->setPosition(xy);
		this->damage = damage;

		this->addChild(brick);
	}

	Sprite* getBrick()
	{
		return brick;
	}

	void setBrickRot(float Rotation)
	{
		brick->setRotation(Rotation);
	}

	void setBrickColor(Color3B color)
	{
		brickColor = color;
	}

	Color3B getBrickColor()
	{
		return brickColor;
	}

	bool getSelBrick()
	{
		return selected;
	}

	void setSelBrick(bool tf)
	{
		selected = tf;
	}

};