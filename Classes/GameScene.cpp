#include "stdafx.h"
#include "Singleton.h"
#include "GameScene.h"
#include "GameClear.h"
#include "PauseWindow.h"

Scene* GameScene::createScene() {
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = GameScene::create();

	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B::BLACK))
		return false;

	Size winSize = this->getContentSize();

	//------------------------------------------------------------
	// BackGround
	Sprite* Background = Sprite::create("Background/Background.jpg");
	Background->setPosition(Vec2::ZERO);
	Background->setAnchorPoint(Vec2::ZERO);
	//this->addChild(Background, 0, "Background");

	//--------------------------------------------------
	// 블럭과 공을 담을 레이더 초기화
	ObjectLayer = Layer::create();
	this->addChild(ObjectLayer);

	Sprite* block = Sprite::create("blocks.png");
	block->setPosition(Vec2(390, 50));
	this->addChild(block, 3);

	// 블럭을 생성
	for (int i = 0; i < Singleton::getInstance()->RedBlockCount; i++)
	{
		Brick* brick = new Brick();
		brick->InitBrick(460, 67, Singleton::getInstance()->RedBlockDamage);
		brick->getBrick()->setTexture("Block/YB.png");
		brick->getBrick()->setScaleX(0.6);
		brick->getBrick()->setScaleY(0.6);
		brick->setBrickColor(Color3B(255, 156, 0));


		PhysicsBody* body = PhysicsBody::createBox(Size(
			brick->getBrick()->getContentSize().width*0.6,
			brick->getBrick()->getContentSize().height*0.6),
			PhysicsMaterial(1.0, 1.0, 1.0));


		body->setDynamic(false);
		body->setGravityEnable(true);
		body->setCategoryBitmask(0x02);
		body->setCollisionBitmask(0x01);


		brick->setSelBrick(false);
		brick->getBrick()->setPhysicsBody(body);
		ObjectLayer->addChild(brick, 3);

		BrickVector.pushBack(brick);
	}

	//---------------------------------------------------
	// 블럭을 생성
	for (int i = 0; i < Singleton::getInstance()->BlueBlockCount; i++)
	{
		Brick* brick = new Brick();
		brick->InitBrick(350, 67, Singleton::getInstance()->BlueBlockDamage);
		brick->getBrick()->setTexture("Block/BB.png");
		brick->getBrick()->setScaleX(0.6);
		brick->getBrick()->setScaleY(0.608);
		brick->setBrickColor(Color3B(0, 99, 255));

		PhysicsBody* body = PhysicsBody::createBox(Size(
			brick->getBrick()->getContentSize().width*0.6,
			brick->getBrick()->getContentSize().height*0.608),
			PhysicsMaterial(1.0, 1.0, 1.0));

		body->setDynamic(false);
		body->setGravityEnable(true);
		body->setCategoryBitmask(0x02);
		body->setCollisionBitmask(0x01);


		brick->setSelBrick(false);
		brick->getBrick()->setPhysicsBody(body);
		ObjectLayer->addChild(brick, 2);

		BrickVector.pushBack(brick);
	}
	//----------------------------------------------------
	// 공을 생성

	Ball = new BallClass;
	Ball->BallInit();
	Ball->getBall()->setPosition(Vec2(Singleton::getInstance()->BubbleX, Singleton::getInstance()->BubbleY));
	Ball->BlockUpdate();
	ObjectLayer->addChild(Ball, 3);

	//----------------------------------------------------
	// 골 초기화

	Goal = new GoalClass();
	Goal->setGoalColor(Singleton::getInstance()->GoalColor);
	Goal->setSpinGoal(6.0f, 360.0f);
	Goal->setGoalPosition(Point(Singleton::getInstance()->GoalX, Singleton::getInstance()->GoalY));
	this->addChild(Goal->getGoal());

	//---------------------------------------------------
	// 블럭을 생성 WALL
	for (int i = 0; i < Singleton::getInstance()->BlueWallCount; i++)
	{
		Brick* brick = new Brick();
		float X, Y;
		float ROT;

		switch (i)
		{
		case 0:
			X = Singleton::getInstance()->BA.x;
			Y = Singleton::getInstance()->BA.y;
			ROT = Singleton::getInstance()->BAR;
			break;
		case 1:
			X = Singleton::getInstance()->BB.x;
			Y = Singleton::getInstance()->BB.y;
			ROT = Singleton::getInstance()->BBR;
			break;
		}
		brick->InitBrick(X, Y, Singleton::getInstance()->BlueWallDamage);
		brick->getBrick()->setTexture("Block/BB.png");
		brick->getBrick()->setScaleX(0.6);
		brick->getBrick()->setScaleY(0.608);
		brick->getBrick()->setRotation(ROT);
		brick->setBrickColor(Color3B(0, 99, 255));

		PhysicsBody* body = PhysicsBody::createBox(Size(
			brick->getBrick()->getContentSize().width*0.6,
			brick->getBrick()->getContentSize().height*0.608),
			PhysicsMaterial(1.0, 1.0, 1.0));

		body->setDynamic(false);
		body->setGravityEnable(true);
		body->setCategoryBitmask(0x02);
		body->setCollisionBitmask(0x01);


		brick->setSelBrick(false);
		brick->getBrick()->setPhysicsBody(body);
		ObjectLayer->addChild(brick, 2);

		WallVector.pushBack(brick);
	}

	// 블럭을 생성 WALL
	for (int i = 0; i < Singleton::getInstance()->RedeWallCount; i++)
	{
		Brick* brick = new Brick();
		float X, Y;
		float ROT;

		switch (i)
		{
		case 0:
			X = Singleton::getInstance()->RA.x;
			Y = Singleton::getInstance()->RA.y;
			ROT = Singleton::getInstance()->RAR;
			break;
		case 1:
			X = Singleton::getInstance()->RB.x;
			Y = Singleton::getInstance()->RB.y;
			ROT = Singleton::getInstance()->RBR;
			break;
		}
		brick->InitBrick(X, Y, Singleton::getInstance()->RedWallDamage);
		brick->getBrick()->setTexture("Block/YB.png");
		brick->getBrick()->setScaleX(0.6);
		brick->getBrick()->setScaleY(0.608);
		brick->getBrick()->setRotation(ROT);
		brick->setBrickColor(Color3B(255, 156, 0));


		PhysicsBody* body = PhysicsBody::createBox(Size(
			brick->getBrick()->getContentSize().width*0.6,
			brick->getBrick()->getContentSize().height*0.6),
			PhysicsMaterial(1.0, 1.0, 1.0));


		body->setDynamic(false);
		body->setGravityEnable(true);
		body->setCategoryBitmask(0x02);
		body->setCollisionBitmask(0x01);


		brick->setSelBrick(false);
		brick->getBrick()->setPhysicsBody(body);
		ObjectLayer->addChild(brick, 3);

		WallVector.pushBack(brick);
	}

	//---------------------------------------------------
	// 기타초기화

	temporarilyBrick = new Brick();

	schedule(schedule_selector(GameScene::update));

	schedule(schedule_selector(GameScene::CollideUpdate));

	schedule(schedule_selector(GameScene::GameOverUpdate));

	isTouch = false;

	GameStart = false;

	Menu = Sprite::create("Menu.png");
	Menu->setPosition((winSize.width - Menu->getBoundingBox().size.width * 0.6), (winSize.height - Menu->getBoundingBox().size.height * 0.6));
	this->addChild(Menu, 1);

	return true;
}

