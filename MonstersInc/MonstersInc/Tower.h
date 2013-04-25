//
//  Tower.h
//  MonstersInc
//
//  Created by Jaime Aughney on 07/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Tower_h
#define MonstersInc_Tower_h

#include "cocos2d.h"
#include "StaticEntity.h"
#include "Bullet.h"
#include "Enemy.h"

class Tower: public StaticEntity
{
    
public:
    
    Tower();
    void move();
    void Shoot(cocos2d::CCLayer *,b2World* , b2Vec2 );
    void update(b2World* world, std::vector<Enemy*>,cocos2d::CCLayer* lay);
    bool builed;
private:
    
    float damage;
    float range;
    cocos2d::CCSpriteBatchNode *bulletSprite;
    int  firecount;
    int  fireRate;
    cocos2d::CCArray *bullets;

    
};

#endif
