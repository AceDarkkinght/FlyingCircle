#include"cocos2d.h"

USING_NS_CC;

class StartScene :public LayerColor
{
public:
	virtual bool init();

	static Scene *createScene();

	CREATE_FUNC(StartScene);

	void startEvent(Ref *pSender);

	void closeEvent(Ref *pSender);

};
