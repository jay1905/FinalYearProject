//
//  EnemyManager.h
//  MonstersInc
//
//  Created by Jaime Aughney on 10/12/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_EnemyManager_h
#define MonstersInc_EnemyManager_h

#include "cocos2d.h"
#include "Enemy.h"


class EnemyManager
{
    
public:
    
    
    EnemyManager(b2World*  world,cocos2d::CCLayer * layer);
    
    
    void update();
    void addEnemy();
    void addPikachu();
    void addAxeBaby();
    
    
    
    std::vector<Enemy*> enemys;
    
    
private:
    
    b2World * world;
    cocos2d::CCLayer * layer;
    
    
};


#endif
