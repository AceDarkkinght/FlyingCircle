#include"StartScene.h"
#include"GameWorldLayer.h"

USING_NS_CC;

bool StartScene::init(){

	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//开始游戏按钮
	auto startButton = MenuItemImage::create("startButton.png", "startButton.png",CC_CALLBACK_1(StartScene::startEvent,this));
	startButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));


	//关闭游戏按钮
	auto closeButton = MenuItemImage::create("closeButton.png", "closeButton.png",CC_CALLBACK_1(StartScene::closeEvent,this));
	closeButton->setAnchorPoint(Vec2(1, 1));
	closeButton->setPosition(Vec2(visibleSize.width, visibleSize.height));

	auto menu = Menu::create(startButton, closeButton,NULL);
	menu->setPosition(Point::ZERO);
	addChild(menu);

	//游戏标题
	auto label = Label::create("Flying Circle", "fonts/Marker Felt.ttf", 40);
	label->setColor(Color3B(0, 0, 0));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height *0.75));
	addChild(label);

	return true;
}

Scene* StartScene::createScene(){

	auto scene = Scene::create();
	scene->addChild(StartScene::create());

	return scene;
}

//开始游戏
void StartScene::startEvent(Ref *pSender){

	auto scene = GameWorldLayer::createScene();
	Director::getInstance()->replaceScene(scene);

}

//关闭游戏
void StartScene::closeEvent(cocos2d::Ref *pSender){
	Director::getInstance()->end();
}
