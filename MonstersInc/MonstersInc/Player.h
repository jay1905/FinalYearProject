//
//  Player.h
//  MonstersInc
//
//  Created by Jaime Aughney on 22/10/2012.
//  Copyright (c) 2012 __MonstersInc__. All rights reserved.
//

#ifndef MonstersInc_Player_h
#define MonstersInc_Player_h

#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"



class Player: public PhysicsSprite
{
public:
    Player(cocos2d::CCSpriteBatchNode *hello,b2World* world);
    
    
    void update(b2Vec2 direction);
    void drawStuf();

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
