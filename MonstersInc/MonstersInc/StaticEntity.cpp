//
//  StaticEntity.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 17/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "StaticEntity.h"
using namespace cocos2d;

StaticEntity::StaticEntity(){
    
    
    
    
}
void StaticEntity::initialize(cocos2d::CCSpriteBatchNode *hello,b2World *world,b2Vec2 pos,float spd,b2Vec2 size,  std::string Name){
    
    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, size.x, size.y));
    this->autorelease();
    bodyDef.type=b2_staticBody;
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
    
    
    fixyureDef.filter.groupIndex = -1; 
    fixyureDef.filter.categoryBits=12;
    
    body->CreateFixture(&fixyureDef);
    this->setPhysicsBody(body);
    speed =spd;
    body->SetUserData(this);
    
}
