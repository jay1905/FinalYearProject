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

Enemy::Enemy(cocos2d::CCSpriteBatchNode *hello,b2World *world){
    

    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, 59, 64));
    this->autorelease();
    bodyDef.type=b2_dynamicBody;
    bodyDef.position.Set(15, 15);
    body=world->CreateBody(&bodyDef);
    float x=59/32;
    float y = 64/32;
    dynamicBox.SetAsBox(x/1.8, y/1.8);
    fixyureDef.shape=&dynamicBox;
    fixyureDef.density=1.0f;
    fixyureDef.friction=2.0f;
    body->CreateFixture(&fixyureDef);
    this->setPhysicsBody(body);
       

}
void Enemy::move(b2Vec2 direction){
    
    this->m_pBody->SetLinearVelocity(direction);
    
}
void Enemy::update(){
    
    
    
}
void Enemy::drawStuf(){
    
    
    
 
    
}