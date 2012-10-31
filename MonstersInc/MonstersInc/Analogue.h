//
//  Analogue.h
//  MonstersInc
//
//  Created by Jaime Aughney on 25/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Analogue_h
#define MonstersInc_Analogue_h

#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"
#include "JoyStick.h"

class Analogue:cocos2d::CCLayer
{
public:
    Analogue(cocos2d::CCLayer *layer);
    
    void move();
   //private:
    cocos2d::CCSprite* solidAnalogMove;
    cocos2d::CCSprite* solidAnalogShoot;
    cocos2d::CCSprite* smallAnalogMove;
    cocos2d::CCSprite* smallAnalogShoot;
    JoyStick *joy;
   // cocos2d::CCMenuItemImage * test;
};
#endif
