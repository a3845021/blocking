#include "Stage.h"
#include "Singleton.h"
#include "GameScene.h"

Scene* Stage::createScene()
{
	auto scene = Scene::create();
	auto layer = Stage::create();
	scene->addChild(layer);
	return scene;
}

bool Stage::init()
{
	if (!Layer::init())
		return false;

	Size winSize = Director::getInstance()->getWinSize();

	_bg = Sprite::create("StageBG.jpg");
	_bg->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(_bg, 1);

	_scene = Layer::create();
	this->addChild(_scene, 1);

	St1 = Sprite::create("St1.png");
	St2 = Sprite::create("St2.png");
	St3 = Sprite::create("St3.png");
	St4 = Sprite::create("St4.png");
	St5 = Sprite::create("St5.png");
	St6 = Sprite::create("St6.png");
	St7 = Sprite::create("St7.png");
	St8 = Sprite::create("St8.png");
	St9 = Sprite::create("St9.png");
	St10 = Sprite::create("St10.png");

	St1->setPosition(winSize.width / 2, winSize.height / 2);
	St2->setPosition(winSize.width * 1.0, winSize.height / 2);
	St3->setPosition(winSize.width * 1.5, winSize.height / 2);
	St4->setPosition(winSize.width * 2.0, winSize.height / 2);
	St5->setPosition(winSize.width * 2.5, winSize.height / 2);
	St6->setPosition(winSize.width * 3.0, winSize.height / 2);
	St7->setPosition(winSize.width * 3.5, winSize.height / 2);
	St8->setPosition(winSize.width * 4.0, winSize.height / 2);
	St9->setPosition(winSize.width * 4.5, winSize.height / 2);
	St10->setPosition(winSize.width * 5.0, winSize.height / 2);

	int j = 0;

	for (float i = 5.5; i < 10.0f; i++)
	{
		++j;
		Sprite* lock = Sprite::create("Lock.png");
		lock->setPosition(winSize.width * i, winSize.height / 2);
		lock->setTag(j);
		_scene->addChild(lock, 5);
	}

	_scene->addChild(St1, 2);
	_scene->addChild(St2, 2);
	_scene->addChild(St3, 2);
	_scene->addChild(St4, 2);
	_scene->addChild(St5, 2);
	_scene->addChild(St6, 2);
	_scene->addChild(St7, 2);
	_scene->addChild(St8, 2);
	_scene->addChild(St9, 2);
	_scene->addChild(St10, 2);

	schedule(schedule_selector(Stage::Update));

	SlideState = Slide::NORMAL;

	BegineTouch = Vec2::ZERO;
	EndTouch = Vec2::ZERO;

	iSceneNum = 0;

	return true;
}

bool Stage::onTouchBegan(Touch *touch, Event *unused_event)
{
	BegineTouch = touch->getLocation();
	EndTouch = touch->getLocation();

	return true;
}

void Stage::onTouchMoved(Touch *touch, Event *unused_event)
{
	float vec = _scene->getPositionX();
	vec += touch->getDelta().x;
	_scene->setPositionX(vec);

	EndTouch = touch->getLocation();
}

void Stage::onTouchEnded(Touch *touch, Event *unused_event)
{
	log("iSceneNum : %d", iSceneNum);
	if (BegineTouch.x - 5 <= EndTouch.x && 
		BegineTouch.x + 5 >= EndTouch.x)
	{
		switch (iSceneNum)
		{
		case 0:{
			Singleton::getInstance()->Map1();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 1:{
			Singleton::getInstance()->Map2();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 2:{
			Singleton::getInstance()->Map3();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 3:{
			Singleton::getInstance()->Map4();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 4:{
			Singleton::getInstance()->Map5();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 5:{
			Singleton::getInstance()->Map6();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 6:{
			Singleton::getInstance()->Map7();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 7:{
			Singleton::getInstance()->Map8();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 8:{
			Singleton::getInstance()->Map9();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		case 9:{
			Singleton::getInstance()->Map10();
			Scene *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
			break; }
		}

		/*if ((iSceneNum) == 0)
		{
			Singleton::getInstance()->Map1();
			auto *pScene = TransitionFade::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
		}
		if ((iSceneNum) == 1)
		{

			Singleton::getInstance()->Map2();
			auto *pScene = TransitionFlipX::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
		}
		if ((iSceneNum) == 2)
		{

			Singleton::getInstance()->Map3();
			auto *pScene = TransitionFlipX::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
		}
		if ((iSceneNum * -1) == 3)
		{

			Singleton::getInstance()->Map4();
			auto *pScene = TransitionFlipX::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
		}
		if ((iSceneNum * -1) == 4)
		{

			Singleton::getInstance()->Map5();
			auto *pScene = TransitionFlipX::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
		}
		if ((iSceneNum * -1) == 5)
		{

			Singleton::getInstance()->Map6();
			auto *pScene = TransitionFlipX::create(0.3, GameScene::createScene());
			Director::getInstance()->replaceScene(pScene);
		}
		if (false)
		{

		}
		if (false)
		{

		}
		if (false)
		{

		}
		if (false)
		{

		}*/
	}
	else
	{
		if (SlideState == Slide::NORMAL)
		{
			if (BegineTouch.x - 15 > EndTouch.x)
			{
				log("Left Slide");
				SlideState = Slide::LEFT;
				clock = 0.f;
				iSceneNum += 1;

				log("iSceneNum : %d", iSceneNum);
				fSceneX = _scene->getPositionX();
			}
			else if (BegineTouch.x + 15 < EndTouch.x)
			{
				log("Right Slide");
				SlideState = Slide::RIGHT;
				clock = 0.f;
				iSceneNum -= 1;

				log("iSceneNum : %d", iSceneNum);
				fSceneX = _scene->getPositionX();
			}
		}
	}
}

void Stage::Update(float dt)
{
	if (SlideState == Slide::LEFT)
	{
		if (clock <= 1.f)
		{
			if (iSceneNum >= 11)
			{
				iSceneNum = 10;
				_scene->setPositionX(Lerp<float>(fSceneX, 400 * iSceneNum * -1, clock));
			}
			else
			{
				clock += dt * 5;
				_scene->setPositionX(Lerp<float>(fSceneX, 400 * iSceneNum * -1, clock));
			}
		}
		else
			SlideState = Slide::NORMAL;
	}

	if (SlideState == Slide::RIGHT)
	{
		if (clock <= 1.f)
		{
			if (iSceneNum <= -1)
			{
				iSceneNum = 0;
				_scene->setPositionX(Lerp<float>(fSceneX, 400 * iSceneNum * -1, clock));
			}
			else
			{
				clock += dt * 5;
				_scene->setPositionX(Lerp<float>(fSceneX, 400 * iSceneNum * -1, clock));
			}
		}
		else
			SlideState = Slide::NORMAL;
	}
}

void Stage::onEnter()
{
	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->setSwallowTouches(true);
	t_touch->onTouchBegan = CC_CALLBACK_2(Stage::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(Stage::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(Stage::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(t_touch, this);

	Layer::onEnter();
}

void Stage::onExit()
{
	Layer::onExit();
}