//
//  Bullet.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 06/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Bullet.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Bullet::Bullet(cocos2d::CCSpriteBatchNode *hello,b2World* world,b2Vec2 pos){
    
    
    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, 11, 7));
    this->autorelease();
    bodyDef.type=b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);
    body=world->CreateBody(&bodyDef);
    float x=11/32;
    float y = 7/32;
    dynamicBox.SetAsBox(.2, .2);
    fixyureDef.shape=&dynamicBox;
    fixyureDef.density=1.0f;
    fixyureDef.friction=2.0f;
    body->CreateFixture(&fixyureDef);
    this->setPhysicsBody(body);
    speed = 30;
    timetolive=60;
    
}
void Bullet::update(b2Vec2 direction){
    
    direction=b2Vec2(direction.x*speed,direction.y*speed);
    this->m_pBody->SetLinearVelocity(direction);
    
}
void Bullet::drawStuf(){
    
    
    
}