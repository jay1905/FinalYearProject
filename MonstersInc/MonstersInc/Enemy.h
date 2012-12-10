//
//  Enemy.h
//  MonstersInc
//
//  Created by Jaime Aughney on 05/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Enemy_h
#define MonstersInc_Enemy_h

#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"



class Enemy: public PhysicsSprite
{
public:
    Enemy(cocos2d::CCSpriteBatchNode *hello,b2World* world,b2Vec2 pos,float speed,b2Vec2 size);
    
    
    void update();
    void drawStuf();
    void move();
    
private:
   
   
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixyureDef;
    cocos2d::CCAnimation * anim;    
    cocos2d::CCAnimate *theAnim ;
    
    float speed;
    
    
};

#endif
