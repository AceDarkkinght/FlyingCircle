#include"GameOverScene.h"
#include"GameWorldLayer.h"
#include"StartScene.h"

bool GameOverScene::init(){
	LayerColor::initWithColor(Color4B(255, 255, 255, 255));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	//��Ϸ����
	auto label = Label::create("Game Over", "fonts/Marker Felt.ttf", 40);
	label->setColor(Color3B(0, 0, 0));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(label);

	//���¿�ʼ��Ϸ��ť
	auto restartButton = MenuItemImage::create("restartButton.png", "restartButton.png", CC_CALLBACK_1(GameOverScene::restartEvent, this));
	restartButton->setPosition(Vec2(visibleSize.width * 0.4, visibleSize.height * 0.4));

	//���������水ť
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

//���¿�ʼ��Ϸ
void GameOverScene::restartEvent(Ref *pSender){
	auto s = GameWorldLayer::createScene();
	Director::getInstance()->replaceScene(s);
}

//����������
void GameOverScene::returnEvent(Ref *pSender){
	auto s = StartScene::createScene();
	Director::getInstance()->replaceScene(s);
}