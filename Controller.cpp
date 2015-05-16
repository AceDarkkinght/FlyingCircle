#include"Controller.h"

bool Controller::init(cocos2d::Layer *layer, float positionY){
	_layer = layer;
	_positionY = positionY;
	visibleSize = Director::getInstance()->getVisibleSize();

	//�����߽��
	edge = Edge::create();
	edge->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2+positionY));
	edge->setContentSize(visibleSize);
	_layer->addChild(edge);

	//�����ذ�
	auto ground = Sprite::create();
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	ground->setPosition(Vec2(visibleSize.width / 2, 1.5 + positionY));
	ground->setColor(Color3B(0, 0, 0));
	_layer->addChild(ground);

	//����ԲȦ
	circle = Sprite::create("circle.png");
	auto circleBody = PhysicsBody::createCircle(circle->getContentSize().width / 2);
	circle->setPhysicsBody(circleBody);
	circle->setPosition(Vec2(50, circle->getContentSize().height/2+_positionY+80));
	_layer->addChild(circle);
	circle->getPhysicsBody()->setContactTestBitmask(1);

	resetFrame();

	return true;
}

Controller *Controller::create(cocos2d::Layer *layer, float positionY){
	auto i = new Controller();
	i->init(layer, positionY);
	i->autorelease();
	return i;
}

//��������ϰ���
void Controller::obstacleUpdate(float dt){
	currentFrameIndex++;

	if (currentFrameIndex >= nextFrameCount)
	{
		if (currentFrameIndex % 2 == 0)
		{
			resetFrame();
			downObstacle1();
			upObstacle1();
		}
		else
		{
			resetFrame();
			downObstacle2();
			upObstacle2();
		}
	}
}

//�����ϰ�������
void Controller::resetFrame(){
	currentFrameIndex = 0;
	nextFrameCount = rand() % 120 + 100;
}

//�ϰ���
void Controller::downObstacle1(){
	auto oDown = Obstacle::create();
	oDown->setPositionY(oDown->getContentSize().height / 2 + _positionY);
	_layer->addChild(oDown);
}

void Controller::downObstacle2(){
	auto oDown = Obstacle::create();
	oDown->setPositionY(oDown->getContentSize().height / 2 + _positionY);
	_layer->addChild(oDown);
}

void Controller::upObstacle1(){
	auto o = Obstacle::create();
	o->setPositionY(visibleSize.height - o->getContentSize().height / 2);
	_layer->addChild(o);
}

void Controller::upObstacle2(){
	auto o = Obstacle::create();
	o->setPositionY(visibleSize.height/2 -o->getContentSize().height / 2);
	_layer->addChild(o);
}

//��ȡ������
bool Controller::touchPonit(Vec2 point){
	return edge->getBoundingBox().containsPoint(point);
}

//����ʱʹԲȦ��������
void Controller::onTouch(){
	circle->getPhysicsBody()->setVelocity(Vec2(0, 200));
}