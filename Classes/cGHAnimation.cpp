#include "cGHAnimation.h"

namespace GH
{

	bool CGHAnimation::Init(string plistPath, string imageGetpath, string extension, int maxFrame, int intervalStart)
	{
		//!< �ʱ�ȭ ����
		m_strPlistPath	= plistPath;
		m_strImagePath	= imageGetpath;
		m_strExtension	= extension;
		m_cPos			= ccp(0,0);
		m_nLayer		= 0;
		m_nMaxFrame		= maxFrame;
		m_fTumTime		= 0.1f;
		m_nNowFrame		= 0;
		m_bType			= false;
		m_bStop			= false;
		m_bVisible		= true;
		m_fCurTime		= 0.0f;
		m_nLoopCount	= 1;
		m_nNowLoopCount = 0;

		//!< Plist�� ��ϵ� �̹��� �ε�
		String* plistStringName = String::createWithFormat("%s.plist" , plistPath.c_str());
		if(plistStringName == NULL) return false;
		//!< Plist�� ��ϵ� �̹��� ĳ��
		SpriteFrameCache* cache = SpriteFrameCache::sharedSpriteFrameCache();
		//!< ĳ�ÿ� ����
		cache->addSpriteFramesWithFile(plistStringName->getCString());

		//!< ������ŭ interval ���Ƽ� �ִϸ��̼� ����
		for(int i = intervalStart ; i < m_nMaxFrame + intervalStart ; i++)
		{
			//!< plist �� key ���� ������
			String * fileName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , i , extension.c_str());

			//!< ������ ���
			SpriteFrame* frame = cache->spriteFrameByName(fileName->getCString());

			//!< ���帶�� ���
			auto pSprite = new GH::CGHSprite;
			pSprite->initWithSpriteFrame(frame);
			pSprite->setPosition(m_cPos);
			pSprite->setVisible(false);

			//!< vector�� ����Ͽ� �ڿ�����
			m_pTable.push_back(pSprite);
		}

		//!< ù �������� ���̵��� ����
		m_pTable[0]->setVisible(true);

		return true;
	}

	void CGHAnimation::AnimationUpdate(float dt)
	{
		if(m_bStop) return;

		switch(m_bType)
		{
		case true:
			//!< ����Ʈ �϶�
			if(m_nNowLoopCount >= m_nLoopCount) return;
			//!< �ð� Ÿ�̸� ����
			m_fCurTime += dt;

			//!< ���� ���� ���������� �Ѿ �ð��� ���
			if(m_fCurTime >= m_fTumTime)
			{
				m_pTable[m_nNowFrame]->setVisible(false);			//!< ���� �������� �Ⱥ��̵��� ����
				m_nNowFrame++;										//!< ���� �������� ����
				m_fCurTime = 0;										//!< ��� �ð��� �ʱ�ȭ
			}

			//!< �ݺ��Ǹ� �ȵǹǷ� ������ ���������� ����
			//!< �ִ� �ݺ�Ƚ�� ���� �� �� ��ŭ ����
			if(m_nNowFrame >= m_nMaxFrame)
			{
				m_nNowLoopCount++;
				m_nNowFrame = 0;
			}

			if(m_nNowLoopCount >= m_nLoopCount) m_nNowFrame = m_nMaxFrame - 1;

			break;
		case false:
			//!< ����Ʈ �ƴҶ�

			//!< �ð� Ÿ�̸� ����
			m_fCurTime += dt;

			//!< ���� ���� ���������� �Ѿ �ð��� ���
			if(m_fCurTime >= m_fTumTime)
			{
				m_pTable[m_nNowFrame]->setVisible(false);			//!< ���� �������� �Ⱥ��̵��� ����
				m_nNowFrame++;										//!< ���� �������� ����
				m_fCurTime = 0;										//!< ��� �ð��� �ʱ�ȭ
			}

			//!< �ݺ��Ǿ� �ϹǷ� ���� �������� �ִ� ������ �Ѿ �� �ʱ� ���������� �� ����
			if(m_nNowFrame >= m_nMaxFrame)
				m_nNowFrame = 0;

			break;
		}

		if(m_bVisible)
		{
			if(!m_pTable[m_nNowFrame]->isVisible())
				m_pTable[m_nNowFrame]->setVisible(true);
		}
		else
		{
			if(m_pTable[m_nNowFrame]->isVisible())
				m_pTable[m_nNowFrame]->setVisible(false);
		}
	}

	void CGHAnimation::addChild()
	{
		for (int i = 0; i < m_nMaxFrame; i++)
			m_pLayer->addChild(m_pTable[i], m_nLayer);
	}

	void CGHAnimation::setAniTime(float time)
	{
		m_fTumTime = time;
	}

	float CGHAnimation::getAniTime()
	{
		return m_fTumTime;
	}

	void CGHAnimation::setEffect(bool bChk)
	{
		m_bType = bChk;
	}

	bool CGHAnimation::getEffect()
	{
		return m_bType;
	}

	void CGHAnimation::setLoopCount(int nLoop)
	{
		m_nLoopCount = nLoop;
	}

	int CGHAnimation::getLoopCount()
	{
		return m_nLoopCount;
	}

	void CGHAnimation::setLayer(int nLayer)
	{
		m_nLayer = nLayer;
	}

	int CGHAnimation::getLayer()
	{
		return m_nLayer;
	}

	void CGHAnimation::setPosition(Point pos)
	{
		m_cPos = pos;
		for (int i = 0; i < m_nMaxFrame; i++)
			m_pTable[i]->setPosition(m_cPos);
	}

	Point CGHAnimation::getPosition()
	{
		return m_cPos;
	}

	void CGHAnimation::setAnchorPositon(Point pos)
	{
		m_pTable[m_nNowFrame]->setAnchorPoint(pos);
	}

	Point CGHAnimation::getAnchorPosition()
	{
		return m_pTable[m_nNowFrame]->getAnchorPoint();
	}

	void CGHAnimation::setVisible(bool bChk)
	{
		m_bVisible = bChk;
	}

	bool CGHAnimation::getVisible()
	{
		return m_bVisible;
	}

	void CGHAnimation::setScale(Point pos)
	{
		m_cScale = pos;
		m_pTable[m_nNowFrame]->setScaleX(m_cScale.x);
		m_pTable[m_nNowFrame]->setScaleY(m_cScale.y);
	}

	float CGHAnimation::getScale()
	{
		return m_pTable[m_nNowFrame]->getScale();
	}

	void CGHAnimation::setFrame(int nFrame)
	{
		m_pTable[m_nNowFrame]->setVisible(false);
		m_nNowFrame = nFrame;
		m_fCurTime = 0.0f;
		m_pTable[m_nNowFrame]->setVisible(true);
	}

	int CGHAnimation::getFrame()
	{
		return m_nNowFrame;
	}

	void CGHAnimation::setStop()
	{
		m_bStop = true;
	}

	void CGHAnimation::setResume()
	{
		m_bStop = false;
	}

	void CGHAnimation::Destroy()
	{
		for(int i = 0 ; i < m_pTable.size() ; i++)
			CC_SAFE_DELETE(m_pTable[i]);

		m_pTable.clear();
	}
}