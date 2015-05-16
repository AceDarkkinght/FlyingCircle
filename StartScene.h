#include"cocos2d.h"
#include"ui\UIButton.h"

USING_NS_CC;
using namespace ui;

class startScene :public LayerColor
{
public:
	virtual bool init();

	static Scene *createScene();

	CREATE_FUNC(startScene);

	void startEvent(Ref *pSender, TouchEventType type);

	void closeEvent(Ref *pSender, TouchEventType type);

};
