//
//  BulletManager.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 28/02/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "BulletManager.h"

using namespace cocos2d;


BulletManager::BulletManager( b2World* w){
    
  bullets=new CCArray();
    world=w;
    
}
void BulletManager::update(){
    
    
    if(bullets->count()!=0){
        for (int i=0; i<bullets->count(); i++){
            Bullet  *b = static_cast<Bullet *>(bullets->objectAtIndex(i));
            b->update();
            if(b->timetolive > 60*2){
                bullets->removeObjectAtIndex(i);
                world->DestroyBody(b->m_pBody);
                b->removeChild(b, true);
            }
        }
    }

    
    
}
void BulletManager::create(b2Vec2 pos,b2Vec2 direction){
    
    bulletSprite=CCSpriteBatchNode::create("Bullet.png", 100);
    addChild(bulletSprite);
    Bullet *b = new Bullet(bulletSprite,world,pos);
    b->fire(direction);
    bulletSprite->addChild(b);
    bullets->addObject(b);
    
    
}