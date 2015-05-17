#include"Obstacle.h"

bool Obstacle::init(){
	Sprite::init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size size = Size(rand() % 40 + 5, rand() % 80 + 20);

	//障碍物属性
	setPhysicsBody(PhysicsBody::createBox(size));
	setTextureRect(Rect(0, 0, size.width, size.height));
	setColor(Color3B(0, 0, 0));
	setContentSize(size);

	setPositionX(visibleSize.width);
	scheduleUpdate();

	getPhysicsBody()->setDynamic(false);

	getPhysicsBody()->setContactTestBitmask(1);

	return true;
}

void Obstacle::update(float dt){

	this->setPositionX(getPositionX() - 3);//障碍物移动速度
	
	//离开屏幕时移除障碍物
	if (getPositionX() < 0)
	{
		unscheduleUpdate();
		removeFromParent();
	}
}