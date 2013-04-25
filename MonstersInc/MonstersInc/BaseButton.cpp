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
#define SQUARE_HEIGHT 143.0f
using namespace cocos2d;
static CCPoint convertCoordinate(CCPoint point){
    return CCDirector::sharedDirector()->convertToGL(point);
}
static bool isPointInSquare(CCPoint point, CCPoint pos){
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
        bg = CCSprite::spriteWithFile("red2.png");
        bg->setPosition(CCPoint(67+position.x,position.y-72));
        bg->setOpacity(50);
        this->addChild(bg,0);
        direction= b2Vec2(0, 0);
        bRet=true;
        hb=new HumanButton(CCPoint(position.x, position.y));
        this->addChild(hb);
        activated=false;
       
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
        if(isPointInSquare(point,position)){
            
            //if(activated ==false){
                isPressed = true;
                //bg->setOpacity(100);
            //    hb->bg->setOpacity(200);
                activated=true;
                
            //}
                   
        }
        else{
            
            activated=false;
            bg->setOpacity(50);
            //hb->bg->setOpacity(40);
            
        }
}
void BaseButton::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
{
    
}
void BaseButton::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )
{
    this->handleLastTouch();
}
void BaseButton::ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent )
{
    this->handleLastTouch();
     //bg->setOpacity(60);
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