void GameScene::GameOverUpdate(float dt)
{
	if (!first)
	{
		if (0 > Ball->getBall()->getPositionX())
		{
			GameClear* clear = GameClear::create();
			clear->setScale(0.5);
			this->addChild(clear);
			clear->runAction(Sequence::create(ScaleBy::create(0.2f, 2.0f), NULL));
			Ball->getBall()->setPosition(Vec2(0, Ball->getBall()->getPosition().y));
			first = true;
		}
		if (D_DESIGN_WIDTH < Ball->getBall()->getPositionX())
		{
			GameClear* clear = GameClear::create();
			clear->setScale(0.5);
			this->addChild(clear);
			clear->runAction(Sequence::create(ScaleBy::create(0.2f, 2.0f), NULL));
			Ball->getBall()->setPosition(Vec2(D_DESIGN_WIDTH, Ball->getBall()->getPosition().y));
			first = true;
		}
		if (0 > Ball->getBall()->getPositionY())
		{
			GameClear* clear = GameClear::create();
			clear->setScale(0.5);
			this->addChild(clear);
			clear->runAction(Sequence::create(ScaleBy::create(0.2f, 2.0f), NULL));
			Ball->getBall()->setPosition(Vec2(Ball->getBall()->getPosition().x, 0));
			first = true;
		}
		if (D_DESIGN_HEIGHT < Ball->getBall()->getPositionY())
		{
			GameClear* clear = GameClear::create();
			clear->setScale(0.5);
			this->addChild(clear);
			clear->runAction(Sequence::create(ScaleBy::create(0.2f, 2.0f), NULL));
			Ball->getBall()->setPosition(Vec2(Ball->getBall()->getPosition().x, D_DESIGN_HEIGHT));
			first = true;
		}
	}
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	//BACK
	if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
	{
		pause = PauseWindow::create();
		this->addChild(pause);
	}
}

