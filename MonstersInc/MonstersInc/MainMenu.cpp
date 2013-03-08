//
//  MainMenu.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 12/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "MainMenu.h"
#include "HelloWorldScene.h"
#include "Tutorial.h"

#include <CCUserDefault.h>

using namespace cocos2d;

MainMenu::MainMenu(){
    
    init();
    
    
}
void MainMenu::init(){
    
    
    
    pCloseItem = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",this,menu_selector(MainMenu::test));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    addChild(pMenu, 1);

    
    tutorial=CCMenuItemImage::create("Tutorial.png", "Tutorial.png", this, menu_selector(MainMenu::tutorialLevel));
    tutorial->setPosition(CCPoint(100, 500));
    CCMenu *tut=CCMenu::create(tutorial,NULL);
    tut->setPosition(CCPointZero);
    addChild(tut,1);
    
    level1btn=CCMenuItemImage::create("Level1.png", "Level1.png", this, menu_selector(MainMenu::level1));
    level1btn->setPosition(CCPoint(100, 400));
    CCMenu *lev1=CCMenu::create(level1btn,NULL);
    lev1->setPosition(CCPointZero);
    addChild(lev1,1);
    
    
    
    level2btn=CCMenuItemImage::create("Level2.png", "Level2.png", this, menu_selector(MainMenu::level2));
    level2btn->setPosition(CCPoint(100, 300));
    CCMenu *lev2=CCMenu::create(level2btn,NULL);
    lev2->setPosition(CCPointZero);
    addChild(lev2,1);
    
    jaime = CCSprite::create("MonstersInc.jpg");
    jaime->setPosition(CCPointMake(510, 380));
    addChild(jaime);
    
    label = CCLabelTTF::create("health:", "Marker Felt", 32);
    addChild(label, 1);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( 60, 745));
       
}
void MainMenu::test(){
    
    int highScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore");
    char helth[100];
    snprintf(helth, 100, "%i",highScore);
    label->setString(helth);
}
void MainMenu::tutorialLevel(){;
    

    CCScene *pScene = Tutorial::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);    
    
}
void MainMenu::level1(){
    
    CCScene *pScene1= HelloWorld::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);
    
    
}
void MainMenu::level2(){
    
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore", 40);
    CCUserDefault::sharedUserDefault()->setFloatForKey("helth", 98);
    CCUserDefault::sharedUserDefault()->flush();
    
    
}
CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new MainMenu();
    
    
    
    scene->addChild(layer);
    layer->release();
    
    return scene;
}