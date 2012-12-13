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
    void addEnemy(b2Vec2 pos);
    void addPikachu();
    void addAxeBaby();
    void moveEnemy(b2Vec2 pos);
    void destroy();
    
    
    std::vector<Enemy*> enemys;
    int coins;
    int EnemyCount;
    int enemyCurrent;
    
private:
    
    b2World * world;
    cocos2d::CCLayer * layer;
    int count;
    
    
    
};


#endif
