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
    
    cocos2d::CCSprite *gunwheel=CCSprite::create("HandGuns.png");
    gunwheel->setPosition(CCPointMake(510,600));
    addChild(gunwheel);
    gunBars.push_back(gunwheel);
    gunbarPositions.push_back(CCPointMake(510, 600));
    
    cocos2d::CCSprite *assaultWheel=CCSprite::create("MachineGuns.png");
    assaultWheel->setPosition(CCPointMake(510,550));
    addChild(assaultWheel);
    gunBars.push_back(assaultWheel);
    gunbarPositions.push_back(CCPointMake(510, 550));
    
    cocos2d::CCSprite *shotgunWheel=CCSprite::create("Shotguns.png");
    shotgunWheel->setPosition(CCPointMake(510, 500));
    addChild(shotgunWheel);
    gunBars.push_back(shotgunWheel);
    gunbarPositions.push_back(CCPointMake(510, 500));
    
    
    cocos2d::CCSprite *energyWheel=CCSprite::create("EnergyGuns.png");
    energyWheel->setPosition(CCPointMake(510, 450));
    addChild(energyWheel);
    gunBars.push_back(energyWheel);
    gunbarPositions.push_back(CCPointMake(510, 450));
    
    cocos2d::CCSprite *sniperWheel=CCSprite::create("SniperRifles.png");
    sniperWheel->setPosition(CCPointMake(510, 400));
    addChild(sniperWheel);
    gunBars.push_back(sniperWheel);
    gunbarPositions.push_back(CCPointMake(510, 400));
    
    
    cocos2d::CCSprite *bigWheel=CCSprite::create("BigGuns.png");
    bigWheel->setPosition(CCPointMake(510, 350));
    addChild(bigWheel);
    gunBars.push_back(bigWheel);
    gunbarPositions.push_back(CCPointMake(510, 350));
    
    cocos2d::CCSprite *rpgWheel=CCSprite::create("RPGs.png");
    rpgWheel->setPosition(CCPointMake(510, 300));
    addChild(rpgWheel);
    gunBars.push_back(rpgWheel);
    gunbarPositions.push_back(CCPointMake(510, 300));
    
    int count=150;
    for (int i=0; i<13; i++) {
        
        cocos2d::CCSprite *l=CCSprite::create("highlight-green.png");
        addChild(l);
        l->setPosition(CCPointMake(count, 600));
        locked.push_back(l);
        count+=60;
        
    }
    // l->setPosition(CCPointMake(165, 550));
    //l->setPosition(CCPointMake(225, 550));
    // l->setPosition(CCPointMake(290, 550));
    // l->setPosition(CCPointMake(365, 550));
    //l->setPosition(CCPointMake(435, 550));
    //l->setPosition(CCPointMake(500, 550));
    // l->setPosition(CCPointMake(585, 550));
    //l->setPosition(CCPointMake(660, 550));
    //l->setPosition(CCPointMake(725, 550));
    //l->setPosition(CCPointMake(785, 550));
    //l->setPosition(CCPointMake(850, 550));

     //l->setPosition(CCPointMake(460, 500));
    //l->setPosition(CCPointMake(545, 500));

    //l->setPosition(CCPointMake(350, 450));
    //l->setPosition(CCPointMake(405, 450));
    //l->setPosition(CCPointMake(460, 450));
    //l->setPosition(CCPointMake(515, 450));
    //l->setPosition(CCPointMake(595, 450));
    //l->setPosition(CCPointMake(660, 450));
    
    //l->setPosition(CCPointMake(510, 400));


    count=165;
//    for (int i=0; i<11; i++) {
//        //assault layer
//        cocos2d::CCSprite *l=CCSprite::create("highlight-green.png");
//        addChild(l);
//        l->setPosition(CCPointMake(count, 550));
//        locked.push_back(l);
//        count+=60;
//        
//    }
    
    cocos2d::CCSprite *l=CCSprite::create("highlight-green.png");
    addChild(l);
    l->setPosition(CCPointMake(510, 400));
    
    
    
    count =60;
    for (int i =0; i<37; i++) {
     
        cocos2d::CCSprite *l=CCSprite::create("highlight-red.png");
        addChild(l);
        l->setPosition(CCPointMake(count, 200));
        unlocked.push_back(l);
        count+=20;
        
    }


    
    play = CCMenuItemImage::create("play.bmp","playdown.bmp",this,menu_selector(UpgradeScreen::hide));
    play->setPosition( 250, 100);
    CCMenu* pMenu = CCMenu::create(play, NULL);
    pMenu->setPosition( CCPointZero );
    addChild(pMenu, 1);
   
    quit = CCMenuItemImage::create("quitenabled.bmp","quitenableddown.bmp",this,menu_selector(UpgradeScreen::exit));
    quit->setPosition( 750, 100);
    CCMenu* pQuit = CCMenu::create(quit, NULL);
    pQuit->setPosition( CCPointZero );
    addChild(pQuit, 1);

    StartLevel=false;
    
}
void UpgradeScreen::hide(){
    
    
    background->setPosition(ccp(2000, 380));
    for (int i=0; i<gunBars.size(); i++){
        
        gunBars[i]->setPosition(ccp(2000, 380));
    
    }
    play->setPosition(ccp(2000, 380));
    quit->setPosition(ccp(2000, 380));
    StartLevel=true;
    
}
void UpgradeScreen::show(){
    
    
    
    background->setPosition(ccp(511, 383));
    for (int i=0; i<gunBars.size(); i++){
        
        gunBars[i]->setPosition(gunbarPositions[i]);
        
    }
    play->setPosition(ccp(300, 200));
    quit->setPosition(ccp(800, 200));
    StartLevel=false;
    
}

void UpgradeScreen::exit(){
    
    
    
    CCScene *pScene = MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);    
    
    
}