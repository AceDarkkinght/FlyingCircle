#include"GameWorldLayer.h"
#include"GameOverScene.h"
#include"PauseScene.h"
#include"ui\UIButton.h"

USING_NS_CC;
using namespace ui;

GameWorldLayer::GameWorldLayer(){

}

GameWorldLayer::~GameWorldLayer(){

}

bool GameWorldLayer::init(){

	if (!LayerColor :: initWithColor(Color4B(255,255,255,255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//添加暂停按钮
	auto pauseButton = Button::create("pauseButton.png");
	pauseButton->setAnchorPoint(Vec2(1, 1));
	pauseButton->setPosition(Vec2(visibleSize.width, visibleSize.height));
	addChild(pauseButton);

	pauseButton->addTouchEventListener(this, toucheventselector(GameWorldLayer::pauseEvent));

	//添加圆圈
	controllers.insert(0, Controller::create(this, 20));
	controllers.insert(0, Controller::create(this, visibleSize.height / 2));

	scheduleUpdate();

	//添加计时器
	startTime = clock();
	timer = Label::create("0.000", "fonts/Marker Felt.ttf", 25);
	timer->setColor(Color3B(0, 0, 0));
	timer->setPosition(Vec2(3, visibleSize.height));
	timer->setAnchorPoint(Vec2(0, 1));
	addChild(timer);
	schedule(schedule_selector(GameWorldLayer::addTime),0.01f);

	//结束游戏判断
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact &contact)
	{
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(GameOverScene::createScene());

		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);	//事件监听器

	//判断触摸区域
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch *t, Event *e)
	{
		for (auto i = controllers.begin(); i < controllers.end(); i++)
		{
			if ((*i)->touchPonit(t->getLocation()))
			{
				(*i)->onTouch();
				break;
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);	//事件监听器

	return true;
}


//创建物理世界
Scene* GameWorldLayer::createScene(){

	auto scene = Scene::createWithPhysics();
//	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -400)); 

	scene->addChild(GameWorldLayer::create());

	return scene;
}

//添加障碍物
void GameWorldLayer::update(float dt){
	for (auto i = controllers.begin(); i != controllers.end(); i++)
	{
		(*i)->obstacleUpdate(dt);
	}
}

//计时器计时
void GameWorldLayer::addTime(float dt){
	long offsetTime = clock() - startTime;
	timer->setString(StringUtils::format("%g", ((double)offsetTime) / 1000));
}

//暂停游戏
void GameWorldLayer::pauseEvent(Ref *pSender, TouchEventType type){
	switch (type)
	{
	case TOUCH_EVENT_ENDED:
		Director::getInstance()->pause();
		break;
	}
}