void GameScene::update(float dt)
{
	// 블럭이 화면밖을 벗어나지 못하도록함
	/*for (auto it : BrickVector)
	{
	if (0 > it->getBrick()->getPositionX())
	it->getBrick()->setPosition(Vec2(0, it->getBrick()->getPosition().y));

	if (D_DESIGN_WIDTH < it->getBrick()->getPositionX())
	it->getBrick()->setPosition(Vec2(D_DESIGN_WIDTH, it->getBrick()->getPosition().y));

	if (0 > it->getBrick()->getPositionY())
	it->getBrick()->setPosition(Vec2(it->getBrick()->getPosition().x, 0));

	if (D_DESIGN_HEIGHT < it->getPositionY())
	it->getBrick()->setPosition(Vec2(it->getBrick()->getPosition().x, D_DESIGN_HEIGHT));
	}*/

	if (GameStart)
	{
		Sprite* Shadow = Sprite::create("Ball.png");
		Shadow->setPosition(Ball->getBall()->getPosition());
		Shadow->setColor(Ball->getBall()->getColor());
		Shadow->setOpacity(50);
		Ball->getParent()->addChild(Shadow);

		Shadow->runAction(Sequence::create(FadeOut::create(0.4f), RemoveSelf::create(), NULL));
	}
}

void GameScene::CollideUpdate(float dt)
{
	Size winSize = this->getContentSize();
	if (GameStart)
	{
		for (auto it : BrickVector)
		{
			if (Ball->getBall()->getBoundingBox().intersectsRect(Goal->getGoal()->getBoundingBox()))
			{
				if (!ifClear)
				{
					if (Ball->getBallColor() != Goal->getGoalColor())
					{
						Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
						GameClear* clear = GameClear::create();
						clear->setScale(0.5);
						this->addChild(clear);
						clear->runAction(Sequence::create(ScaleBy::create(0.2f, 2.0f), NULL));
						ifClear = true;
						break;
					}
				}
			}
			if (it->enable)
			{
				if (it->CollideBlock)
				{
					if (!Ball->getBall()->getBoundingBox().intersectsRect(it->getBrick()->getBoundingBox()))
					{
						Ball->setBallColor(it->getBrickColor());
						it->CollideBlock = false;
					}
				}

				if (!it->CollideBlock) // false일때 부름
				{
					//log("%d", it->CollideBlock);
					if (Ball->getBall()->getBoundingBox().intersectsRect(it->getBrick()->getBoundingBox()))
					{
						it->CollideBlock = true;

						Ball->setBallColor(it->getBrickColor());

						BrickAnima(it);

						break;
					}
				}
			}
		}
	}
}

