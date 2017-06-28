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

	Singleton()
	{
		RedBlockCount = 0;
		RedBlockDamage = 0;

		BlueBlockCount = 0;
		BlueBlockDamage = 0;

		AllBlockCount = 0;

		MapCount = 0;
	}

	bool init()
	{
		RedBlockCount = 2;
		BlueBlockCount = 3;
		AllBlockCount = RedBlockCount + BlueBlockCount;
		return true;
	}
};