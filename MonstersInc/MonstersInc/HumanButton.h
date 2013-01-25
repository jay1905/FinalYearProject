//
//  HumanButton.h
//  MonstersInc
//
//  Created by Jaime Aughney on 15/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_HumanButton_h
#define MonstersInc_HumanButton_h
#include "cocos2d.h"
#include "Box2D.h"

class HumanButton:public cocos2d::CCLayer//, cocos2d::CCTargetedTouchDelegate
{
public:
    HumanButton(cocos2d::CCPoint centre);
    
    
    virtual bool init();  
    cocos2d::CCPoint getVelocity(){return velocity;}
    
    b2Vec2 getDirection(){return -direction;}
    cocos2d::CCSprite *bg;
    cocos2d::CCSprite *thumb;
    bool activated;
    bool build;
    bool buttontouch;
    
    b2Vec2 buildPoint;
private:
    
    cocos2d::CCPoint position;
    
    bool isPressed;
    
    cocos2d::CCPoint velocity;
    b2Vec2 direction;
    
    
    cocos2d::CCArray* allTouchesFromSet(cocos2d::CCSet *touches);
    
    
    void resetJoystick();
    bool handleLastTouch();
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    
};

#endif


