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
    
        label = CCLabelTTF::create("great now you can buy a tower", "Marker Felt", 32);
        addChild(label, 1);
        label->setColor(ccc3(0,255,255));
        label->setPosition(ccp( 755, 490));

        label2 = CCLabelTTF::create("touch the castle!", "Marker Felt", 32);
        addChild(label2, 1);
        label2->setColor(ccc3(0,255,255));
        label2->setPosition(ccp( 770, 460));
        
        label4 = CCLabelTTF::create("exit", "Marker Felt", 32);
        addChild(label4, 1);
        label4->setColor(ccc3(200,255,200));
        label4->setPosition(ccp( 965, 740));
    
    
        label5 = CCLabelTTF::create("try killing the enemy", "Marker Felt", 32);
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
    
    label10 = CCLabelTTF::create("touch the turret", "Marker Felt", 32);
    addChild(label10, 1);
    label10->setColor(ccc3(0,255,255));
    label10->setPosition(ccp(790, 550));
    
    label11 = CCLabelTTF::create("now touch where you want it", "Marker Felt", 32);
    addChild(label11, 1);
    label11->setColor(ccc3(0,255,255));
    label11->setPosition(ccp(520, 335));

    label12 = CCLabelTTF::create("Great! now exit", "Marker Felt", 32);
    addChild(label12, 1);
    label12->setColor(ccc3(0,255,255));
    label12->setPosition(ccp(520, 335));
    
    label13 = CCLabelTTF::create("shoot", "Marker Felt", 32);
    addChild(label13, 1);
    label13->setColor(ccc3(0,255,255));
    label13->setPosition(ccp(915,150));
    
    label14 = CCLabelTTF::create("move", "Marker Felt", 32);
    addChild(label14, 1);
    label14->setColor(ccc3(0,255,255));
    label14->setPosition(ccp(100,150));
    
    label->setOpacity(0);
    label2->setOpacity(0);
    label10->setOpacity(0);
        label11->setOpacity(0);
        label12->setOpacity(0);
    
    
        cocos2d::CCSprite * jaime = CCSprite::create("game_background.png");
        jaime->setPosition(CCPointMake(500, 380));
        addChild(jaime);
    
        analog = new Analogue(CCPoint(100, 95));
    analog->bg->setOpacity(200);
    analog->thumb->setOpacity(200);
        this->addChild(analog);
   
    
        analog2 = new Analogue(CCPoint(s.width-100, 95));
    analog2->bg->setOpacity(200);
    analog2->thumb->setOpacity(200);
        this->addChild(analog2);
    
        CCSpriteBatchNode *hello = CCSpriteBatchNode::create("Player.png", 100);
        player= new Player(hello,world);
        addChild(player);

        bullets=new CCArray();
        createBounds();
        fireCount=20;
    
        eMan=new EnemyManager(world, this);   
        eMan->addEnemy(b2Vec2(120,600));
    eMan->coins=45;
   
    thumb1 = CCSprite::create("thum1.png");
    thumb1->setPosition(CCPointMake(120, 100));
    thumb1->setOpacity(70);
    addChild(thumb1);
    
    thumb2 = CCSprite::create("thum2.png");
    thumb2->setPosition(CCPointMake(920, 100));
    thumb2->setOpacity(70);
    addChild(thumb2);
    
    
    
    base = new Base(world);
    addChild(base);
    
    baseButton= new BaseButton(CCPoint(892, 580));
    addChild(baseButton);

   
    builed=false;
    
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
    
    if( eMan->coins>50){
        
        
        label->setOpacity(100);
        label2->setOpacity(100);
        label5->setOpacity(0);
        
        
    }
//    if(baseButton->castleTouch==true){
//        
//        label->setOpacity(0);
//        label2->setOpacity(0);
//        label10->setOpacity(100);
//    
//    }
    if(baseButton->hb->buttontouch==true){
        
          label10->setOpacity(0);
          label11->setOpacity(100);
        
    }
    if(builed==true){
        
         label11->setOpacity(0);
         label12->setOpacity(100);
    }
    
    
    
    if(analog2->getDirection().x!=0&&analog2->getDirection().y!=0){
//        if(wep->handgun){
//            if(fireCount>gun->fireRate){
//                bulletSprite=CCSpriteBatchNode::create("Bullet.png", 100);
//                addChild(bulletSprite);
//                Bullet *b = new Bullet(bulletSprite,world,player->returnpos());
//                b->fire(analog2->getDirection());
//                bulletSprite->addChild(b);
//                bullets->addObject(b);
//                fireCount=0;
//                
//            }
//        }
       // else if(wep->assaultrifle){
//            if(fireCount>assaultgun->fireRate){
//                bulletSprite=CCSpriteBatchNode::create("Bullet.png", 100);
//                addChild(bulletSprite);
//                Bullet *b = new Bullet(bulletSprite,world,player->returnpos());
//                b->fire(analog2->getDirection());
//                bulletSprite->addChild(b);
//                bullets->addObject(b);
//                fireCount=0;
//                
//            }
        //}
        fireCount++;
        if(analog2->getDirection().x<0){
            player->setFlipX(false);
        }
        else{
            player->setFlipX(true);
        }
    }
//    if(bullets->count()!=0){
//        for (int i=0; i<bullets->count(); i++){
//            Bullet  *b = static_cast<Bullet *>(bullets->objectAtIndex(i));
//            b->update();
//            if(b->timetolive > 60*2){
//                bullets->removeObjectAtIndex(i);
//                world->DestroyBody(b->m_pBody);
//                b->removeChild(b, true);
//            }
//        }
//    }
//    if(baseButton->hb->build){
//        baseButton->hb->build=false;
//        if(eMan->coins>=50){
//            eMan->coins=eMan->coins-50;
//            builed=true;
//            Tower *t = new Tower();
//            CCSpriteBatchNode * tow= CCSpriteBatchNode::create("tower1.png", 100);
//            t->initialize(tow, world,baseButton->hb->buildPoint, 20, b2Vec2(97, 67), "tower");
//            
//            addChild(t);
//            towers.push_back(t);
//        }
//    }
//    if(towers.size()!=0){
//        for (int i=0; i<towers.size(); i++){
//            Tower  *b = static_cast<Tower *>(towers[i]);
//            b->update(world,eMan->enemys,this);
//            
//        }
//    }

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