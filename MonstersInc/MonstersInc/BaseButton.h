//
//  BaseButton.h
//  MonstersInc
//
//  Created by Jaime Aughney on 14/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_BaseButton_h
#define MonstersInc_BaseButton_h

#include "cocos2d.h"
#include "Box2D.h"
#include "HumanButton.h"

class BaseButton:public cocos2d::CCLayer
{
public:
    BaseButton(cocos2d::CCPoint centre);
    
    
    virtual bool init();  
    cocos2d::CCPoint getVelocity(){return velocity;}
    
    b2Vec2 getDirection(){return -direction;}
    cocos2d::CCSprite *bg;
    cocos2d::CCSprite *thumb;
    HumanButton* hb;
    bool castleTouch;
    
private:
    
    cocos2d::CCPoint position;
    
    bool isPressed;
    bool activated;
    
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
