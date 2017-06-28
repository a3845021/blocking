#include "GameClear.h"
#include "GameScene.h"
#include "Stage.h"
#include "Home.h"


Scene* GameClear::createScene()
{
	auto scene = Scene::create();
	auto layer = GameClear::create();
	scene->addChild(layer);
	return scene;
}

bool GameClear::init()
{
	if (!Layer::init())
		return false;

	Size winSize = Director::getInstance()->getWinSize();

	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->onTouchBegan = CC_CALLBACK_2(GameClear::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(GameClear::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(GameClear::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);

	_bg = Sprite::create("Clear.png");
	_retry = Sprite::create("Retry.png");
	_home = Sprite::create("Home.png");
	_next = Sprite::create("Resum.png");

	_bg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_bg, 1);

	_retry->setPosition(winSize.width * 0.35, winSize.height * 0.3);
	this->addChild(_retry, 2);

	_home->setPosition(winSize.width / 2, winSize.height*0.3);
	this->addChild(_home, 2);

	_next->setPosition(winSize.width* 0.65, winSize.height*0.3);
	this->addChild(_next, 2);

	return true;
}

bool GameClear::onTouchBegan(Touch *touch, Event *unused_event)
{
	log("Clear Touch");
	TransitionFade* scene;
	if (_retry->getBoundingBox().containsPoint(touch->getLocation()))
	{
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
		scene = TransitionFade::create(1.0f, GameScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}

	if (_home->getBoundingBox().containsPoint(touch->getLocation()))
	{
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
		scene = TransitionFade::create(2.0f, Home::createScene());
		Director::getInstance()->replaceScene(scene);
	}

	if (_next->getBoundingBox().containsPoint(touch->getLocation()))
	{
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
		scene = TransitionFade::create(2.0f, Stage::createScene());
		Director::getInstance()->replaceScene(scene);
	}

	return true;
}

void GameClear::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void GameClear::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void GameClear::onEnter()
{
	log("GameClear Scene onEnter");
	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->onTouchBegan = CC_CALLBACK_2(GameClear::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(GameClear::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(GameClear::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(t_touch, true);


	auto listener2 = EventListenerKeyboard::create();
	listener2->onKeyReleased = CC_CALLBACK_2(GameClear::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, this);

	Layer::onEnter();
}

void GameClear::onExit()
{
	//Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}

void GameClear::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	//BACK
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(Stage::createScene());
	}
}