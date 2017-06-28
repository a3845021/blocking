#pragma once

#include "cocos2d.h"
#include "CGHSprite.h"

USING_NS_CC;
using namespace std;

namespace GH
{
	class CGHAnimation
	{
	private:
		Layer*					m_pLayer;				//!< �̹��� �Ѹ� ���
		string					m_strPlistPath;			//!< Plist ���
		string					m_strImagePath;			//!< �̹��� �̸�
		string					m_strExtension;			//!< Ȯ����
		Point					m_cPos;
		Point					m_cScale;

		int						m_nLayer;				//!< �׷��� ���̾� ��ȣ
		int						m_nNowFrame;			//!< ���� �ִϸ��̼� �������� ������
		int						m_nMaxFrame;			//!< �ִ� �ִϸ��̼� ����
		int						m_nLoopCount;			//!< ��� ����ϴ� ��
		int						m_nNowLoopCount;		//!< ���� ����� ����

		bool					m_bType;				//!< Ÿ���� ����Ʈ ���� �ƴ���
		bool					m_bVisible;				//!< �ִϸ��̼��� ���̰� ���� ������
		bool					m_bStop;				//!< ������ �� ���� ��

		float					m_fTumTime;				//!< ���� ��������Ʈ�� �Ѿ �ð�
		float					m_fCurTime;				//!< ���� �������� �ð�

		vector<GH::CGHSprite*>	m_pTable;				//!< vector ���̺� (Sprite ����)

	public:
		CGHAnimation(Layer* pLayer) : m_pLayer(pLayer){}
		~CGHAnimation() { Destroy(); }

	public:
		/**
		@brief : �ִϸ��̼� �ʱ�ȭ ���� image/hero/texture_hero.plist , png ������ �ִٸ� Init("image/hero/texture_hero" , "hero_" , ".png" , 5 , 0); ���ָ� ��
		@param : Plist�� ��� ( Ȯ���ڸ� �� )
		@param : plist ������ ����� �̹��� �̸�
		@param : Ȯ���� �̸�
		@param : �ִ� ������ ����
		@param : 0���� ������ ������ 1���� ������ ������ ����
		@return : true �������� �ʱ�ȭ
		@return : false �ʱ�ȭ ����
		*/
		bool Init(string plistPath , string imageGetpath , string extension , int maxFrame = 1, int intervalStart = 0);

		/**
		@brief : �ִϸ��̼� ������Ʈ Ŭ����
		@param : delay time
		*/
		void AnimationUpdate(float dt);

		void addChild();

		void setEffect(bool bChk);
		bool getEffect();

		void setLoopCount(int nLoop);
		int getLoopCount();

		void setAniTime(float time);
		float getAniTime();

		void setLayer(int nLayer);
		int getLayer();

		void setPosition(Point pos);
		Point getPosition();

		void setAnchorPositon(Point pos);
		Point getAnchorPosition();

		void setVisible(bool bChk);
		bool getVisible();

		void setScale(Point pos);
		float getScale();

		void setFrame(int nFrame);
		int getFrame();

		void setStop();
		void setResume();

		void Destroy();
	};
}