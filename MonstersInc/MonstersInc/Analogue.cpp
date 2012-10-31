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
 
     
    cocos2d::CCMenuItemImage* test = CCMenuItemImage::create("BigCircle.png", "BigCircle.png",layer, menu_selector(Analogue::move) );
  //  test->setPosition(100, 500);
    CCMenu * menu = CCMenu::create(test,NULL);
    menu->setPosition(ccp(100,95));
    menu->setOpacity(50);
    layer->addChild(menu);
  
   // layer->addChild(this);
    joy = new JoyStick(layer);
    //this->addChild(joy);

}
void Analogue::move(){
   
    
    this->joy->moveMe();
    //joy->setPosition(ccp(50, 50));
   // joy->stick->setPosition(ccp(50, 50));
}