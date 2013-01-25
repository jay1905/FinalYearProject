//
//  StaticEntity.h
//  MonstersInc
//
//  Created by Jaime Aughney on 17/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_StaticEntity_h
#define MonstersInc_StaticEntity_h



#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"

class StaticEntity :public PhysicsSprite
{
    
public:
    StaticEntity();
    
    void initialize(cocos2d::CCSpriteBatchNode *hello,b2World* world,b2Vec2 pos,float speed,b2Vec2 size,  std::string name);
    b2FixtureDef fixyureDef;
    b2BodyDef bodyDef;
private:
    
    b2Body* body;
    b2PolygonShape dynamicBox;
    
    cocos2d::CCAnimation * anim;    
    cocos2d::CCAnimate *theAnim ;
    float speed;
};

#endif
