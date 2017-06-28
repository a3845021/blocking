#include "stdafx.h"
#include "Home.h"
#include "Credit.h"

Scene* Credit::createScene()
{
	auto scene = Scene::create();
	auto layer = Credit::create();
	scene->addChild(layer);
	return scene;
}

bool Credit::init()
{
	if (!Layer::init())
		return false;

	Size winSize = Director::getInstance()->getVisibleSize();

	_back = Sprite::create("Retry.png");
	_back->setAnchorPoint(Point(0, 1));
	_back->setScale(0.8);
	_back->setPosition(0, winSize.height);
	this->addChild(_back, 5);

	auto sprite = Sprite::create("3.jpg");
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	sprite->setPosition(250, 250);
	this->addChild(sprite);

	auto node = ParallaxNode::create();
	this->addChild(node);

	auto action0 = MoveBy::create(25.0f, Point(-2000, 0));
	auto action1 = Place::create(Point::ZERO);
	auto action2 = Sequence::create(action0, action1, NULL);
	auto action3 = RepeatForever::create(action2);
	node->runAction(action3);

	auto spr0 = Sprite::create("credit.png");
	spr0->setAnchorPoint(Point::ZERO);
	node->addChild(spr0, 0, Point(1, 0), Point::ZERO);

	auto spr1 = Sprite::create("credit.png");
	spr1->setAnchorPoint(Point::ZERO);
	node->addChild(spr1, 0, Point(1, 0), Point(3000, 0));

	auto spr2 = Sprite::create("credit.png");
	spr2->setAnchorPoint(Point::ZERO);
	node->addChild(spr2, 0, Point(1, 0), Point::ZERO);

	auto spr3 = Sprite::create("credit.png");
	spr3->setAnchorPoint(Point::ZERO);
	node->addChild(spr3, 0, Point(1, 0), Point(3000, 0));

	auto spr4 = Sprite::create("credit.png");
	spr4->setAnchorPoint(Point::ZERO);
	node->addChild(spr4, 0, Point(1, 0), Point(6000, 0));
}

bool Credit::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (_back->getBoundingBox().containsPoint(touch->getLocation()))
	{
		_back->setOpacity(180);
		auto scene = TransitionFade::create(2.0f, Home::createScene());
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
		Director::getInstance()->replaceScene(scene);
	}
	return false;
}

void Credit::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void Credit::onTouchEnded(Touch *touch, Event *unused_event)
{

}
void Credit::onEnter()
{
	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->setSwallowTouches(true);
	t_touch->onTouchBegan = CC_CALLBACK_2(Credit::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(Credit::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(Credit::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);

	Layer::onEnter();
}
void Credit::onExit()
{

	Layer::onExit();
}