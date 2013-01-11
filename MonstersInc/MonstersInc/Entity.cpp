//
//  Creature.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 07/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Entity.h"


using namespace cocos2d;

Entity::Entity(){
    
   
    
    
}
void Entity::initialize(cocos2d::CCSpriteBatchNode *hello,b2World *world,b2Vec2 pos,float spd,b2Vec2 size,  std::string Name){
    
    
    
    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, size.x, size.y));
    this->autorelease();
    bodyDef.type=b2_dynamicBody;
    bodyDef.position.Set(pos.x/32,pos.y/32);
    name=Name;
    health= 100;
    body=world->CreateBody(&bodyDef);
    
    float x=size.x/32;
    float y =size.y/32;
    dynamicBox.SetAsBox(x/1.8, y/1.8);
    fixyureDef.shape=&dynamicBox;
    fixyureDef.density=0.0f;
    fixyureDef.friction=0.0f;
    
    body->CreateFixture(&fixyureDef);
    this->setPhysicsBody(body);
    speed =spd;
    body->SetUserData(this);
    
    
    
    
}
