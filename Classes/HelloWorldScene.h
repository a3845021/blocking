#pragma once

#include "stdafx.h"

class HelloWorld : public Layer
{
private:
	//!< 애니메이션
	GH::CGHAnimation * m_pAni;
	GH::CGHAnimation * m_pAni2;

public:
    //!< 씬 생성에 대한 싱글톤
    static Scene* createScene();

    //!< 초기화 하는 구문
	//!< bool 형으로 만든 이유는 true 면 정상적인 반환
	//!< false 면 정상적으로 안되었기 때문에 오류 메시지를 반환하기 위함
    virtual bool init();  
    
    //!< 콜백 함수 (이 씬에선 종료할 때 쓰임)
    void menuCloseCallback(Ref* pSender);
    
	void Update(float dt);

    //!< 씬을 등록 시킴
    CREATE_FUNC(HelloWorld);
};