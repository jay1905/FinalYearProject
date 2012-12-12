//
//  Tutorial.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 11/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Tutorial.h"
#include "SimpleAudioEngine.h"
#include "MainMenu.h"


using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 32

Tutorial::Tutorial(){
    
    init();
    
    
}
void Tutorial::init(){
    
    
        s = CCDirector::sharedDirector()->getWinSize();
    
        pCloseItem = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",this,menu_selector(Tutorial::exit));
        pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition( CCPointZero );
        addChild(pMenu, 1);
        
        world = new b2World(b2Vec2_zero);
        world->SetAllowSleeping(true);
        world->SetContinuousPhysics(true);
    
        label = CCLabelTTF::create("touch here to move", "Marker Felt", 32);
        addChild(label, 1);
        label->setColor(ccc3(0,0,255));
        label->setPosition(ccp( 125, 90));

        label2 = CCLabelTTF::create("touch here to shoot", "Marker Felt", 32);
        addChild(label2, 1);
        label2->setColor(ccc3(0,0,255));
        label2->setPosition(ccp( 900, 90));
    
    
        cocos2d::CCSprite * jaime = CCSprite::create("game_background.png");
        jaime->setPosition(CCPointMake(500, 380));
        addChild(jaime);
    
        analog = new Analogue(CCPoint(100, 95));
        this->addChild(analog);
    
        analog2 = new Analogue(CCPoint(s.width-100, 95));
        this->addChild(analog2);
    
        CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Player.png", 100);
        player= new Player(hello,world);
        addChild(player);

        bullets=new CCArray();
        createBounds();
    
        scheduleUpdate();

}
void Tutorial::createBounds(){
    
    
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
void Tutorial::exit(){
    
    
    CCScene *pScene1= MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);
    
}
void Tutorial::update(float dt){
    
    int velocityIterations = 8;
    int positionIterations = 1;

    player->update(analog->getDirection());
    
    if(analog2->getDirection().x!=0&&analog2->getDirection().y!=0){
        bulletSprite=CCSpriteBatchNode::create("Bullet.png", 100);
        addChild(bulletSprite);
        Bullet *b = new Bullet(bulletSprite,world,player->returnpos());
        b->fire(analog2->getDirection());
        bulletSprite->addChild(b);
        bullets->addObject(b);
    }
    if(bullets->count()!=0){
        for (int i=0; i<bullets->count(); i++){
            Bullet  *b = static_cast<Bullet *>(bullets->objectAtIndex(i));
            b->update(player->m_pBody);
            if(b->timetolive > 60*2){
                bullets->removeObjectAtIndex(i);
                world->DestroyBody(b->m_pBody);
                b->removeChild(b, true);
            }
        }
    }
    
    world->Step(dt, velocityIterations, positionIterations);
    
    
}
CCScene* Tutorial::scene()
{
    CCScene *scene = CCScene::create();
    CCLayer* layer = new Tutorial();
    scene->addChild(layer);
    layer->release();
    return scene;
}