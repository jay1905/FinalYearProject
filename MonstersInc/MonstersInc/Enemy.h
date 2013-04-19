//
//  Enemy.h
//  MonstersInc
//
//  Created by Jaime Aughney on 05/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Enemy_h
#define MonstersInc_Enemy_h

#include "cocos2d.h"
#include "Box2D.h"
#include "Entity.h"


class Enemy: public Entity
{
public:
    Enemy(b2World* world,b2Vec2 pos,float speed);
    Enemy();
    
    void update();
    void drawStuf();
    void setPosition(b2Vec2 pos);
    b2Vec2 getPos();
   
private:
   
   
      float speed;
    
    
};

#endif
