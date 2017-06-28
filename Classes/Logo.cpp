#include "Logo.h"
#include "Home.h"

Scene* Logo::createScene()
{
	auto scene = Scene::create();
	auto layer = Logo::create();
	scene->addChild(layer);
	return scene;
}

bool Logo::init()
{
	if (!Layer::init())
		return false;

	Size winSize = Director::getInstance()->getWinSize();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Logo.mp3");

	_logo = Sprite::create("Logo.png");
	_logo->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_logo, 2);

	_bapdoduk = Sprite::create("Bapdoduk.png");
	_bapdoduk->setPosition(winSize.width / 2, (winSize.height / 2) - 80);
	_bapdoduk->setOpacity(0);
	this->addChild(_bapdoduk, 1);

	auto action = FadeIn::create(1.5f);
	auto action2 = MoveTo::create(1.0f, Point(winSize.width / 2, (winSize.height / 2) - 40));
	_bapdoduk->runAction(action);
	_bapdoduk->runAction(action2);

	schedule(schedule_selector(Logo::Update));

	return true;
}

void Logo::Update(float dt)
{
	if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		auto scene = TransitionFade::create(3.0f, Home::createScene());
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;
		Director::getInstance()->replaceScene(scene);
	}
}
