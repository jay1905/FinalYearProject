

//
//  HelloWorldScene.cpp
//  test
//
//  Created by Jaime Aughney on 18/10/2012.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"
#include "curl.h"


using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 32

enum {
    kTagParentNode = 1,
    jaimesfinished=2,
};
HelloWorld::HelloWorld()
{
    setTouchEnabled( true );
    
    setAccelerometerEnabled( true );
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    this->initPhysics();
    
    
  
    jaime = CCSprite::create("GrassBackground.png");
    jaime->setPosition(CCPointMake(0, 0));
    addChild(jaime);
    
    
    analog = new Analogue(CCPoint(100, 95));
    this->addChild(analog);
    
    analog2 = new Analogue(CCPoint(s.width-100, 95));
    this->addChild(analog2);
    bullets=new CCArray();
    
          


    world->SetContactListener(&mycontact);
    
    eManager = new EnemyManager(world,this);
    savedData = new SaveFileData();

    
    bulletMan = new BulletManager(world);
    addChild(bulletMan);

    
       
    
    float minSpawn=10;
    float maxSpawn=10;
    int numEnemyOne=2;
    int numEnemyTwo=2;
    int numEnemyThree=2;
    int numEnemyFour=2;
    int numEnemyFive=2;
    
    
    
    currentLevel=0;
    
  
    
    
    for (int i = 0;i<100;i++){
        Level * l = new Level(minSpawn,maxSpawn,numEnemyOne,numEnemyTwo,numEnemyThree,numEnemyFour,numEnemyFive);
        levels.push_back(l);
       // minSpawn-=20;
       // maxSpawn-=25;
        numEnemyOne+=2;
        numEnemyTwo+=2;
        numEnemyThree+=2;
        numEnemyFour+=2;
        numEnemyFive+=2;
    }
    eManager->setEnemiesToBeAdded( levels[currentLevel]->enemies,levels[currentLevel]->minSpawnTime,levels[currentLevel]->maxSpawnTime);

    
    CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Player.png", 100);
    player= new Player(hello,world);
    addChild(player);
      
    
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Final Fantasy VII - Birth of a God [HQ].mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Final Fantasy VII - Birth of a God [HQ].mp3", true);
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(70);
    //SimpleAudioEngine::sharedEngine()->preloadEffect("ie_shot_gun-luminalace-770179786.mp3");
     SimpleAudioEngine::sharedEngine()->preloadEffect("M1 Garand Single-SoundBible.com-1941178963.mp3");
    
    label = CCLabelTTF::create("health:", "Marker Felt", 32);
    addChild(label, 1);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( 60, 745));
    
    label4 = CCLabelTTF::create("0", "Marker Felt", 32);
    addChild(label4, 1);
    label4->setColor(ccc3(255,0,55));
    label4->setPosition(ccp( 130, 745));
    
    label2 = CCLabelTTF::create("Coins:", "Marker Felt", 32);
    addChild(label2, 1);
    label2->setColor(ccc3(0,0,255));
    label2->setPosition(ccp( 260, 745));
    
    label3 = CCLabelTTF::create("0", "Marker Felt", 32);
    addChild(label3, 1);
    label3->setColor(ccc3(255,255,55));
    label3->setPosition(ccp(315, 745));
    
    win = CCLabelTTF::create("You Win!", "Marker Felt", 32);
    addChild(win, 1);
    win->setColor(ccc3(255,0,0));
    win->setPosition(ccp(515, 345));
    win->setOpacity(0);
   
    loose = CCLabelTTF::create("You lose!", "Marker Felt", 32);
    addChild(loose, 1);
    loose->setColor(ccc3(255,0,0));
    loose->setPosition(ccp(515, 345));
    loose->setOpacity(0);
   
    win2 = CCLabelTTF::create("press here", "Marker Felt", 32);
    addChild(win2, 1);
    win2->setColor(ccc3(255,0,0));
    win2->setPosition(ccp(500, 320));
    win2->setOpacity(0);

    eManager->coins=savedData->gold;
    upgradeScn=new UpgradeScreen();
    addChild(upgradeScn);
       pCloseItem = CCMenuItemImage::create("quitenabled.bmp","quitenableddown.bmp",this,menu_selector(HelloWorld::exitMainMenu));
        pCloseItem->setPosition(2000,  740);
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition( CCPointZero );
        addChild(pMenu, 1);
    
    buy = CCMenuItemImage::create("buyBtn.bmp","buyBtnDown.bmp",this,menu_selector(HelloWorld::buyGun));
    buy->setPosition( 2000, 100);
    CCMenu* pbuy = CCMenu::create(buy, NULL);
    pbuy->setPosition( CCPointZero );
    addChild(pbuy, 1);
       
    

    scheduleUpdate();
}

