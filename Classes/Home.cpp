#include "stdafx.h"
#include "Home.h"
#include "MainScene.h"

Scene* Home::createScene()
{
	auto scene = Scene::create();
	auto layer = Home::create();
	scene->addChild(layer);
	return scene;
}

bool Home::init()
{
	if (!Layer::init())
		return false;
	Size winSize = Director::getInstance()->getWinSize();

	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3", true);

	Sprite* bg = Sprite::create("3.jpg");
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bg, 0);

	word = Sprite::create("2.jpg");
	word->setOpacity(0);
	word->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(word, 2);

	main = Sprite::create("1.jpg");
	main->setOpacity(0);
	main->setPosition((winSize.width / 2), ((winSize.height / 2) - 40));
	this->addChild(main, 3);

	DrawWord();
	DrawMain();

	schedule(schedule_selector(Home::Update), 1.0f);

	return true;
}

void Home::onMenu(Ref* sender)
{
	switch (((Node*)sender)->getTag())
	{
	case 1:
		auto scene = TransitionFadeBL::create(2.0f, MainScene::createScene());
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
		Director::getInstance()->replaceScene(scene);
		break;
	}
}

void Home::DrawMain()
{
	auto winSize = Director::getInstance()->getWinSize();
	auto action = FadeIn::create(1.5f);
	auto action2 = MoveTo::create(1.0f, Point(winSize.width / 2, winSize.height / 2));
	main->runAction(action);
	main->runAction(action2);
}

void Home::DrawWord()
{
	auto action = FadeIn::create(1.5f);
	auto action2 = FadeOut::create(1.5f);
	auto action3 = Sequence::create(action, action2, NULL);

	word->runAction(RepeatForever::create(action3));
}

bool Home::onTouchBegan(Touch *touch, Event *unused_event)
{
	auto scene = TransitionFade::create(2.0f, MainScene::createScene());
	Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
	Director::getInstance()->replaceScene(scene);

	return true;
}

void Home::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void Home::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void Home::Update(float dt)
{
	auto winSize = Director::getInstance()->getWinSize();



	auto ball = Sprite::create("Ball.png");
	ball->setPosition(0, rand() % 438 + 42);
	this->addChild(ball, 1);
	float RandSpeed = rand() % 3 + 1;
	ball->runAction(RepeatForever::create(MoveBy::create(RandSpeed, Point(100, 0))));
}
void Home::onEnter()
{
	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->setSwallowTouches(true);
	t_touch->onTouchBegan = CC_CALLBACK_2(Home::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(Home::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(Home::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);

	auto listener2 = EventListenerKeyboard::create();
	listener2->onKeyReleased = CC_CALLBACK_2(Home::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, this);

	Layer::onEnter();
}
void Home::onExit()
{
	//Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
	Layer::onExit();
}
void Home::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	//BACK
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
		MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
		return;
#endif

		cocos2d::Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
	}
}