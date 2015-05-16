#include"cocos2d.h"
#include"Controller.h"
#include"ui\UIButton.h"

USING_NS_CC;
using namespace ui;

class GameWorldLayer : public LayerColor{

public:
	GameWorldLayer();
	~GameWorldLayer();
	virtual bool init();	

	static Scene *createScene();

	CREATE_FUNC(GameWorldLayer);

	virtual void update(float dt);

	bool touchPonit(Vec2 point);
	
	void addTime(float dt);

	void pauseEvent(Ref *pSender, TouchEventType type);

private:
	Vector<Controller*> controllers;

	Label *timer;

	long startTime;
};