HelloWorld::~HelloWorld()
{
    delete world;
    world = NULL;
    
    //delete m_debugDraw;
}
void HelloWorld::exitMainMenu(){
    
    savedData->updateGold(eManager->coins);
    savedData->updateLevel(currentLevel);
    CCScene *pScene1= MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);

    
    
    
}
void HelloWorld::initPhysics()
{
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    
    b2Vec2 gravity;
    gravity.Set(0.0f, 0.0f);
    world = new b2World(gravity);
    // Do we want to let bodies sleep?
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0); // bottom-left corner
    
    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    
    // Define the ground box shape.
    b2EdgeShape groundBox;
    
    // bottom
    
    groundBox.Set(b2Vec2(-1000/PTM_RATIO,-1000/PTM_RATIO), b2Vec2(1000/PTM_RATIO,-1000/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    
    // top
    groundBox.Set(b2Vec2(-1000/PTM_RATIO,1000/PTM_RATIO), b2Vec2(1000/PTM_RATIO,1000/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    
    // left
    groundBox.Set(b2Vec2(-1000/PTM_RATIO,1000/PTM_RATIO), b2Vec2(-1000/PTM_RATIO,-1000/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    
    // right  
    groundBox.Set(b2Vec2(1000/PTM_RATIO,1000/PTM_RATIO), b2Vec2(1000/PTM_RATIO,-1000/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
}

void HelloWorld::draw()
{
    //
    // IMPORTANT:
    // This is only for debug purposes
    // It is recommend to disable it
//    //
//    CCLayer::draw();
//    
//    ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
//    
//    kmGLPushMatrix();
//    
//    world->DrawDebugData();
//    
//    kmGLPopMatrix();
}
void HelloWorld::update(float dt)
{
    //It is recommended that a fixed time step is used with Box2D for stability
    //of the simulation, however, we are using a variable time step here.
    //You need to make an informed choice, the following URL is useful
    //http://gafferongames.com/game-physics/fix-your-timestep/
    CCSize s = CCDirector::sharedDirector()->getWinSize();

    
    int velocityIterations = 8;
    int positionIterations = 1;
    
   if (upgradeScn->StartLevel==true){ 
   
           if( eManager->totalEnemys==0){
               
                   currentLevel++;
                   eManager->setEnemiesToBeAdded(levels[currentLevel]->enemies,levels[currentLevel]->minSpawnTime,levels[currentLevel]->maxSpawnTime);
                   upgradeScn->show();
               
           }


            if(player->health<=0){
                CCPoint centre= CCPoint(s.width/2, s.height/2);
                CCPoint playerpos= CCPoint(player->returnpos().x*PTM_RATIO, player->returnpos().y*PTM_RATIO);
                CCPoint camerapos = ccpSub(centre, this->getPosition());

                    player->health=0;
                    loose->setOpacity(200);
                loose->setPosition(CCPoint(camerapos.x, camerapos.y+50));
                    win2->setOpacity(200);
                win2->setPosition(CCPoint(camerapos.x, camerapos.y));
                
                // pCloseItem->setOpacity(200);
                pCloseItem->setPosition(CCPoint(camerapos.x, camerapos.y-50));
                
            

                
            }
            else{
         
                    pCloseItem->setPosition(CCPoint(2000,100));
                    buy->setPosition( 2550, 100);

                    player->update(analog->getDirection());
                    eManager->moveEnemy(b2Vec2(player->m_pBody->GetPosition().x, player->m_pBody->GetPosition().y));
                    eManager->update();
                    bulletMan->update();
                
                    updateUI();
                
                
                    if(analog2->getDirection().x!=0&&analog2->getDirection().y!=0){
                       
                           
                                if(firecount>upgradeScn->guns[upgradeScn->GunEquipNum]->fireRate){
                                    
                                    
                                    bulletMan->create(player->returnpos(), analog2->getDirection(),upgradeScn->guns[upgradeScn->GunEquipNum]->damage);
                                    //SimpleAudioEngine::sharedEngine()->playEffect("ie_shot_gun-luminalace-770179786.mp3");
                                    SimpleAudioEngine::sharedEngine()->playEffect("M1 Garand Single-SoundBible.com-1941178963.mp3");
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
            char coin[100];
            snprintf(coin, 100, "%d",eManager->coins);
            label3->setString(coin);
            char helth[100];
            snprintf(helth, 100, "%i",player->health);
            label4->setString(helth);

   }
   else{
       
       CCPoint centre= CCPoint(s.width/2, s.height/2);
       CCPoint playerpos= CCPoint(player->returnpos().x*PTM_RATIO, player->returnpos().y*PTM_RATIO);
       CCPoint camerapos = ccpSub(centre, this->getPosition());
       label->setPosition(ccp( 60, 745));
       label2->setPosition(ccp( 260, 745));
       char coin[100];
       snprintf(coin, 100, "%d",eManager->coins);
       label3->setString(coin);
       label3->setPosition(CCPoint(325, 745));
       label4->setPosition(ccp( 130, 745));
       this->setPosition(  upgradeScn->getPosition());
       player->health=100;
       player->reset(b2Vec2(0, 0));
        pCloseItem->setPosition(CCPoint(750,100));
        buy->setPosition( 550, 100);
       
   }
    world->Step(dt, velocityIterations, positionIterations);

    
}
void HelloWorld::buyGun(){
    
    if (upgradeScn->gunSelectedForPurchase!=0) {
        
        if(upgradeScn->guns[upgradeScn->gunSelectedForPurchase]->locked==true){
            if (eManager->coins>=upgradeScn->guns[upgradeScn->gunSelectedForPurchase]->price) {
        
        
                upgradeScn->guns[upgradeScn->gunSelectedForPurchase]->locked=false;
                eManager->coins-=upgradeScn->guns[upgradeScn->gunSelectedForPurchase]->price;
                upgradeScn->locked[upgradeScn->gunSelectedForPurchase]->setPosition(CCPoint(3000, 3000));
                savedData->updateGuns(upgradeScn->gunSelectedForPurchase);
        
            }
        }
    }
    
    
}
void HelloWorld::updateUI(){
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();

    
    CCPoint centre= CCPoint(s.width/2, s.height/2);
    CCPoint playerpos= CCPoint(player->returnpos().x*PTM_RATIO, player->returnpos().y*PTM_RATIO);
    CCPoint camerapos = ccpSub(centre, playerpos);
    
    float gameedgeright=19;
    if(camerapos.x<=gameedgeright){
        
        camerapos.x=gameedgeright;
        
    }
    float gameedgeleft=1000;
    if(camerapos.x>=gameedgeleft){
        
        camerapos.x=gameedgeleft;
        
    }
    float gameedgetop=-239;
    if(camerapos.y<=gameedgetop){
        
        camerapos.y=gameedgetop;
        
    }
    float gameedgebottom=1000;
    if(camerapos.y>=gameedgebottom){
        
        camerapos.y=gameedgebottom;
        
    }
    this->setPosition(camerapos);
    
    
    
    CCPoint an = CCPoint(0,0);
    CCPoint an1= ccpSub(an, camerapos);
    analog->setPosition(an1);
    analog2->setPosition(an1);
    CCPoint l3= CCPoint(325, 745);
    CCPoint lab3 = ccpSub(l3, camerapos);
    label3->setPosition(lab3);
    CCPoint l4= CCPoint(130, 745);
    CCPoint lab4 = ccpSub(l4, camerapos);
    label4->setPosition(lab4);
    CCPoint l1= CCPoint(60, 745);
    CCPoint lab1 = ccpSub(l1, camerapos);
    label->setPosition(lab1);
    
    CCPoint l2= CCPoint(260, 745);
    CCPoint lab2 = ccpSub(l2, camerapos);
    label2->setPosition(lab2);


    
    
}
void HelloWorld::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    
    //human->ccTouchesBegan(pTouches, pEvent);
//    CCArray *allTouches =   this->allTouchesFromSet(pTouches);
//    
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->locationInView();
    
    if (upgradeScn->StartLevel==false){
    upgradeScn->ccTouchesBegan(pTouches, pEvent);
    }
}
void HelloWorld::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    //Add a new body/atlas sprite at the touched location
    CCSetIterator it;
    CCTouch* touch;
    
    for( it = touches->begin(); it != touches->end(); it++) 
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
        location = touch->getLocationInView();
        
        location = CCDirector::sharedDirector()->convertToGL(location);
        
           
        
    }
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new HelloWorld();
   
    
    
    scene->addChild(layer);
    layer->release();
    
    return scene;
}

