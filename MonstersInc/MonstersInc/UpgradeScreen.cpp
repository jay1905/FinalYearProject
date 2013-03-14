//
//  UpgradeScreen.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 28/02/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "UpgradeScreen.h"




using namespace cocos2d;

UpgradeScreen::UpgradeScreen(){
    
    background = CCSprite::create("UpgradeMenu.png");
    background->setPosition(CCPointMake(510, 380));
    addChild(background);
    
    gunwheel=CCSprite::create("HandGuns.png");
    gunwheel->setPosition(CCPointMake(510, 380));
    addChild(gunwheel);
    
    //test.addControlPoint(CCPoint(10, 10));
    //test.addControlPoint(CCPoint(12, 12));
    
}

CCScene* UpgradeScreen::scene()
{
    CCScene *scene = CCScene::create();
    CCLayer* layer = new UpgradeScreen();
    scene->addChild(layer);
    layer->release();
    return scene;
}