void GameScene::onEnter()
{
	auto t_touch = EventListenerTouchOneByOne::create();
	t_touch->setSwallowTouches(true);
	t_touch->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	t_touch->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	t_touch->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(t_touch, this);

	auto listener2 = EventListenerKeyboard::create();
	listener2->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, this);


	Layer::onEnter();
}

void GameScene::onExit()
{
	//Director::getInstance()->getEventDispatcher()->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	log("GameClear GOGO");

	Layer::onExit();
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	log("TOUCH GAME");

	if (Singleton::getInstance()->MapCount == 0)
	{
		switch (count)
		{
		case 0:
			Tu = Sprite::create();
			Tu->setTexture("Tu1.png");
			Tu->setPosition(Vec2(D_DESIGN_WIDTH / 2, D_DESIGN_HEIGHT / 2));
			this->addChild(Tu);
			break;
		case 1:
			Tu->setTexture("Tu2.png");
			break;
		case 2:
			Tu->setTexture("Tu3.png");
			break;
		case 3:
			Tu->removeAllChildrenWithCleanup(true);
			Tu->setVisible(false);
			break;
		}
	}
	count += 1;


	// 현재 터치 좌표
	Vec2 Touch = touch->getLocation();

	// 공을 터치하면 게임 시작
	if (Ball->getBall()->getBoundingBox().containsPoint(touch->getLocation()))
	{
		GameStart = true;
		This_Touch = Vec2(900, 900);
		//-------------------------
		PhysicsBody* body =
			PhysicsBody::createCircle(20,
			PhysicsMaterial(1.0, 1.0, 0.0));

		body->setDynamic(true);
		body->setGravityEnable(true);
		body->setVelocity(Vec2(Singleton::getInstance()->BubblePowerX, Singleton::getInstance()->BubblePowerY));
		body->setCategoryBitmask(0x01);
		body->setCollisionBitmask(0x02);

		Ball->getBall()->setPhysicsBody(body);

		Ball->BallDirectionCursorRemove();
	}

	ActionInterval* action;
	CallFunc* action2;
	ActionInterval* action3;
	if (Menu->getBoundingBox().containsPoint(touch->getLocation()))
	{
		action = RotateBy::create(0.3f, 360);
		action2 = CallFuncN::create(CC_CALLBACK_0(GameScene::onMenu, this));
		action3 = Sequence::create(action, action2, NULL);
		Menu->runAction(action3);
	}

	log("%.f", Touch.x);
	log("%.f", Touch.y);

	// 터치함
	// 절대로 다른곳에 쓰지 말것
	doTouch = true;

	if (!GameStart)
	{
		// 블럭을 터치한다면
		if (!isToBrickTouch)
		{
			// 터치한 블럭을 찾아냄
			for (auto it : BrickVector)
			{
				// 임시의 블럭에 터치한 블럭의 정보를 넣음
				temporarilyBrick = it;
				if (temporarilyBrick->getBrick()->getBoundingBox().containsPoint(Touch))
				{
					//---------------------------

					for (auto it : BrickVector)
					{
						// 우선 전부 블럭 선택을 false시킴
						it->setSelBrick(false);

						// 블럭을 터치함
						isToBrickTouch = true;
					}

					//----------------------------
					// 그다음 선택한 블럭을 
					it->setSelBrick(true);
					break;
				}
			}
		}
	}

	// 현재 터치한 값을 넘김
	This_Touch = Touch;

	if (!GameStart)
	{
		// 블럭을 터치했을때는 회전시키지 않는다
		if (!isToBrickTouch)
		{
			if (doTouch)
			{
				touchBrickAndTurn(This_Touch);
			}
		}

		return true;
	}
}

void GameScene::onTouchMoved(Touch *touch, Event *unused_event)
{
	// 터치후 움직인 값
	Vec2 Touch = touch->getLocation();
	Vector<Brick*>::iterator FindBlock;

	if (!GameStart)
	{
		// 터치한 블럭을 찾아내어 좌표를 이동시킴
		if (isToBrickTouch)
		{
			FindBlock = find(BrickVector.begin(), BrickVector.end(), temporarilyBrick);
			if ((*FindBlock)->getSelBrick())
			{
				(*FindBlock)->getBrick()->setPosition(Touch);
			}
		}
	}
}

