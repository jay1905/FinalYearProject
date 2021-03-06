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

class Analogue:public cocos2d::CCLayer//, cocos2d::CCTargetedTouchDelegate
{
public:
    Analogue(cocos2d::CCPoint centre);

    
    virtual bool init();  
    cocos2d::CCPoint getVelocity(){return velocity;}
   
    b2Vec2 getDirection(){return -direction;}
    cocos2d::CCSprite *bg;
    cocos2d::CCSprite *thumb;
    
private:
    
    cocos2d::CCPoint kCenter;
   
    bool isPressed;
    
    cocos2d::CCPoint velocity;
    b2Vec2 direction;
    
    
    cocos2d::CCArray* allTouchesFromSet(cocos2d::CCSet *touches);
    
    void updateVelocity(cocos2d::CCPoint point);
    void resetJoystick();
    bool handleLastTouch();
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    
   };
#endif