#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"
USING_NS_CC;

class Entity :public Node {
public:
	Entity();
	~Entity();
	Sprite* getSprite();
	void bindSprite(Sprite *sprite);
private:
	Sprite* m_sprite;
};


#endif
