#include"cocos2d.h"

USING_NS_CC;

class Obstacle : public Sprite
{
public:
	virtual bool init();

	virtual void update(float dt);

	CREATE_FUNC(Obstacle);

private:


};
