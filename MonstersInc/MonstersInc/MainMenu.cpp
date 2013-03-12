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
    
    world = new b2World(b2Vec2_zero);

    
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
    
    newGame=CCMenuItemImage::create("HandGunSelect.png", "HandGunSelect.png", this, menu_selector(MainMenu::newPlayer));
    newGame->setPosition(CCPoint(400, 500));
    CCMenu *newFile=CCMenu::create(newGame,NULL);
    newFile->setPosition(CCPointZero);
    addChild(newFile,1);
    
   
        
    
    pNormal9SpriteBg= cocos2d::extension::CCScale9Sprite::create("assaultRifleSelect.png");
    m_pEditName = cocos2d::extension::CCEditBox::create(CCSize(250, 30), pNormal9SpriteBg);
    m_pEditName->setPosition(ccp(1400, 200));
    m_pEditName->setFontColor(ccBLUE);
    m_pEditName->setPlaceHolder("Name:");
    m_pEditName->setMaxLength(8);
    addChild(m_pEditName);
    
    enter=CCMenuItemImage::create("blocks.png", "blocks.png", this, menu_selector(MainMenu::enterPlayer));
    enter->setPosition(CCPoint(1400, 400));
    CCMenu *enterB=CCMenu::create(enter,NULL);
    enterB->setPosition(CCPointZero);
    addChild(enterB,1);
    
    
    
   
  
    savedData= new SaveFileData();
    
    scheduleUpdate();
       
}
void MainMenu::enterPlayer(){
    
    
    level2btn->setPosition(CCPoint(100, 300));
    level1btn->setPosition(CCPoint(100, 400));
    tutorial->setPosition(CCPoint(100, 500));
    m_pEditName->setPosition(ccp(1400, 200));
    enter->setPosition(CCPoint(1400, 400));
    newGame->setPosition(CCPoint(400, 500));
    
    savedData->newPlayer(m_pEditName->getText());
    
    
    
    
}
void MainMenu::newPlayer(){
    level2btn->setPosition(CCPoint(1400, 400));
    level1btn->setPosition(CCPoint(1400, 400));
    tutorial->setPosition(CCPoint(1400, 400));
    m_pEditName->setPosition(ccp(400, 200));
    enter->setPosition(CCPoint(400, 400));
    newGame->setPosition(CCPoint(1400, 500));
    
 
}
void MainMenu::update(float dt){
    int velocityIterations = 8;
    int positionIterations = 1;
    
    
    const char * c = savedData->name.c_str();
    label->setString(c);
    
    
    
    world->Step(dt, velocityIterations, positionIterations);

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