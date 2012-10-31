//
//  JoyStick.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 31/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "JoyStick.h"


JoyStick::JoyStick(cocos2d::CCLayer* layer){
    
    
    stick=cocos2d::CCSprite::create("SmallCircle.png");
    stick->setPosition(ccp(100, 95));
  
    this->addChild(stick);
    
}
void JoyStick::moveMe(){
    
    
    
   // JoyStick::stick->setPosition(ccp(50, 50));
    //stick->cocos2d::CCNode::setPosition(50, 50);
   //this->setPosition(ccp(50, 50   ));
}