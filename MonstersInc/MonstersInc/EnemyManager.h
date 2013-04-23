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
#include "Box2D.h"
#include "AxeBaby.h"
#include "Pikachu.h"
#include "Sully.h"
#include "Metroid.h"


class EnemyManager
{
    
public:
    
    
    EnemyManager(b2World* ,cocos2d::CCLayer * );
    
    
    void update();
    void addEnemy(b2Vec2 pos);
    void addPikachu(b2Vec2 pos);
    void addAxeBaby(b2Vec2 pos);
    void addSully(b2Vec2 pos);
    void addMetroid(b2Vec2 pos);
    void moveEnemy(b2Vec2 pos);
    void destroy();
    void setEnemiesToBeAdded( int enemies[],float minSpawn,float maxSpawn);
    void setPath(  std::vector<b2Vec2*>);
    void movePath();
    
    std::vector<Enemy*> enemys;
    int coins;
    int EnemyCount;
    int enemyCurrent;
    int spawn;
    int enemiesToBeAdded[5];
    bool levelCompleted;
    bool towerLevel;
    int totalEnemys;
    
    
private:
    
    b2World * world;
    cocos2d::CCLayer * layer;
    int count;
    int minSpawn;
    int maxSpawn;
    int addcount;
    std::vector<b2Vec2 *> path;
  
     
       
    
};


#endif
