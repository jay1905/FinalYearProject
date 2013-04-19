//
//  UpgradeScreen.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 28/02/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "UpgradeScreen.h"
#include "MainMenu.h"



using namespace cocos2d;

UpgradeScreen::UpgradeScreen(){
    
    background = CCSprite::create("UpgradeMenu.png");
    background->setPosition(CCPointMake(511, 383));
    addChild(background);
    
    gunwheel=CCSprite::create("HandGuns.png");
    gunwheel->setPosition(CCPointMake(510, 380));
    addChild(gunwheel);
    
    play = CCMenuItemImage::create("play.bmp","playdown.bmp",this,menu_selector(UpgradeScreen::hide));
    play->setPosition( 300, 200);
    CCMenu* pMenu = CCMenu::create(play, NULL);
    pMenu->setPosition( CCPointZero );
    addChild(pMenu, 1);
   
    quit = CCMenuItemImage::create("quitenabled.bmp","quitenableddown.bmp",this,menu_selector(UpgradeScreen::exit));
    quit->setPosition( 800, 200);
    CCMenu* pQuit = CCMenu::create(quit, NULL);
    pQuit->setPosition( CCPointZero );
    addChild(pQuit, 1);

    StartLevel=false;
    
}
void UpgradeScreen::hide(){
    
    
    background->setPosition(ccp(2000, 380));
    gunwheel->setPosition(ccp(2000, 380));
    play->setPosition(ccp(2000, 380));
    quit->setPosition(ccp(2000, 380));
    StartLevel=true;
    
}
void UpgradeScreen::show(){
    
    
    
    background->setPosition(ccp(511, 383));
    gunwheel->setPosition(ccp(510, 380));
    play->setPosition(ccp(300, 200));
    quit->setPosition(ccp(800, 200));
    StartLevel=false;
    
}

void UpgradeScreen::exit(){
    
    
    
    CCScene *pScene = MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);    
    
    
}