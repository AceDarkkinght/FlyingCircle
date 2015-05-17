#include"GameOverScene.h"
#include"GameWorldLayer.h"
#include"StartScene.h"

bool GameOverScene::init(){
	LayerColor::initWithColor(Color4B(255, 255, 255, 255));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	//游戏结束
	auto label = Label::create("Game Over", "fonts/Marker Felt.ttf", 40);
	label->setColor(Color3B(0, 0, 0));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(label);

	//重新开始游戏按钮
	auto restartButton = MenuItemImage::create("restartButton.png", "restartButton.png", CC_CALLBACK_1(GameOverScene::restartEvent, this));
	restartButton->setPosition(Vec2(visibleSize.width * 0.4, visibleSize.height * 0.4));

	//返回主界面按钮
	auto returnButton = MenuItemImage::create("returnButton.png", "returnButton.png", CC_CALLBACK_1(GameOverScene::returnEvent, this));
	returnButton->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.4));

	auto menu = Menu::create(restartButton, returnButton, NULL);
	menu->setPosition(Point::ZERO);
	addChild(menu);

	return true;
}

Scene *GameOverScene::createScene(){
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);

	return scene;
}

//重新开始游戏
void GameOverScene::restartEvent(Ref *pSender){
	auto s = GameWorldLayer::createScene();
	Director::getInstance()->replaceScene(s);
}

//返回主界面
void GameOverScene::returnEvent(Ref *pSender){
	auto s = StartScene::createScene();
	Director::getInstance()->replaceScene(s);
}