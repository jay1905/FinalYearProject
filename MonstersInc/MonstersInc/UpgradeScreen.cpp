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

#define SQUARE_WIDTH 60.0f
#define SQUARE_HEIGHT 40.0f

using namespace cocos2d;


static bool isPointInSquare(CCPoint point, b2Vec2 pos){
  
    if(point.x>pos.x-(SQUARE_WIDTH/2)&&point.x<pos.x+(SQUARE_WIDTH/2)){
        
        
        if(point.y>pos.y-(SQUARE_HEIGHT/2)&&point.y<pos.y+(SQUARE_HEIGHT/2)){
            
            return true;
        }
        
    }
    return false;
}
UpgradeScreen::UpgradeScreen(){
    
    background = CCSprite::create("UpgradeMenu.png");
    background->setPosition(CCPointMake(511, 383));
    addChild(background);
    
    cocos2d::CCSprite *gunwheel=CCSprite::create("Hand2Guns.png");
    gunwheel->setPosition(CCPointMake(510,600));
    addChild(gunwheel);
    gunBars.push_back(gunwheel);
    gunbarPositions.push_back(CCPointMake(510, 600));
    
    
    
    
    cocos2d::CCSprite *assaultWheel=CCSprite::create("MachineGuns.png");
    assaultWheel->setPosition(CCPointMake(510,550));
    addChild(assaultWheel);
    gunBars.push_back(assaultWheel);
    gunbarPositions.push_back(CCPointMake(510, 550));
       
    
       
    cocos2d::CCSprite *sniperWheel=CCSprite::create("SniperRifles.png");
    sniperWheel->setPosition(CCPointMake(510, 500));
    addChild(sniperWheel);
    gunBars.push_back(sniperWheel);
    gunbarPositions.push_back(CCPointMake(510, 500));
    
    
    
    
    
    cocos2d::CCSprite *bigWheel=CCSprite::create("BigGuns.png");
    bigWheel->setPosition(CCPointMake(510, 450));
    addChild(bigWheel);
    gunBars.push_back(bigWheel);
    gunbarPositions.push_back(CCPointMake(510, 450));
    
   
    
    int count=150;
    for (int i=0; i<13; i++) {
        lockedUnlockedPositions.push_back(CCPoint(count, 600));
        count+=60;
    }
    lockedUnlockedPositions.push_back(CCPointMake(165, 550));
    lockedUnlockedPositions.push_back(CCPointMake(225, 550));
    lockedUnlockedPositions.push_back(CCPointMake(290, 550));
    lockedUnlockedPositions.push_back(CCPointMake(365, 550));
    lockedUnlockedPositions.push_back(CCPointMake(435, 550));
    lockedUnlockedPositions.push_back(CCPointMake(500, 550));
    lockedUnlockedPositions.push_back(CCPointMake(585, 550));
    lockedUnlockedPositions.push_back(CCPointMake(660, 550));
    lockedUnlockedPositions.push_back(CCPointMake(725, 550));
    lockedUnlockedPositions.push_back(CCPointMake(785, 550));
    lockedUnlockedPositions.push_back(CCPointMake(850, 550));
    lockedUnlockedPositions.push_back(CCPointMake(510, 500));
    lockedUnlockedPositions.push_back(CCPointMake(450, 450));
    lockedUnlockedPositions.push_back(CCPointMake(555, 450));

    for (int i =0; i<27; i++) {
     
        cocos2d::CCSprite *l=CCSprite::create("highlight-red.png");
        addChild(l);
        l->setPosition(lockedUnlockedPositions[i]);
        locked.push_back(l);
        count+=20;
        
    }
    int d=12;
    int fr=20;
    int price=50;
    for (int i=0; i<13; i++) {
        Gun * g = new Gun(d,fr,price,"Handgun");
        guns.push_back(g);
        damage+=2;
        price +=50;
        
    }
     d=6;
     fr=14;
     price=60;
    for (int i=0; i<11; i++) {
        Gun * g = new Gun(d,fr,price,"MachineGun");
        guns.push_back(g);
        damage+=2;
        price +=60;
        
    }
    Gun* sniper = new Gun(65,25,1200,"Sniper Rifle");
    guns.push_back(sniper);

    Gun* mini = new Gun(20,8,2500,"Mini Gun");
    guns.push_back(mini);

    Gun* saw = new Gun(25,14,2000,"Saw");
    guns.push_back(saw);
    
    
    guns[0]->locked=false;
    locked[0]->setPosition(CCPoint(3000, 3000));
    
    GunEquipNum=0;
    equipedGun=CCSprite::create("highlight-green.png");
    equipedGun->setPosition(lockedUnlockedPositions[0]);
    addChild(equipedGun);
    
    play = CCMenuItemImage::create("play.bmp","playdown.bmp",this,menu_selector(UpgradeScreen::hide));
    play->setPosition( 250, 100);
    CCMenu* pMenu = CCMenu::create(play, NULL);
    pMenu->setPosition( CCPointZero );
    addChild(pMenu, 1);
    
    name = CCLabelTTF::create("Name:", "Marker Felt", 32);
    addChild(name, 1);
    name->setColor(ccc3(0,0,255));
    name->setPosition(ccp( 450, 350));
    
    damage = CCLabelTTF::create("damage:", "Marker Felt", 32);
    addChild(damage, 1);
    damage->setColor(ccc3(0,0,255));
    damage->setPosition(ccp( 450, 300));
    
    firerate = CCLabelTTF::create("firerate:", "Marker Felt", 32);
    addChild(firerate, 1);
    firerate->setColor(ccc3(0,0,255));
    firerate->setPosition(ccp( 450, 250));
    
    cost = CCLabelTTF::create("cost:", "Marker Felt", 32);
    addChild(cost, 1);
    cost->setColor(ccc3(0,0,255));
    cost->setPosition(ccp( 450, 200));
    
    
    
    StartLevel=false;
    
}
void UpgradeScreen::hide(){
    
    
    background->setPosition(ccp(2000, 380));
    for (int i=0; i<gunBars.size(); i++){
        
        gunBars[i]->setPosition(ccp(2000, 380));
    
    }
    for (int i =0; i<locked.size(); i++) {
        
        locked[i]->setPosition(CCPoint(3000, 3000));
        
    }
    equipedGun->setPosition(CCPoint(300, 3000));
    play->setPosition(ccp(2000, 380));
    name->setPosition(ccp(2000, 380));
    damage->setPosition(ccp(2000, 380));
    firerate->setPosition(ccp(2000, 380));
    cost->setPosition(ccp(2000, 380));
    StartLevel=true;
    
}
void UpgradeScreen::show(){
    
    
    
    background->setPosition(ccp(511, 383));
    for (int i=0; i<gunBars.size(); i++){
        
        gunBars[i]->setPosition(gunbarPositions[i]);
        
    }
    for (int i =0; i<locked.size(); i++) {
        if(guns[i]->locked==true){
            locked[i]->setPosition(lockedUnlockedPositions[i]);
        }
    }
    equipedGun->setPosition(lockedUnlockedPositions[GunEquipNum]);
    play->setPosition(ccp(450, 100));
    name->setPosition(ccp(450, 350));
    damage->setPosition(ccp(450, 300));
    firerate->setPosition(ccp(450, 250));
    cost->setPosition(ccp(450, 200));
    StartLevel=false;
    
}
void UpgradeScreen::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    
    //human->ccTouchesBegan(pTouches, pEvent);
    //    CCArray *allTouches =   this->allTouchesFromSet(pTouches);
    //
    //    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    //    CCPoint point = touch->locationInView();
    
}
void UpgradeScreen::exit(){
    
    
    
    CCScene *pScene = MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);    
    
    
}