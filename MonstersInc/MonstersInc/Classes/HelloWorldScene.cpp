

//
//  HelloWorldScene.cpp
//  test
//
//  Created by Jaime Aughney on 18/10/2012.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    // init physics
    this->initPhysics();
    
    CCSpriteBatchNode *parent = CCSpriteBatchNode::create("blocks.png", 100);
    m_pSpriteTexture = parent->getTexture();
    
   addChild(parent, 0, kTagParentNode);
  
    
    
    
    analog = new Analogue(this);
   // addChild(analog);
    
    
    player= new Player(this);
    CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Zombie2.png", 100);
    addChild(hello);
    player->initWithTexture(hello->getTexture(), CCRectMake(0, 0, 103, 215));
    player->autorelease();
    hello->addChild(player);
    b2BodyDef hellobodyDef;
    hellobodyDef.type = b2_dynamicBody;
    hellobodyDef.position.Set(10,10);
    b2Body *hellobody = world->CreateBody(&hellobodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.5f, 3.2f);//These are mid points for our 1m box
    b2FixtureDef hellofixtureDef;
    hellofixtureDef.shape = &dynamicBox;    
    hellofixtureDef.density = 1.0f;
    hellofixtureDef.friction = 1.8f;
    hellobody->CreateFixture(&hellofixtureDef);
    player->setPhysicsBody(hellobody);

 
    
    
    CCSpriteBatchNode *jaimesNode = CCSpriteBatchNode::create("orange.png", 100);
    JaimeTexture = jaimesNode->getTexture();
    addChild(jaimesNode, 0, jaimesfinished);
    CCNode* jaimeparent = getChildByTag(jaimesfinished);
    jaimeSprite = new PhysicsSprite();
    jaimeSprite->initWithTexture(JaimeTexture, CCRectMake(0,0,58,59));
    jaimeSprite->autorelease();
    jaimeparent->addChild(jaimeSprite);
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(500/64, 600/64);
    b2Body *body = world->CreateBody(&bodyDef);
    b2CircleShape circle;
    circle.m_radius =0.85f;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;    
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.8f;
    body->CreateFixture(&fixtureDef);
    jaimeSprite->setPhysicsBody(body);

    
    
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(HelloWorld::move) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    
    
    addNewSpriteAtPosition(ccp(200, 200));

    
    
    
    
    
    
    
    CCLabelTTF *label = CCLabelTTF::create("Tap screen", "Marker Felt", 32);
    addChild(label, 0);
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( s.width/2, s.height-50));
    
    scheduleUpdate();
}

HelloWorld::~HelloWorld()
{
    delete world;
    world = NULL;
    
    //delete m_debugDraw;
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
    
    //     m_debugDraw = new GLESDebugDraw( PTM_RATIO );
    //     world->SetDebugDraw(m_debugDraw);
    
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    //        flags += b2Draw::e_jointBit;
    //        flags += b2Draw::e_aabbBit;
    //        flags += b2Draw::e_pairBit;
    //        flags += b2Draw::e_centerOfMassBit;
    //m_debugDraw->SetFlags(flags);
    
    
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

void HelloWorld::move(){
    
    //jaimeSprite->m_pBody->ApplyForce(b2Vec2(0, 500), b2Vec2(20, 20));
    jaimeSprite->m_pBody->ApplyTorque(700);
    
    
}
void HelloWorld::addNewSpriteAtPosition(CCPoint p)
{
    CCLOG("Add sprite %0.2f x %02.f",p.x,p.y);
    CCNode* parent = getChildByTag(kTagParentNode);
    
    //We have a 64x64 sprite sheet with 4 different 32x32 images.  The following code is
    //just randomly picking one of the images
    int idx = (CCRANDOM_0_1() > .5 ? 0:1);
    int idy = (CCRANDOM_0_1() > .5 ? 0:1);
    PhysicsSprite *sprite = new PhysicsSprite();
    sprite->initWithTexture(m_pSpriteTexture, CCRectMake(32 * idx,32 * idy,32,32));
    sprite->autorelease();
    
    parent->addChild(sprite);
    
    sprite->setPosition( CCPointMake( p.x, p.y) );
    
    // Define the dynamic body.
    //Set up a 1m squared box in the physics world
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(p.x/PTM_RATIO, p.y/PTM_RATIO);
    
    b2Body *body = world->CreateBody(&bodyDef);
    
    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(.5f, .5f);//These are mid points for our 1m box
    
    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;    
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    
    sprite->setPhysicsBody(body);
}


void HelloWorld::update(float dt)
{
    //It is recommended that a fixed time step is used with Box2D for stability
    //of the simulation, however, we are using a variable time step here.
    //You need to make an informed choice, the following URL is useful
    //http://gafferongames.com/game-physics/fix-your-timestep/
    
    int velocityIterations = 8;
    int positionIterations = 1;
    
    // Instruct the world to perform a single step of simulation. It is
    // generally best to keep the time step and iterations fixed.
    world->Step(dt, velocityIterations, positionIterations);
     //myActor->setPosition(location);
    //Iterate over the bodies in the physics world
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        // CCSprite* myActor = (CCSprite*)b->GetUserData();
        if (b->GetUserData() != NULL) {
            //Synchronize the AtlasSprites position and rotation with the corresponding body
           // CCSprite* myActor = (CCSprite*)b->GetUserData();
            //myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
            //myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
            //myActor->setPosition(location);
        }  
        
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
        
        addNewSpriteAtPosition( location );
        
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

