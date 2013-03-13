//
//  Base.h
//  MonstersInc
//
//  Created by Jaime Aughney on 06/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Base_h
#define MonstersInc_Base_h



#include "cocos2d.h"
#include "Box2D.h"
#include "StaticEntity.h"



class Base: public StaticEntity
{
public:
    Base(b2World* world);
    
    
    void update(b2Vec2 direction);
    void drawStuf();
    
private:
    
    b2BodyDef bodyDef;
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixyureDef;
    cocos2d::CCAnimation * anim;    
    cocos2d::CCAnimate *theAnim ;
    
 
    
     cocos2d::CCSpriteBatchNode *castle ;
   
};

#endif

