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

class Analogue:public cocos2d::CCLayer, cocos2d::CCTargetedTouchDelegate
{
public:
    Analogue(cocos2d::CCPoint point);

    cocos2d::CCSprite* solidAnalog;
    cocos2d::CCSprite* bigAnalog;
    void move(cocos2d::CCSet* touches);
    cocos2d::CCPoint location;
    
    
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    bool containsTouchLocation(cocos2d::CCTouch* touch);
    cocos2d::CCRect rect();
   };
#endif