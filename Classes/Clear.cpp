#include "Clear.h"
#include "GameScene.h"
#include "Home.h"

Scene* Clear::createScene()
{
	auto scene = Scene::create();
	auto layer = Clear::create();
	scene->addChild(layer);
	return scene;
}

bool Clear::init()
{
	if (!Layer::init())
		return false;

	Size winSize = Director::getInstance()->getWinSize();

	_bg = Sprite::create("Clear.jpg");
	_retry = Sprite::create("Retry.png");
	_home = Sprite::create("Home.png");
	_next = Sprite::create("Resum.png");

	_bg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_bg, 1);

	_retry->setPosition(winSize.width * 0.40, winSize.height * 0.3);
	this->addChild(_retry, 2);

	_home->setPosition(winSize.width * 0.60, winSize.height*0.3);
	this->addChild(_home, 2);

	return true;
}

bool Clear::onTouchBegan(Touch *touch, Event *unused_event)
{
	TransitionFade* scene;
	if (_retry->getBoundingBox().containsPoint(touch->getLocation()))
	{
		scene = TransitionFade::create(3.0f, GameScene::createScene());
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(scene);
	}
	if (_home->getBoundingBox().containsPoint(touch->getLocation()))
	{
		scene = TransitionFade::create(3.0f, Home::createScene());
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(scene);
	}

	return true;
}

void Clear::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void Clear::onTouchEnded(Touch *touch, Event *unused_event)
{

}
void Clear::onEnter()
{
	log("GameClear Scene");
	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->setSwallowTouches(true);
	t_touch->onTouchBegan = CC_CALLBACK_2(Clear::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(Clear::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(Clear::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);


	Layer::onEnter();
}
void Clear::onExit()
{
	Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}