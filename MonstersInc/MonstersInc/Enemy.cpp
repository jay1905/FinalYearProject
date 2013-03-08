//
//  Enemy.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 05/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Enemy.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Enemy::Enemy(cocos2d::CCSpriteBatchNode *hello,b2World *world,b2Vec2 pos,float spd,b2Vec2 size){
    

    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, size.x, size.y));
    this->autorelease();
    bodyDef.type=b2_dynamicBody;
    bodyDef.position.Set(pos.x/32,pos.y/32);
    name="Enemy";
    health= 100;
    body=world->CreateBody(&bodyDef);
    
    float x=size.x/32;
    float y =size.y/32;
    dynamicBox.SetAsBox(x/1.8, y/1.8);
    fixyureDef.shape=&dynamicBox;
    fixyureDef.density=0.0f;
    fixyureDef.friction=0.0f;
     fixyureDef.filter.groupIndex = -2; 
    body->CreateFixture(&fixyureDef);
    this->setPhysicsBody(body);
    speed =spd;
    body->SetUserData(this);
       

}
void Enemy::move(b2Vec2 playerPos){
    
 
    b2Vec2 dir = b2Vec2(m_pBody->GetPosition().x-playerPos.x, m_pBody->GetPosition().y-playerPos.y);
    dir.Normalize();
    this->m_pBody->SetLinearVelocity(b2Vec2(-dir.x*speed, -dir.y*speed));
   
    
}

void Enemy::update(){
    
    
    
}
void Enemy::drawStuf(){
    
    
    
 
    
}
void Enemy::setPosition(b2Vec2 pos){
    
    
   
    
    
    
}
b2Vec2 Enemy::getPos(){
    
    
    
    return m_pBody->GetPosition();
}