#include"cocos2d.h"

USING_NS_CC;

class pauseScene : public LayerColor
{
public:
	virtual bool init();

	void continueEvent(Ref *pSender);
//	void restartEvent(Ref *pSender);
//	void returnEvent(Ref *pSender);

	static Scene *createScene();

	CREATE_FUNC(pauseScene);
private:

};
