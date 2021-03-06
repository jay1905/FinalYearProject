//
//  Creature.h
//  MonstersInc
//
//  Created by Jaime Aughney on 07/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef MonstersInc_Creature_h
#define MonstersInc_Creature_h


#include "cocos2d.h"
#include "Box2D.h"
#include "PhysicsSprite.h"

class Entity :public PhysicsSprite
{
    
public:
    Entity();
    
    void initialize(cocos2d::CCSpriteBatchNode *hello,b2World* world,b2Vec2 pos,float speed,b2Vec2 size,  std::string name);
    b2FixtureDef fixyureDef;
    b2BodyDef bodyDef;
    float speed;
    void defend(b2Vec2 pos);
    void update();
    void moveTo(b2Vec2 playerPos);
    void walkPath();
    bool arrived(b2Vec2, b2Vec2);
    b2Vec2 size;
    void setPath(std::vector<b2Vec2*>);
    void setPosition(b2Vec2);
private:
    
    b2Body* body;
    b2PolygonShape dynamicBox;
    b2Vec2 defendPos;
    bool isdefending;
    
    cocos2d::CCAnimation * anim;    
    cocos2d::CCAnimate *theAnim ;
    std::vector<b2Vec2*> path;
    int pathCount;
    
};

#endif
