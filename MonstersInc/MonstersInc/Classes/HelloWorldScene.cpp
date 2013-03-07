

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
    
    CCSpriteBatchNode *parent = CCSpriteBatchNode::create("blocks.png", 100);
    m_pSpriteTexture = parent->getTexture();
    
    addChild(parent, 0, kTagParentNode);
  
    jaime = CCSprite::create("game_background.png");
    jaime->setPosition(CCPointMake(500, 380));
    addChild(jaime);
    
    
    analog = new Analogue(CCPoint(100, 95));
    this->addChild(analog);
    
    analog2 = new Analogue(CCPoint(s.width-100, 95));
    this->addChild(analog2);
    bullets=new CCArray();
    gun =new Gun();
    assaultgun= new AssaultRifle();
    firecount=20;
    enemyCount=0;

    wep= new WeaponSelectButton(CCPoint(500, 750));
    addChild(wep);

    world->SetContactListener(&mycontact);
    
    eManager = new EnemyManager(world,this);
    eManager->addEnemy(b2Vec2(200, 300));

    
    bulletMan = new BulletManager(world);
    addChild(bulletMan);
    
    
    
    human= new Human(world, b2Vec2(200, 200), 10, b2Vec2(19, 23),this);
    addChild(human);
    
  
    
    

///////////////////////////////////////////////////////////////////animation
//    cocos2d::CCAnimation * anim = CCAnimation::animation();
//    anim->addSpriteFrameWithFileName("GreenZombie1.png");
//    anim->addSpriteFrameWithFileName("GreenZombie2.png");
//    anim->addSpriteFrameWithFileName("GreenZombie3.png");
//    anim->addSpriteFrameWithFileName("GreenZombie4.png");
//    anim->setDelayPerUnit(.5f);
//    CCAnimate *theAnim = cocos2d::CCAnimate::actionWithAnimation(anim);// CCAnimate::a  actionWithDuration(1.8f,anim,true); 
//    CCAction *jumpAct = CCRepeatForever::create(theAnim);
//    cocos2d::CCSprite*  pSprite=CCSprite::spriteWithFile("GreenZombie1.png");//  createWithSpriteFrame((CCSpriteFrame*) anim->getFrames()->objectAtIndex(0));
//    pSprite->setPosition(CCPoint(500, 300));
//    this->addChild(pSprite);
//    pSprite->runAction(jumpAct);
///////////////////////////////////////////////////////////////////////animation
    
    
    
    CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Player.png", 100);
    player= new Player(hello,world);
    addChild(player);
      
    CCSpriteBatchNode *castle = CCSpriteBatchNode::create("castle.png", 100);
    base = new Base(castle,world);
    addChild(base);
    
    baseButton= new BaseButton(CCPoint(892, 580));
    addChild(baseButton);
    
    
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
   
    win2 = CCLabelTTF::create("press the exit button", "Marker Felt", 32);
    addChild(win2, 1);
    win2->setColor(ccc3(255,0,0));
    win2->setPosition(ccp(500, 320));
    win2->setOpacity(0);


    
       pCloseItem = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",this,menu_selector(HelloWorld::exitMainMenu));
        pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20,  740));
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition( CCPointZero );
        addChild(pMenu, 1);
        pCloseItem->setOpacity(0);
       
        
    scheduleUpdate();
}

HelloWorld::~HelloWorld()
{
    delete world;
    world = NULL;
    
    //delete m_debugDraw;
}
void HelloWorld::exitMainMenu(){
    
    
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
    
    int velocityIterations = 8;
    int positionIterations = 1;
    
    
   
    human->update();
    if(eManager->EnemyCount<=25){
        eManager->update();
        
    }
    else{
        
        if(eManager->enemyCurrent==0){
        
            win->setOpacity(100);
            win2->setOpacity(100);
            pCloseItem->setOpacity(100);
        }
    }
    if(player->health<=0){
        player->health=0;
        loose->setOpacity(100);
        win2->setOpacity(100);
        pCloseItem->setOpacity(100);
    
    }
    else{
        
        if(baseButton->hb->build){
            baseButton->hb->build=false;
            if(eManager->coins>=50){
                eManager->coins=eManager->coins-50;
                
                Tower *t = new Tower();
                CCSpriteBatchNode * tow= CCSpriteBatchNode::create("tower1.png", 100);
                t->initialize(tow, world,baseButton->hb->buildPoint, 20, b2Vec2(97, 67), "tower");
                addChild(t);
                towers.push_back(t);
            }
        }
        if(towers.size()!=0){
            for (int i=0; i<towers.size(); i++){
                Tower  *b = static_cast<Tower *>(towers[i]);
                b->update(world,eManager->enemys,this,world);
                
            }
        }
        
        player->update(analog->getDirection());
        eManager->destroy();
        eManager->moveEnemy(b2Vec2(player->m_pBody->GetPosition().x, player->m_pBody->GetPosition().y));
        bulletMan->update();
        
        if(analog2->getDirection().x!=0&&analog2->getDirection().y!=0){
           
            if(wep->handgun){
                if(firecount>gun->fireRate){
                    
                    
                    bulletMan->create(player->returnpos(), analog2->getDirection());
                
                    firecount=0;
                
                }
            }
            else if(wep->assaultrifle){
                if(firecount>assaultgun->fireRate){
                    
                    bulletMan->create(player->returnpos(), analog2->getDirection());
                    firecount=0;
                    
                }
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

    world->Step(dt, velocityIterations, positionIterations);

    
}
void HelloWorld::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
    
    human->ccTouchesBegan(pTouches, pEvent);
//    CCArray *allTouches =   this->allTouchesFromSet(pTouches);
//    
//    CCTouch *touch = (CCTouch*)pTouches->anyObject();
//    CCPoint point = touch->locationInView();
     
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
        
      //  addNewSpriteAtPosition( location );
        // jaime->setPosition(CCPointMake(300, 300));
        
        
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

