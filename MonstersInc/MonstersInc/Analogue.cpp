//
//  Analogue.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 25/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Analogue.h"


#define JOYSTICK_OFFSET_X 5.0f
#define JOYSTICK_OFFSET_Y 5.0f

#define JOYSTICK_RADIUS 96.0f

#define THUMB_RADIUS 70.0f


using namespace cocos2d;

static CCPoint convertCoordinate(CCPoint point){
    return CCDirector::sharedDirector()->convertToGL(point);
}
static bool isPointInCircle(CCPoint point, CCPoint center, float radius){
    float dx = (point.x - center.x);
    float dy = (point.y - center.y);
    return (radius >= sqrt((dx*dx)+(dy*dy)));
}
Analogue::Analogue(CCPoint centre)
{
     CCSize s = CCDirector::sharedDirector()->getWinSize();
    kCenter=centre;
    init();
}
bool Analogue::init()
{
    bool bRet = false;
    do 
    { 
        CC_BREAK_IF(!CCLayer::init());
        this->setTouchEnabled(true);
        velocity = CCPointZero;         
        CCSprite *bg = CCSprite::spriteWithFile("BigCircle.png");
        bg->setPosition(kCenter);
        bg->setOpacity(50);
        this->addChild(bg,0);
        thumb = CCSprite::spriteWithFile("SmallCircle.png");
        thumb->setPosition(kCenter);
        thumb->setOpacity(50);
        this->addChild(thumb,1);
        bRet=true;
        
    }while(0);
    return bRet;
}
void Analogue::updateVelocity(CCPoint point)
{
    // calculate Angle and length
    float dx = point.x - kCenter.x;
    float dy = point.y - kCenter.y;
    float distance = sqrt(dx*dx + dy*dy);
    float angle = atan2(dy,dx); // in radians
    if(distance > JOYSTICK_RADIUS){
        dx = cos(angle) * JOYSTICK_RADIUS;
        dy = sin(angle) * JOYSTICK_RADIUS;
    }
    velocity = CCPointMake(dx/JOYSTICK_RADIUS, dy/JOYSTICK_RADIUS);
    if(distance>THUMB_RADIUS)
    {
        point.x = kCenter.x + cos(angle) * THUMB_RADIUS;
        point.y = kCenter.y + sin(angle) * THUMB_RADIUS;
    }
    direction= CCPoint(kCenter.x-point.x, kCenter.y-point.y);
    thumb->setPosition(point);
}

void Analogue::resetJoystick()
{
    this->updateVelocity(kCenter);
}

bool Analogue::handleLastTouch()
{
    bool wasPressed = isPressed;
    if(wasPressed){
        this->resetJoystick();
        isPressed = false;
    }
    return (wasPressed ? true : false);
}

void Analogue::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->locationInView();
    point = convertCoordinate(point);
    
    if(isPointInCircle(point,kCenter,JOYSTICK_RADIUS)){
        isPressed = true;
        this->updateVelocity(point);
    }
}

void Analogue::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
{
    if(isPressed){
        CCTouch *touch = (CCTouch*)pTouches->anyObject();
        CCPoint point = touch->locationInView();
        point = convertCoordinate(point);
        this->updateVelocity(point);
    }
}

void Analogue::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )
{
    this->handleLastTouch();
}

void Analogue::ccTouchesEnded( CCSet *pTouches, CCEvent *pEvent )
{
    this->handleLastTouch();
}


