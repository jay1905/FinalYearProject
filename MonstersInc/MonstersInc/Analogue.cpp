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

Analogue::Analogue(cocos2d::CCLayer *layer)
{
     CCSize s = CCDirector::sharedDirector()->getWinSize();
 
     solidAnalogMove = CCSprite::create("BigCircle.png");
     solidAnalogMove->setPosition( ccp(100,95) );
   
    solidAnalogMove->setOpacity(50);
     layer->addChild(solidAnalogMove);
    
     solidAnalogShoot=CCSprite::create("BigCircle.png");
     solidAnalogShoot->setPosition(ccp(s.width-100,95));
    solidAnalogShoot->setOpacity(50);
    layer->addChild(solidAnalogShoot);


}
void Analogue::update(){
    
    
}