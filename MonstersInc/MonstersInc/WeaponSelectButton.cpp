//
//  WeaponSelectButton.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 16/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "WeaponSelectButton.h"
#define JOYSTICK_OFFSET_X 5.0f
#define JOYSTICK_OFFSET_Y 5.0f
#define JOYSTICK_RADIUS 96.0f
#define THUMB_RADIUS 70.0f
#define SQUARE_WIDTH 200.0f
#define SQUARE_HEIGHT 50.0f
using namespace cocos2d;
static CCPoint convertCoordinate(CCPoint point){
    return CCDirector::sharedDirector()->convertToGL(point);
}
static bool isPointInSquare(CCPoint point, CCPoint pos, float radius){
    if(point.x>pos.x&&point.x<pos.x+(SQUARE_WIDTH)){
        
        
        if(point.y<pos.y&&point.y>pos.y-(SQUARE_HEIGHT)){
            
            return true;
        }
        
    }
    return false;
}
WeaponSelectButton::WeaponSelectButton(CCPoint pos)
{
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    position=pos;
    init();
}
bool WeaponSelectButton::init()
{
    bool bRet = false;
    do 
    { 
        CC_BREAK_IF(!CCLayer::init());
        this->setTouchEnabled(true);
        bg = CCSprite::spriteWithFile("weaponBackground.png");
        bg->setPosition(CCPoint(position.x+(SQUARE_WIDTH /2),position.y-(SQUARE_HEIGHT/2)));
        bg->setOpacity(50);
        this->addChild(bg,0);
        handGun=CCSprite::spriteWithFile("handGun.png");
        handGun->setPosition(CCPoint(position.x+25, position.y-25));
       // handGun->setOpacity(100);
        this->addChild(handGun,0);
        assaultRifle=CCSprite::spriteWithFile("assaultRifle.png");
        assaultRifle->setPosition(CCPoint(position.x+70, position.y-25));
        this->addChild(assaultRifle);
       
        bRet=true;
        
    }while(0);
    return bRet;
}
bool WeaponSelectButton::handleLastTouch()
{
    bool wasPressed = isPressed;
    if(wasPressed){
       
        isPressed = false;
    }
    return (wasPressed ? true : false);
}
void WeaponSelectButton::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    CCArray *allTouches =   this->allTouchesFromSet(pTouches);
    
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->locationInView();
    point = convertCoordinate(point);
    if(isPointInSquare(point,position,JOYSTICK_RADIUS)){
        isPressed = true;
        bg->setOpacity(100);
        
        
    }
}
void WeaponSelectButton::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
{
    if(isPressed){
        CCArray *allTouches =   this->allTouchesFromSet(pTouches);
        if (allTouches->count() > 1)
        {
            CCTouch *fingerOne = static_cast<CCTouch* >(allTouches->objectAtIndex(0));
            CCTouch *fingerTwo = static_cast<CCTouch* >(allTouches->objectAtIndex(1));
            CCPoint  pointOne =fingerOne->locationInView();            
            CCPoint  pointTwo =fingerTwo->locationInView(); 
            pointOne= convertCoordinate(pointOne);
            pointTwo= convertCoordinate(pointTwo);
            if(isPointInSquare(pointOne,position,JOYSTICK_RADIUS)){
                isPressed = true;
            }
            if(isPointInSquare(pointTwo,position,JOYSTICK_RADIUS)){
                isPressed = true;
                
            }
        }
        else{
            CCTouch *touch = (CCTouch*)pTouches->anyObject();
            CCPoint point = touch->locationInView();
            point = convertCoordinate(point);
            if(isPointInSquare(point,position,JOYSTICK_RADIUS)){
                isPressed = true;
                
            }
            if(isPointInSquare(point,position,JOYSTICK_RADIUS)){
                isPressed = true;
                
            }
        }
    }
}
void WeaponSelectButton::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )
{
    this->handleLastTouch();
}
void WeaponSelectButton::ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent )
{
    this->handleLastTouch();
}
CCArray* WeaponSelectButton::allTouchesFromSet(CCSet *touches)
{
    CCArray *arr = new CCArray;
    CCSetIterator it;
	for( it = touches->begin(); it != touches->end(); it++) 
    {
        arr->addObject((CCTouch *)*it);
    }
    return arr;
}
