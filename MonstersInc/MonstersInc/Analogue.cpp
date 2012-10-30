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
 
//     solidAnalogMove = CCSprite::create("BigCircle.png");
//     solidAnalogMove->setPosition( ccp(100,95) );
//   
//    solidAnalogMove->setOpacity(50);
//     layer->addChild(solidAnalogMove);
    
     solidAnalogShoot=CCSprite::create("BigCircle.png");
     solidAnalogShoot->setPosition(ccp(s.width-100,95));
    solidAnalogShoot->setOpacity(50);
    layer->addChild(solidAnalogShoot);
    
    smallAnalogMove=CCSprite::create("SmallCircle.png");
    smallAnalogMove->setPosition(ccp(100,95));
    layer->addChild(smallAnalogMove);
    
    
    smallAnalogShoot=CCSprite::create("SmallCircle.png");
    smallAnalogShoot->setPosition(ccp(s.width-100, 95));
    layer->addChild(smallAnalogShoot);
    
    
    
    
    cocos2d::CCMenuItemImage* test = CCMenuItemImage::create("BigCircle.png", "BigCircle.png",layer, menu_selector(Analogue::update) );
  //  test->setPosition(100, 500);
    CCMenu * menu = CCMenu::create(test,NULL);
    menu->setPosition(ccp(300,300));
    layer->addChild(menu);
    //CCMenuItemImage *icecream = CCMenuItemImage::create("icecream.png","icecream2.png",this,  menu_selector(Analogue::update));
    
    
    
   //test->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    CCMenuItemImage *icecream = CCMenuItemImage::create("icecream.png","icecream2.png",layer,  menu_selector(Analogue::update));
    icecream->setPosition( ccp( 100 , 95) );
    //create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(icecream, NULL);
    pMenu->setPosition( ccp(200,100));
    layer->addChild(pMenu, 1);

    
    

}
void Analogue::update(){
    
    smallAnalogMove->setPosition(ccp(400, 100));
    //smallAnalogMove->setPosition(smallAnalogMove.position.x,ite.position.y+1);
}