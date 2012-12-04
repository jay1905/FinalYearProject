//
//  Bullet.h
//  MonstersInc
//
//  Created by Jaime Aughney on 06/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Bullet_h
#define MonstersInc_Bullet_h


#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"



class Bullet: public PhysicsSprite
{
public:
    Bullet(cocos2d::CCSpriteBatchNode *hello,b2World* world,b2Vec2 pos);
    
    
    void update(b2Body* b);
    void drawStuf();
    void fire(b2Vec2 direction);
    
    cocos2d::CCSpriteBatchNode *sprite;
    void destroy(){timetolive=500;}
    std::string typeName;
   
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
