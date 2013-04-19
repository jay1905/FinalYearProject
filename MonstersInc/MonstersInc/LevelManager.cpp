//
//  LevelManager.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 11/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include <iostream>
#include "LevelManager.h"



using namespace cocos2d;

#define PTM_RATIO 32

LevelManager::LevelManager(){
    
    
	
    this->initPhysics();
    this->initialize();
    
    
}
void LevelManager::initialize(){
    
 	setTouchEnabled( true );
    
    setAccelerometerEnabled( true );
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
	jaime = CCSprite::create("game_background.png");
    jaime->setPosition(CCPointMake(500, 380));
    addChild(jaime);
    
    castle = new Base(world);
    addChild(castle);
    
    
    CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Player.png", 100);
    player= new Player(hello,world);
    addChild(player);
    
      
    
    analog = new Analogue(CCPoint(100, 95));
    this->addChild(analog);
    
    analog2 = new Analogue(CCPoint(s.width-100, 95));
    this->addChild(analog2);
    
    upgradeScn = new UpgradeScreen();
    this->addChild(upgradeScn);
    
    float minSpawn=2.0;
    float maxSpawn=5.0;
    float numEnemyOne=10;
    float numEnemyTwo=0;
    
    
    
    currentLevel=0;/////this needs to be saved
    
    eman = new EnemyManager(world, this);
    
    
//    for (int i = 0;i<10;i++){
//        Level * l = new Level(minSpawn,maxSpawn,numEnemyOne,numEnemyTwo);
//        levels.push_back(l);
//        minSpawn-=0.2;
//        maxSpawn-=0.2;
//        numEnemyOne+=5;
//        numEnemyTwo+=5;
//    }
   // eman->setEnemiesToBeAdded(levels[currentLevel]->enemies,levels[currentLevel]->minSpawnTime,levels[currentLevel]->maxSpawnTime);
       
    scheduleUpdate();
    
}
void LevelManager::update(float dt){
    int velocityIterations = 8;
    int positionIterations = 1;
    
    
       
//    if (upgradeScn->StartLevel==true){
//        
//        
//        if(levels[currentLevel]->finishedLevel==true){
//            
//            currentLevel++;
//          //  eman->setEnemiesToBeAdded(levels[currentLevel]->enemies,levels[currentLevel]->minSpawnTime,levels[currentLevel]->maxSpawnTime);
//            upgradeScn->StartLevel=false;
//            
//        }
//        else{
//            
//            eman->update();
//            
//            player->update(analog->getDirection());
//            
//        }
//    }
    
      
    
    world->Step(dt, velocityIterations, positionIterations);
    
    
}
void LevelManager::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    
   // human->ccTouchesBegan(pTouches, pEvent);
    
}
void LevelManager::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    //Add a new body/atlas sprite at the touched location
    CCSetIterator it;
    CCTouch* touch;
    
    for( it = touches->begin(); it != touches->end(); it++) 
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
       // location = touch->getLocationInView();
        
       // location = CCDirector::sharedDirector()->convertToGL(location);
        
        //  addNewSpriteAtPosition( location );
        // jaime->setPosition(CCPointMake(300, 300));
        
        
    }
}

void LevelManager::exitMainMenu(){
    
    //savedData->updateGold(eManager->coins);
    CCScene *pScene1= MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);
    
    
    
    
}
void LevelManager::initPhysics()
{
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    b2Vec2 gravity;
    gravity.Set(0.0f, 0.0f);
    world = new b2World(gravity);
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0); 
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2EdgeShape groundBox;
    // bottom
    groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    // top
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    // left
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);
    // right  
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
}


CCScene* LevelManager::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new LevelManager();
    
    
    
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
