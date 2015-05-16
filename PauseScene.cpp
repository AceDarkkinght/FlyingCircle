#include"PauseScene.h"

USING_NS_CC;

bool pauseScene::init(){
	if (!pauseScene::initWithColor(Color4B(220, 200, 200, 50)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//������Ϸ��ť
	auto continueButton = MenuItemImage::create("startButton.png", "startButton.png", CC_CALLBACK_1(pauseScene::continueEvent,this));
	continueButton->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height / 2));
	addChild(continueButton);

	//���¿�ʼ��ť
	//auto restartButton = MenuItemImage::create("restartButton.png", "restartButton.png", CC_CALLBACK_1(pauseScene::restartEvent, this));
	//restartButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//addChild(restartButton);

	////���������水ť
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

//������Ϸ
void pauseScene::continueEvent(Ref *pSender){

}