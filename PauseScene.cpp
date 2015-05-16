#include"PauseScene.h"

USING_NS_CC;

bool pauseScene::init(){
	if (!pauseScene::initWithColor(Color4B(220, 200, 200, 50)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//继续游戏按钮
	auto continueButton = MenuItemImage::create("startButton.png", "startButton.png", CC_CALLBACK_1(pauseScene::continueEvent,this));
	continueButton->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height / 2));
	addChild(continueButton);

	//重新开始按钮
	//auto restartButton = MenuItemImage::create("restartButton.png", "restartButton.png", CC_CALLBACK_1(pauseScene::restartEvent, this));
	//restartButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//addChild(restartButton);

	////返回主界面按钮
	//auto returnButton = MenuItemImage::create("returnButton.png", "returnButton.png", CC_CALLBACK_1(pauseScene::returnEvent, this));
	//returnButton->setPosition(Vec2(visibleSize.width * 0.7, visibleSize.height / 2));
	//addChild(returnButton);

	return true;
}

Scene* pauseScene::createScene(){

	auto scene = Scene::create();
	scene->addChild(pauseScene::create());

	return scene;
}

//继续游戏
void pauseScene::continueEvent(Ref *pSender){

}