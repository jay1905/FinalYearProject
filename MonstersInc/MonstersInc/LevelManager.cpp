//
//  LevelManager.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 11/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include <iostream>
#include "LevelManager.h"
#include "SimpleAudioEngine.h"


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
    
	background = CCSprite::create("game_background_Level1.png");
    background->setPosition(CCPointMake(470, 380));
    addChild(background);
    
    castle = new Base(world);
    addChild(castle);
   cocos2d::CCSprite *castleSprite = CCSprite::create("castle.png");
    castleSprite->setPosition(CCPointMake(950, 380));
    castleSprite->setRotation(90);
    castleSprite->setScale(1.6);
    addChild(castleSprite);
    
    
    CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Player.png", 100);
    player= new Player(hello,world);
    player->setPosition(CCPoint(1050, 350));
    addChild(player);
    

    eman=new EnemyManager(world,this);
    analog2 = new Analogue(CCPoint(s.width-100, 95));
    this->addChild(analog2);
    
    world->SetContactListener(&mycontact);

    
    baseButton= new BaseButton(CCPoint(900, 750));
    this->addChild(baseButton);
    
    
    upgradeScn = new UpgradeScreen();
    this->addChild(upgradeScn);
    
    towerMan= new TowerManager();
    firecount=0;
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Final Fantasy VII - Birth of a God [HQ].mp3");
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Final Fantasy VII - Birth of a God [HQ].mp3", true);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(70);
    //SimpleAudioEngine::sharedEngine()->preloadEffect("ie_shot_gun-luminalace-770179786.mp3");
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("M1 Garand Single-SoundBible.com-1941178963.mp3");

    bulletMan = new BulletManager(world);
    addChild(bulletMan);
   
    
    float minSpawn=10;
    float maxSpawn=100;
    int numEnemyOne=2;
    int numEnemyTwo=2;
    int numEnemyThree=2;
    int numEnemyFour=2;
    int numEnemyFive=2;
    std::vector<b2Vec2 *> path1;
    
    
    b2Vec2 * a= new b2Vec2(200/PTM_RATIO, 560/PTM_RATIO);
    path1.push_back( a);
    
    b2Vec2 * b= new b2Vec2(200/PTM_RATIO, 60/PTM_RATIO);
    path1.push_back( b);
    
    b2Vec2 * c= new b2Vec2(770/PTM_RATIO, 60/PTM_RATIO);
    path1.push_back( c);

    b2Vec2 * d= new b2Vec2(770/PTM_RATIO, 475/PTM_RATIO);
    path1.push_back(d);
    
    b2Vec2 * e= new b2Vec2(950/PTM_RATIO, 475/PTM_RATIO);
    path1.push_back(e);

    
    currentLevel=0;/////this needs to be saved

    
    for (int i = 0;i<10;i++){
        Level * l = new Level(minSpawn,maxSpawn,numEnemyOne,numEnemyTwo,numEnemyThree,numEnemyFour,numEnemyFive);
        l->setPath(path1);
        levels.push_back(l);
        
        // minSpawn-=20;
        // maxSpawn-=25;
        numEnemyOne+=2;
        numEnemyTwo+=2;
        numEnemyThree+=2;
        numEnemyFour+=2;
        numEnemyFive+=2;
    }
    eman->setEnemiesToBeAdded( levels[currentLevel]->enemies,levels[currentLevel]->minSpawnTime,levels[currentLevel]->maxSpawnTime);
    eman->setPath(levels[currentLevel]->path);
    eman->towerLevel=true;
    scheduleUpdate();
    
}
void LevelManager::update(float dt){
    int velocityIterations = 8;
    int positionIterations = 1;
    
    
       
    if (upgradeScn->StartLevel==true){
        
        
        if(eman->totalEnemys==0){
            
            
            currentLevel++;
            eman->setEnemiesToBeAdded(levels[currentLevel]->enemies,levels[currentLevel]->minSpawnTime,levels[currentLevel]->maxSpawnTime);
            upgradeScn->show();
            
            
        }
        else{
            
            eman->update();
            eman->movePath();
            towerMan->update(eman->enemys, world, this);
            bulletMan->update();
            if(baseButton->hb->build==true){
                
                baseButton->hb->build=false;
                
                towerMan->createTower(baseButton->hb->buildPoint, this, world);
            }
            if(analog2->getDirection().x!=0&&analog2->getDirection().y!=0){
                
                
                if(firecount>upgradeScn->guns[upgradeScn->GunEquipNum]->fireRate){
                    
                    
                    bulletMan->create(player->returnpos(), analog2->getDirection(),upgradeScn->guns[upgradeScn->GunEquipNum]->damage);
                    //SimpleAudioEngine::sharedEngine()->playEffect("ie_shot_gun-luminalace-770179786.mp3");
                    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("M1 Garand Single-SoundBible.com-1941178963.mp3");
                    firecount=0;
                    
                }
                
                firecount++;
                if(analog2->getDirection().x<0){
                    player->setFlipX(false);
                }
                else{
                    player->setFlipX(true);
                }
            }
            
        }
    }
    
    
    
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
