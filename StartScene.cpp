#include"startScene.h"
#include"GameWorldLayer.h"
#include"ui\UIButton.h"

USING_NS_CC;
using namespace ui;

bool startScene::init(){

	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//开始游戏按钮
	auto startButton = Button::create("startButton.png");
	startButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(startButton);

	startButton->addTouchEventListener(this, toucheventselector(startScene::startEvent));


	//关闭游戏按钮
	auto closeButton = Button::create("closeButton.png");
	closeButton->setAnchorPoint(Vec2(1, 1));
	closeButton->setPosition(Vec2(visibleSize.width, visibleSize.height));
	addChild(closeButton);

	closeButton->addTouchEventListener(this, toucheventselector(startScene::closeEvent));

	//游戏标题
	auto label = Label::create("Flying Circle", "fonts/Marker Felt.ttf", 40);
	label->setColor(Color3B(0, 0, 0));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height *0.75));
	addChild(label);

	return true;
}

Scene* startScene::createScene(){

	auto scene = Scene::create();
	scene->addChild(startScene::create());

	return scene;
}

//开始游戏
void startScene::startEvent(Ref *pSender, TouchEventType type){

	auto scene = GameWorldLayer::createScene();

	switch (type)
	{
	case TOUCH_EVENT_ENDED:
		Director::getInstance()->replaceScene(scene);
		break;
	}
}

//关闭游戏
void startScene::closeEvent(cocos2d::Ref *pSender, TouchEventType type){
	switch (type)
	{
	case TOUCH_EVENT_BEGAN:
		Director::getInstance()->end();
		break;
	}
}
