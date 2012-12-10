//
//  EnemyManager.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 10/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "EnemyManager.h"

using namespace cocos2d;

EnemyManager::EnemyManager(b2World* w,cocos2d::CCLayer* lay){
    
    world= w;
    layer = lay;
    
    
}
void EnemyManager::update(){
    
    for(int i = 0; i<enemys.size();i++){
        
        if(enemys[i]->health<=0){
            
            world->DestroyBody(enemys[i]->m_pBody);
            //enemys[i]->removeChild(enemys[i], true);
            layer->removeChild(enemys[i], true);
            enemys.erase(enemys.begin()+i);
            
        }
        
        
    }
    
    
}
void EnemyManager::addEnemy(){
    
   
    CCSpriteBatchNode *enemy1 = CCSpriteBatchNode::create("GreenZombie1.png", 100);
    Enemy * enemy = new Enemy(enemy1,world,b2Vec2(10, 10),1,b2Vec2(59,64));
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
}
void EnemyManager::addPikachu(){
    
    
    CCSpriteBatchNode *enemy1 = CCSpriteBatchNode::create("pikachu1.png", 100);
    Enemy * enemy = new Enemy(enemy1,world,b2Vec2(10, 11),1.75,b2Vec2(19,18));
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
    
}
void EnemyManager::addAxeBaby(){
    
    CCSpriteBatchNode *enemy1 = CCSpriteBatchNode::create("axeBaby1.png", 100);
    Enemy * enemy = new Enemy(enemy1,world,b2Vec2(10, 12),1,b2Vec2(11,30));
    layer->addChild(enemy);
    enemys.push_back(enemy);
    
    
}