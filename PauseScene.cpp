#include"PauseScene.h"
#include"GameWorldLayer.h"
#include"StartScene.h"

USING_NS_CC;

bool pauseScene::init(){
	if (!pauseScene::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//继续游戏按钮
	auto continueButton = MenuItemImage::create("startButton.png", "startButton.png", CC_CALLBACK_1(pauseScene::continueEvent,this));
	continueButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	//重新开始游戏按钮
	auto restartButton = MenuItemImage::create("restartButton.png", "restartButton.png", CC_CALLBACK_1(pauseScene::restartEvent, this));
	restartButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.3));

	//返回主界面按钮
	auto returnButton = MenuItemImage::create("returnButton.png", "returnButton.png", CC_CALLBACK_1(pauseScene::returnEvent, this));
	returnButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.7));

	auto menu = Menu::create(continueButton,restartButton,returnButton,NULL);
	menu->setPosition(Point::ZERO);
	addChild(menu);

	return true;
}

Scene* pauseScene::createScene(){

	auto scene = Scene::create();
	scene->addChild(pauseScene::create());

	return scene;
}

//继续游戏
void pauseScene::continueEvent(Ref *pSender){

	Director::getInstance()->popScene();
}

//重新开始游戏
void pauseScene::restartEvent(Ref *pSender){
	auto s = GameWorldLayer::createScene();
	Director::getInstance()->replaceScene(s);
}

//返回主界面
void pauseScene::returnEvent(Ref *pSender){
	auto s = StartScene::createScene();
	Director::getInstance()->replaceScene(s);
}