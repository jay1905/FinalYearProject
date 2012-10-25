//
//  Player.h
//  MonstersInc
//
//  Created by Jaime Aughney on 22/10/2012.
//  Copyright (c) 2012 __MonstersInc__. All rights reserved.
//

#ifndef MonstersInc_Player_h
#define MonstersInc_Player_h

#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"



class Player: public PhysicsSprite
{
public:
    Player(cocos2d::CCLayer *layer);
    
    
    void update();
    void drawStuf();

private:
  
    cocos2d::CCTexture2D* JaimeTexture;
  //PhysicsSprite *jaimeSprite;
    cocos2d::CCSprite* pSprite;
    cocos2d::CCSprite* test;

    b2World* world;
    cocos2d::CCLayer *lay;


};

#endif
