#include"cocos2d.h"
#include"Edge.h"
#include"Obstacle.h"

USING_NS_CC;

class Controller : public Ref
{
public:
	virtual bool init(cocos2d::Layer *layer, float positionY);
	static Controller *create(cocos2d::Layer *layer, float positionY);
	void obstacleUpdate(float dt);
	bool touchPonit(Vec2 point);
	void onTouch();

private:
	Layer *_layer;
	float _positionY;
	Edge *edge;
	Sprite *circle;

	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;

	void resetFrame();
	void downObstacle1();
	void downObstacle2();
	void upObstacle1();
	void upObstacle2();
};