void GameScene::onTouchEnded(Touch *touch, Event *unused_event)
{
	isToBrickTouch = false;
	isTouch = false;
	This_Touch = Vec2(900, 900);
}

void GameScene::CollideBrickToBall()
{

}

void GameScene::BrickAnima(Brick* target)
{
	if (target->enable)
	{
		if (target->damage != 0)
		{
			BoundingAni(target);
		}
		else
		{
			CrashAni(target);
		}
	}
}

void GameScene::touchBrickAndTurn(Vec2 touch)
{
	for (auto brick : BrickVector)
	{
		if (brick->getSelBrick())
		{
			if (brick->enable)
			{
				if (D_DESIGN_WIDTH / 2 < touch.x && D_DESIGN_WIDTH > touch.x)
				{
					brick->getBrick()->setRotation(brick->getBrick()->getRotation() + 45);
					break;
				}

				if (D_DESIGN_WIDTH / 2 > touch.x && 0 < touch.x)
				{
					brick->getBrick()->setRotation(brick->getBrick()->getRotation() - 45);
					break;
				}
			}
		}
	}

}

void GameScene::BoundingAni(Brick* target)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Block/Brick.plist");
	char temp[100];
	Vector<SpriteFrame*> spriteframe;

	if (target->getBrickColor() == Color3B(255, 156, 0))
	{
		for (int i = 7; i < 15; i++)
		{
			sprintf(temp, "YB%d.png", i);
			auto sprite = cache->getSpriteFrameByName(temp);
			spriteframe.pushBack(sprite);
		}

		Animation* AniFrame = Animation::createWithSpriteFrames(spriteframe, 0.1);
		Animate*   Ani = Animate::create(AniFrame);

		target->getBrick()->runAction(Spawn::create(Ani, NULL));
	}

	else
	{
		for (int i = 7; i < 15; i++)
		{
			sprintf(temp, "BB%d.png", i);
			auto sprite = cache->getSpriteFrameByName(temp);
			spriteframe.pushBack(sprite);
		}

		Animation* AniFrame = Animation::createWithSpriteFrames(spriteframe, 0.1);
		Animate*   Ani = Animate::create(AniFrame);

		target->getBrick()->runAction(Spawn::create(Ani, NULL));
	}

	target->damage -= 1;
}

void GameScene::CrashAni(Brick* target)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	Sprite* tempSprite = Sprite::create();
	tempSprite->setPosition(target->getBrick()->getPosition());
	tempSprite->setRotation(target->getBrick()->getRotation());
	tempSprite->setScale(0.6);
	this->addChild(tempSprite);

	cache->addSpriteFramesWithFile("Block/Crash.plist");

	char temp[100];
	Vector<SpriteFrame*> spriteframe;

	for (int i = 3; i < 18; i++)
	{
		sprintf(temp, "c%d.png", i);
		auto sprite = cache->getSpriteFrameByName(temp);
		spriteframe.pushBack(sprite);
	}

	Animation* AniFrame = Animation::createWithSpriteFrames(spriteframe, 0.01);
	Animate* Ani = Animate::create(AniFrame);

	auto func = CallFuncN::create(CC_CALLBACK_0(GameScene::removeShadow, this, this));

	//tempSprite->runAction(Sequence::create(Ani, RemoveSelf::create(), NULL));

	target->enable = false;
	//target->getBrick()->setVisible(false);

	//target->getBrick()->setPosition(Vec2(900, 900));

	target->getBrick()->runAction(Sequence::create(Ani, DelayTime::create(0.0005), FadeOut::create(0.0001), RemoveSelf::create(), NULL));
}

void GameScene::removeShadow(cocos2d::CCObject *pSender)
{
	CCSprite *pShadow = (CCSprite*)pSender;
	pShadow->removeFromParentAndCleanup(true);
}

void GameScene::removeBrickVector(Object* pSender)
{
	Brick* pBrick = (Brick*)pSender;
}

void GameScene::onMenu()
{
	pause = PauseWindow::create();
	this->addChild(pause);
}
