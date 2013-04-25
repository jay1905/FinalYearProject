//
//  Tower.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 07/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Tower.h"

using namespace cocos2d;


Tower::Tower(){
    
    fireRate=14;
    bullets=new CCArray();
    range = 5;
    builed=true;
}



void Tower::move(){
    
    
    
}
void Tower::update(b2World* world, std::vector<Enemy*> enemys,cocos2d::CCLayer* lay){
    
    
     for(int i = 0; i<enemys.size();i++){  
         b2Vec2 len = enemys[i]->getPos()-m_pBody->GetPosition();
         float length=sqrt(len.x*len.x +len.y*len.y);  
         if(length<range){
             Shoot(lay, world, len);
         }
     }

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
void Tower::Shoot(cocos2d::CCLayer* lay ,b2World* world, b2Vec2 dir){
    
    if(firecount> fireRate){
        
        bulletSprite=CCSpriteBatchNode::create("Bullet.png", 100);
        lay->addChild(bulletSprite);
        Bullet *b = new Bullet(bulletSprite,world,m_pBody->GetPosition());
  
        b->fire(dir);
   
        bulletSprite->addChild(b);
   
        bullets->addObject(b);
  
        firecount=0;
    }
    firecount++;
    
}