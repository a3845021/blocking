#include "stdafx.h"
#include "MainScene.h"
#include "Stage.h"
#include "Credit.h"
#include "Home.h"

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
		return false;


	Size winSize = Director::getInstance()->getWinSize();

	_bg = Sprite::create("BG.jpg");
	_bg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_bg, 1);

	_stage = Sprite::create("stagebut.png");
	_stage->setPosition(winSize.width / 2, winSize.height * 0.5);
	this->addChild(_stage, 3);

	_credit = Sprite::create("creditbut.png");
	_credit->setPosition(winSize.width / 2, winSize.height * 0.35);
	this->addChild(_credit, 2);

	_mute = Sprite::create("mute.png");
	_mute->setPosition(winSize.width / 2, winSize.height * 0.20);
	this->addChild(_mute, 4);


	_speaker = Sprite::create("Speaker.png");
	_speaker->setPosition(winSize.width * 0.8, winSize.height * 0.6);
	this->addChild(_speaker, 5);

	_speaker2 = Sprite::create("Speaker.png");
	_speaker2->setPosition(winSize.width * 0.2, winSize.height * 0.6);
	this->addChild(_speaker2, 5);

	_Mute = false;

	schedule(schedule_selector(MainScene::Update), 0.5f);

	return true;
}

void MainScene::Update(float dt)
{
	Size winSize = Director::getInstance()->getWinSize();

	Sprite* tempSpeaker = Sprite::create("Speaker.png");
	tempSpeaker->setPosition(_speaker->getPositionX(), _speaker->getPositionY());
	this->addChild(tempSpeaker, 6);
	Sprite* tempSpeaker2 = Sprite::create("Speaker.png");
	tempSpeaker2->setPosition(_speaker2->getPositionX(), _speaker2->getPositionY());
	this->addChild(tempSpeaker2, 6);

	auto action = ScaleTo::create(1.0f, 2.0f);
	auto action2 = FadeOut::create(1.0f);

	auto action_1 = ScaleTo::create(1.0f, 2.0f);
	auto action_2 = FadeOut::create(1.0f);

	tempSpeaker->runAction(Sequence::create(Spawn::create(action, action2, NULL), RemoveSelf::create(), NULL));
	tempSpeaker2->runAction(Sequence::create(Spawn::create(action_1, action_2, NULL), RemoveSelf::create(), NULL));
}

bool MainScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto action = ScaleTo::create(0.5f, 1.5f);
	auto action2 = FadeOut::create(0.5f);
	auto action3 = FadeOut::create(0.5f);
	auto action4 = MoveTo::create(0.5f, Point(winSize.width / 2, winSize.height * 0.35));
	auto action5 = CallFunc::create(CC_CALLBACK_0(MainScene::gotoStage, this));
	auto action6= CallFunc::create(CC_CALLBACK_0(MainScene::gotoCredit, this));
	if (_stage->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_credit->runAction(action2);
		_mute->runAction(action3);
		_stage->runAction(Sequence::create(Spawn::create(action, action4, NULL), action5, NULL));
	}
	if (_credit->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_stage->runAction(action2);
		_mute->runAction(action3);
		_credit->runAction(Sequence::create(Spawn::create(action, action4, NULL), action6, NULL));
	}
	if (_mute->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (!_Mute)
		{
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			_Mute = true;
		}
		else
		{
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
			_Mute = false;
		}
	}

	return false;
}

void MainScene::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void MainScene::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void MainScene::gotoStage()
{
	auto scene = TransitionFade::create(2.0f, Stage::createScene());
	Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
	Director::getInstance()->replaceScene(scene);
}

void MainScene::gotoCredit()
{
	auto scene = TransitionFade::create(2.0f, Credit::createScene());
	Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
	Director::getInstance()->replaceScene(scene);
}

void MainScene::onEnter()
{
	auto t_touch = EventListenerTouchOneByOne::create();;
	t_touch->setSwallowTouches(true);
	t_touch->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);

	auto listener2 = EventListenerKeyboard::create();
	listener2->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, this);

	Layer::onEnter();

}
void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	//BACK
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(Home::createScene());
	}
}

void MainScene::onExit()
{
	//Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
	Layer::onExit();
}
