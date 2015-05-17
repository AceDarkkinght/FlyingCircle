#include"cocos2d.h"

USING_NS_CC;

class GameOverScene : public LayerColor
{
public:
	virtual bool init();

	CREATE_FUNC(GameOverScene);

	void restartEvent(Ref *pSender);
	void returnEvent(Ref *pSender);

	static Scene *createScene();

private:

};
