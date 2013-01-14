//
//  BaseButton.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 14/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "BaseButton.h"
#define JOYSTICK_OFFSET_X 5.0f
#define JOYSTICK_OFFSET_Y 5.0f
#define JOYSTICK_RADIUS 96.0f
#define THUMB_RADIUS 70.0f
#define SQUARE_WIDTH 134.0f
#define SQUARE_HEIGHT 404.0f
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
BaseButton::BaseButton(CCPoint pos)
{
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    position=pos;
    init();
}
bool BaseButton::init()
{
    bool bRet = false;
    do 
    { 
        CC_BREAK_IF(!CCLayer::init());
        this->setTouchEnabled(true);
        velocity = CCPointZero;         
        bg = CCSprite::spriteWithFile("red.png");
        bg->setPosition(CCPoint(67+position.x,position.y-202));
        bg->setOpacity(60);
        this->addChild(bg,0);
        thumb = CCSprite::spriteWithFile("SmallCircle.png");
        thumb->setPosition(position);
        thumb->setOpacity(60);
        this->addChild(thumb,1);
        direction= b2Vec2(0, 0);
        bRet=true;
        
    }while(0);
    return bRet;
}

void BaseButton::resetJoystick()
{
}
bool BaseButton::handleLastTouch()
{
    bool wasPressed = isPressed;
    if(wasPressed){
        this->resetJoystick();
        isPressed = false;
    }
    return (wasPressed ? true : false);
}
void BaseButton::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    CCArray *allTouches =   this->allTouchesFromSet(pTouches);
      
        CCTouch *touch = (CCTouch*)pTouches->anyObject();
        CCPoint point = touch->locationInView();
        point = convertCoordinate(point);
        if(isPointInSquare(point,position,JOYSTICK_RADIUS)){
            isPressed = true;
             bg->setOpacity(0);
            // thumb->setOpacity(50);
         
        
    }
}
void BaseButton::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
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
void BaseButton::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )
{
    this->handleLastTouch();
}
void BaseButton::ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent )
{
    this->handleLastTouch();
     bg->setOpacity(60);
    // thumb->setOpacity(0);
}
CCArray* BaseButton::allTouchesFromSet(CCSet *touches)
{
    CCArray *arr = new CCArray;
    CCSetIterator it;
	for( it = touches->begin(); it != touches->end(); it++) 
    {
        arr->addObject((CCTouch *)*it);
    }
    return arr;
}
