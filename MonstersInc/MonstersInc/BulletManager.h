//
//  BulletManager.h
//  MonstersInc
//
//  Created by Jaime Aughney on 28/02/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_BulletManager_h
#define MonstersInc_BulletManager_h

#include "cocos2d.h"
#include "Bullet.h"
#include "Box2D.h"

class BulletManager: public cocos2d::CCLayer{
    
    
private:
    
    
    cocos2d::CCArray *bullets;
    cocos2d::CCSpriteBatchNode *bulletSprite;
    int firecount;
    b2World* world;
    
public:
     BulletManager( b2World* world);
    void update();
   
    void create(b2Vec2 pos,b2Vec2 direction,int );
    
};

#endif
