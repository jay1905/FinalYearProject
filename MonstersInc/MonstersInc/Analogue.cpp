//
//  Analogue.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 25/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Analogue.h"


USING_NS_CC;

using namespace cocos2d;

Analogue::Analogue(CCPoint point)
{
     CCSize s = CCDirector::sharedDirector()->getWinSize();
 
    solidAnalog= CCSprite::create("SmallCircle.png");
    solidAnalog->setPosition(point);
    addChild(solidAnalog);
    
    bigAnalog = CCSprite::create("BigCircle.png");
    bigAnalog->setPosition(point);
    bigAnalog->setOpacity(50);
    addChild(bigAnalog);
    

//    this->setTouchEnabled(true);

}
void Analogue::move(CCSet* touches){
   
    
 
    solidAnalog->setPosition(CCPoint(location.x, location.y));

           
}
void Analogue::onEnter(){
    //CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
    CCDirector::sharedDirector()->getTouchDispatcher();
    CCNode::onEnter();
}

void Analogue::onExit(){
    CCDirector::sharedDirector()->end();
    //CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
}
bool Analogue::ccTouchBegan(CCTouch* touch, CCEvent* event){
    /* if you return true then ccTouchEnded will called */
    /* if you return false then ccTouchEnded will not be called, and the event will go the parent layer */
    CCPoint point = touch->locationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    solidAnalog->setPosition(CCPoint(point.x, point.y));

    return CCRect::CCRectContainsPoint(rect(), point);
}
void Analogue::ccTouchMoved(CCTouch* touch, CCEvent* event){
    //CCLOG(“Fish ccTouchMoved”);
    /* do your stuff here */
}
void Analogue::ccTouchEnded(CCTouch* touch, CCEvent* event){
    //CCLOG(“Fish ccTouchEnded”);
    /* do your stuff here */
}
CCRect Analogue::rect(){
    CCRect c = CCRectMake( bigAnalog->getPosition().x,  bigAnalog->getPosition().y ,  bigAnalog->getTextureRect().size.width * bigAnalog->getScaleX() ,   bigAnalog->getTextureRect().size.height * bigAnalog->getScaleY());
                      
}



