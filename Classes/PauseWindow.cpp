#include "PauseWindow.h"
#include "Home.h"
#include "GameScene.h"

bool PauseWindow::init()
{
	if (!Layer::init())
		return false;

	Size winSize = Director::getInstance()->getWinSize();

	_playSound = true;

	_resum = Sprite::create("Resum.png");
	_resum->setScale(0.7f);
	_resum->setAnchorPoint(Point(1, 1));
	_resum->setPosition((winSize.width - _resum->getBoundingBox().size.width * 0.35), winSize.height);
	this->addChild(_resum, 4);

	_retry = Sprite::create("Retry.png");
	_retry->setScale(0.7f);
	_retry->setAnchorPoint(Point(1, 1));
	_retry->setPosition((winSize.width - _retry->getBoundingBox().size.width * 0.35), winSize.height);
	this->addChild(_retry, 3);

	_home = Sprite::create("Home.png");
	_home->setScale(0.7f);
	_home->setAnchorPoint(Point(1, 1));
	_home->setPosition((winSize.width - _home->getBoundingBox().size.width * 0.35), winSize.height);
	this->addChild(_home, 2);

	_sound = Sprite::create("Sound.png");
	_sound->setScale(0.7f);
	_sound->setAnchorPoint(Point(1, 1));
	_sound->setPosition((winSize.width - _sound->getBoundingBox().size.width * 0.35), winSize.height);
	this->addChild(_sound, 1);

	CallFunc* action;
	CallFunc* action2;
	ActionInterval* action3;

	doAni1();

	return true;
}

bool PauseWindow::onTouchBegan(Touch *touch, Event *unused_event)
{
	log("TOUCH PAUSE");

	CallFunc* action;
	CallFunc* action2;

	if (_resum->getBoundingBox().containsPoint(touch->getLocation()))
	{
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;		Director::getInstance()->resume();
		doAni2();
	}
	
	if (_retry->getBoundingBox().containsPoint(touch->getLocation()))
	{
		Director::getInstance()->resume();
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;		auto scene = TransitionFade::create(1.0f, GameScene::createScene());
		Director::getInstance()->replaceScene(scene);
	}

	if (_home->getBoundingBox().containsPoint(touch->getLocation()))
	{
		//Director::getInstance()->getEventDispatcher()->removeEventListener(t_touch);
		Director::getInstance()->resume();
		Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);;		scene = TransitionFade::create(2.0f, Stage::createScene());
		Director::getInstance()->replaceScene(scene);
	}
	if (_sound->getBoundingBox().containsPoint(touch->getLocation()))
	{
		if (_playSound)
		{
			_sound->setTexture("Sound2.png");
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			_playSound = false;
		}
		else
		{
			_sound->setTexture("Sound.png");
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
			//SimpleAudioEngine::getInstance()->willPlayBackgroundMusic();
			_playSound = true;
		}
	}
	return true;
}

void PauseWindow::onEnter()
{
	t_touch = EventListenerTouchOneByOne::create();
	t_touch->onTouchBegan = CC_CALLBACK_2(PauseWindow::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(PauseWindow::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(PauseWindow::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);

	Layer::onEnter();
}
void PauseWindow::onExit()
{
	//Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	//this->removeAllChildren();
	Layer::onExit();
}

void PauseWindow::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void PauseWindow::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void PauseWindow::doAni1()
{
	auto action = MoveBy::create(0.2f, Point(0, -(_retry->getBoundingBox().size.height + 40)));
	auto action2 = MoveBy::create(0.2f, Point(0, -((_retry->getBoundingBox().size.height * 2) + 40)));
	auto action3 = MoveBy::create(0.2f, Point(0, -((_retry->getBoundingBox().size.height * 3) + 40)));
	auto action4 = MoveBy::create(0.2f, Point(0, -((_retry->getBoundingBox().size.height * 4) + 40)));
	auto action5 = CallFuncN::create(CC_CALLBACK_0(PauseWindow::pauseGame, this));
	auto action6 = Sequence::create(action4, action5, NULL);
	_resum->runAction(action);
	_retry->runAction(action2);
	_home->runAction(action3);
	_sound->runAction(action6);
}

void PauseWindow::doAni2()
{
	Size winSize = Director::getInstance()->getWinSize();

	auto action = MoveTo::create(0.2f, Point((winSize.width - _resum->getBoundingBox().size.width * 0.35), winSize.height));
	auto action2 = MoveTo::create(0.2f, Point((winSize.width - _resum->getBoundingBox().size.width * 0.35), winSize.height));
	auto action3 = MoveTo::create(0.2f, Point((winSize.width - _resum->getBoundingBox().size.width * 0.35), winSize.height));
	auto action4 = MoveTo::create(0.2f, Point((winSize.width - _resum->getBoundingBox().size.width * 0.35), winSize.height));
	auto action5 = CallFuncN::create(CC_CALLBACK_0(PauseWindow::resumGame, this));
	auto action6 = Sequence::create(action4, action5, NULL);
	_retry->runAction(action);
	_resum->runAction(action2);
	_home->runAction(action3);
	_sound->runAction(action6);
}

void PauseWindow::pauseGame()
{
	Director::getInstance()->pause();
}

void PauseWindow::resumGame()
{
	Director::getInstance()->resume();
	this->removeAllChildrenWithCleanup(true);
}