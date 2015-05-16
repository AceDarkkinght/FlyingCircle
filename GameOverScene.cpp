#include"GameOverScene.h"

bool GameOverScene::init(){
	LayerColor::initWithColor(Color4B(255, 255, 255, 255));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	//ÓÎÏ·½áÊøÒ³Ãæ
	auto label = Label::create("Game Over", "fonts/Marker Felt.ttf", 40);
	label->setColor(Color3B(0, 0, 0));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(label);

	return true;
}

Scene *GameOverScene::createScene(){
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);

	return scene;
}