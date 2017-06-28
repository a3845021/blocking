#pragma once

#pragma once
template <class T>
class singleton {
private:
	static T* m_single;
public:
	// ������
	singleton()
	{
		/*empty*/
	}
	// �Ҹ���
	virtual ~singleton()
	{
		delete m_single;
	}
	// �ν��Ͻ� ����
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