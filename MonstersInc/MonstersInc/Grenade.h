//
//  Grenade.h
//  MonstersInc
//
//  Created by Jaime Aughney on 11/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Grenade_h
#define MonstersInc_Grenade_h

#include "cocos2d.h"
#include "Box2D.h"
#include "Entity.h"
#include "Player.h"
#include "EnemyManager.h"

class Grenade:public Entity
{
    
public:
    Grenade();
    void update();
    void move(b2Vec2 );
    void initializeGrenade(b2World* world,b2Vec2 pos);
    void initializeShrapnel(b2World* world,b2Vec2 pos);
    
    
private:
    b2World* world;
    float timeToLive;
    float time;
    cocos2d::CCPoint velocity;
    cocos2d::CCPoint position;
    cocos2d::CCSpriteBatchNode *grenade;
    cocos2d::CCSpriteBatchNode *shrapnelSprite;
    int numShrapnel;
    std::vector<Grenade*> shrapnel;
    
   b2Vec2 shrapnelDirection[200];
};

#endif
