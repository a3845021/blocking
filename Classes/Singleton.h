#pragma once

#pragma once
template <class T>
class singleton {
private:
	static T* m_single;
public:
	// 생성자
	singleton()
	{
		/*empty*/
	}
	// 소멸자
	virtual ~singleton()
	{
		delete m_single;
	}
	// 인스턴스 관리
	static T* getInstance()
	{
		if (m_single == NULL)
		{
			m_single = new T();
			m_single->init();
		}
		return m_single;
	}
};
template <class T> T* singleton<T>::m_single = 0;


class Singleton : public singleton<Singleton>
{
public:
	float BubbleX;
	float BubbleY;
	int BubblePowerX;
	int BubblePowerY;
public:
	int RedBlockCount;
	int RedBlockDamage;

public:
	int BlueBlockCount;
	int BlueBlockDamage;

public:
	int AllBlockCount;

public:
	int MapCount;

public:
	int GoalColor;
	float GoalX;
	float GoalY;

public:
	int BlueWallCount;
	int BlueWallDamage;

	Vec2 BA, BB;
	float BAR, BBR;

	int RedeWallCount;
	int RedWallDamage;

	Vec2 RA, RB;
	float RAR, RBR;
public:

	Singleton()
	{
		BubbleX = 0;
		BubbleY = 0;

		BubblePowerX = 400;
		BubblePowerY = 0;

		RedBlockCount = 0;
		RedBlockDamage = 0;

		BlueBlockCount = 0;
		BlueBlockDamage = 0;

		AllBlockCount = 0;

		MapCount = 0;

		GoalColor = YELLOW;
		GoalX = 0;
		GoalY = 0;

		BlueWallCount = 0;
		BlueWallDamage = 0;
		BA = Vec2::ZERO, BB = Vec2::ZERO;
		BAR = 0, BBR = 0;

		RedeWallCount = 0;
		RedWallDamage = 0;
		RA = Vec2::ZERO, RB = Vec2::ZERO;
		RAR = 0, RBR = 0;

	}

	void loadMap(int i)
	{
		switch (i)
		{
		case 0:
			Map1();
			break;
		case 1:
			Map2();
			break;
		case 2:
			Map3();
			break;
		case 3:
			Map4();
			break;
		case 4:
			Map5();
			break;
		case 5:
			Map6();
			break;
		case 6:
			Map7();
			break;
		case 7:
			Map8();
			break;
		case 8:
			Map9();
			break;
		case 9:
			Map10();
			break;
		}
	}

	bool init()
	{
		Map1();
		return true;
	}

	void Map1()
	{
		BubbleX = 90;
		BubbleY = 270;

		RedBlockCount = 1;
		RedBlockDamage = 3;

		GoalColor = YELLOW;
		GoalX = 640;
		GoalY = 70;

		MapCount = 0;
	}

	void Map2()
	{
		BubbleX = 96;
		BubbleY = 400;

		RedBlockCount = 2;
		RedBlockDamage = 0;

		GoalColor = YELLOW;
		GoalX = 100;
		GoalY = 100;

		MapCount = 1;
	}

	void Map3()
	{
		BubbleX = 90;
		BubbleY = 180;

		BlueBlockCount = 1;
		BlueBlockDamage = 0;

		RedBlockCount = 2;
		RedBlockDamage = 0;

		GoalColor = BLUE;
		GoalX = 625;
		GoalY = 410;

		MapCount = 2;
	}

	void Map4()
	{
		BubbleX = 79;
		BubbleY = 158;

		BubblePowerX = 400;
		BubblePowerY = 0;

		RedBlockCount = 1;
		RedBlockDamage = 10;

		BlueBlockCount = 2;
		BlueBlockDamage = 0;

		GoalColor = BLUE;
		GoalX = 640;
		GoalY = 35;

		RedeWallCount = 1;
		RedWallDamage = 10;
		RA.x = 653;
		RA.y = 413;
		RAR = 45;


		MapCount = 3;
	}

	void Map5()
	{
		BubbleX = 200;
		BubbleY = 230;

		BubblePowerX = 400;
		BubblePowerY = 0;

		RedBlockCount = 4;
		RedBlockDamage = 5;

		GoalColor = YELLOW;
		GoalX = 99;
		GoalY = 131;

		RedeWallCount = 2;
		RedWallDamage = 10;
		RA.x = 257;
		RA.y = 163;
		RAR = 135;

		RB.x = 320;
		RB.y = 224;
		RBR = 135;

		MapCount = 4;
	}

	void Map6()
	{

		BubbleX = 107;
		BubbleY = 270;

		BubblePowerX = 200;
		BubblePowerY = 0;

		BlueBlockCount = 2;
		BlueBlockDamage = 5;

		RedBlockCount = 2;
		RedBlockDamage = 5;

		GoalColor = BLUE;
		GoalX = 670;
		GoalY = 425;

		RedeWallCount = 1;
		RedWallDamage = 10;
		RA.x = 458;
		RA.y = 274;
		RAR = 45;


		MapCount = 5;
	}

	void Map7()
	{
		MapCount = 6;
	}

	void Map8()
	{
		MapCount = 7;
	}

	void Map9()
	{
		MapCount = 8;
	}

	void Map10()
	{
		MapCount = 9;
	}
};