#include"Edge.h"

bool Edge::init(){

	Node::init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
	setContentSize(visibleSize);

	return true;
}