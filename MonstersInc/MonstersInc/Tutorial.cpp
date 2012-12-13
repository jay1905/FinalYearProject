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
        pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 740));
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition( CCPointZero );
        addChild(pMenu, 1);
        
        world = new b2World(b2Vec2_zero);
        world->SetAllowSleeping(true);
        world->SetContinuousPhysics(true);
    
        label = CCLabelTTF::create("touch and move to move", "Marker Felt", 32);
        addChild(label, 1);
        label->setColor(ccc3(0,255,255));
        label->setPosition(ccp( 155, 90));

        label2 = CCLabelTTF::create("touch and move to shoot", "Marker Felt", 32);
        addChild(label2, 1);
        label2->setColor(ccc3(0,255,255));
        label2->setPosition(ccp( 870, 90));
    
    
        label3 = CCLabelTTF::create("click exit when your ready", "Marker Felt", 32);
        addChild(label3, 1);
        label3->setColor(ccc3(200,255,200));
        label3->setPosition(ccp( 470, 320));
    
        label4 = CCLabelTTF::create("exit", "Marker Felt", 32);
        addChild(label4, 1);
        label4->setColor(ccc3(200,255,200));
        label4->setPosition(ccp( 965, 740));
    
    
        label5 = CCLabelTTF::create("try shooting the enemy", "Marker Felt", 32);
        addChild(label5, 1);
        label5->setColor(ccc3(0,255,255));
        label5->setPosition(ccp( 165, 645));

    label6 = CCLabelTTF::create("health:", "Marker Felt", 32);
    addChild(label6, 1);
    label6->setColor(ccc3(0,0,255));
    label6->setPosition(ccp( 60, 745));
    
    label7 = CCLabelTTF::create("100", "Marker Felt", 32);
    addChild(label7, 1);
    label7->setColor(ccc3(255,0,55));
    label7->setPosition(ccp( 130, 745));
   
    label8 = CCLabelTTF::create("Coins:", "Marker Felt", 32);
    addChild(label8, 1);
    label8->setColor(ccc3(0,0,255));
    label8->setPosition(ccp( 260, 745));
    
    label9 = CCLabelTTF::create("0", "Marker Felt", 32);
    addChild(label9, 1);
    label9->setColor(ccc3(255,255,55));
    label9->setPosition(ccp(315, 745));
    
    label10 = CCLabelTTF::create("when you kill enemys you get coins", "Marker Felt", 32);
    addChild(label10, 1);
    label10->setColor(ccc3(255,255,55));
    label10->setPosition(ccp(440, 710));
    
    label11 = CCLabelTTF::create("the enemy will chase you and attack you", "Marker Felt", 32);
    addChild(label11, 1);
    label11->setColor(ccc3(255,0,0));
    label11->setPosition(ccp(275, 555));

    label12 = CCLabelTTF::create("you will loose health and eventually die", "Marker Felt", 32);
    addChild(label12, 1);
    label12->setColor(ccc3(255,0,0));
    label12->setPosition(ccp(265, 525));
    label13 = CCLabelTTF::create("analogues wont be visible at first in game", "Marker Felt", 32);
    addChild(label13, 1);
    label13->setColor(ccc3(20,200,200));
    label13->setPosition(ccp(515,50));
    label14 = CCLabelTTF::create("only visible after touched", "Marker Felt", 32);
    addChild(label14, 1);
    label14->setColor(ccc3(20,200,200));
    label14->setPosition(ccp(515,20));
    


    
    
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
        gun= new Gun();
        fireCount=20;
    
        eMan=new EnemyManager(world, this);   
        eMan->addEnemy(b2Vec2(120,600));
    
    
        world->SetContactListener(&mycontact);
    count=0;
    
        scheduleUpdate();

}
void Tutorial::createBounds(){
    
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0); // bottom-left corner
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
void Tutorial::exit(){
    
    
    CCScene *pScene1= MainMenu::scene();
    CCDirector::sharedDirector()->replaceScene(pScene1);
    
}
void Tutorial::update(float dt){
    
    int velocityIterations = 8;
    int positionIterations = 1;

    player->update(analog->getDirection());
    eMan->destroy();
    analog->thumb->setOpacity(50);
    analog2->bg->setOpacity(50); 
    analog2->thumb->setOpacity(50);
    analog->bg->setOpacity(50);
    
    char ttt[100];
    snprintf(ttt, 100, "%i",eMan->coins);
       
    label9->setString(ttt);
    if(eMan->enemys.size()==0){
        
        
        if(count>200){
            
            
            eMan->addEnemy(b2Vec2(120, 600));
            count = 0;
        }
        
        count++;
        
    }
    
    
    if(analog2->getDirection().x!=0&&analog2->getDirection().y!=0){
        if(fireCount>gun->fireRate){

        bulletSprite=CCSpriteBatchNode::create("Bullet.png", 100);
        addChild(bulletSprite);
        Bullet *b = new Bullet(bulletSprite,world,player->returnpos());
        b->fire(analog2->getDirection());
        bulletSprite->addChild(b);
        bullets->addObject(b);
            fireCount=0;
        }
        fireCount++;
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