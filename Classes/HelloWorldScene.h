#pragma once

#include "stdafx.h"

class HelloWorld : public Layer
{
private:
	//!< �ִϸ��̼�
	GH::CGHAnimation * m_pAni;
	GH::CGHAnimation * m_pAni2;

public:
    //!< �� ������ ���� �̱���
    static Scene* createScene();

    //!< �ʱ�ȭ �ϴ� ����
	//!< bool ������ ���� ������ true �� �������� ��ȯ
	//!< false �� ���������� �ȵǾ��� ������ ���� �޽����� ��ȯ�ϱ� ����
    virtual bool init();  
    
    //!< �ݹ� �Լ� (�� ������ ������ �� ����)
    void menuCloseCallback(Ref* pSender);
    
	void Update(float dt);

    //!< ���� ��� ��Ŵ
    CREATE_FUNC(HelloWorld);
};