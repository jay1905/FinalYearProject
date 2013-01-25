//
//  WeaponSelectButton.h
//  MonstersInc
//
//  Created by Jaime Aughney on 16/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_WeaponSelectButton_h
#define MonstersInc_WeaponSelectButton_h

#include "cocos2d.h"
#include "Box2D.h"

class WeaponSelectButton:public cocos2d::CCLayer//, cocos2d::CCTargetedTouchDelegate
{
public:
    WeaponSelectButton(cocos2d::CCPoint centre);
    
    
    virtual bool init();  
    cocos2d::CCSprite *bg;
    cocos2d::CCSprite *handGun;
    cocos2d::CCSprite *assaultRifle;
    cocos2d::CCSprite *handGunSelect;
    cocos2d::CCSprite *assaultRifleSelect;
    bool handgun;
    bool assaultrifle;
private:
    
    cocos2d::CCPoint position;
    
    bool isPressed;    
    
    cocos2d::CCArray* allTouchesFromSet(cocos2d::CCSet *touches);
    
    bool handleLastTouch();
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    
};


#endif
