//
//  Player.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 22/10/2012.
//  Copyright (c) 2012 __MonstersInc__. All rights reserved.
//

#include <iostream>
#include "Player.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Player::Player(cocos2d::CCSpriteBatchNode *hello,b2World* world){
    
   
    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, 54, 44));
    this->autorelease();
    bodyDef.type=b2_dynamicBody;
    bodyDef.position.Set(15, 15);
    body=world->CreateBody(&bodyDef);
    float x=54/32;
    float y = 44/32;
    dynamicBox.SetAsBox(x/1.8, y/1.8);
    fixyureDef.shape=&dynamicBox;
    fixyureDef.density=1.0f;
    fixyureDef.friction=2.0f;
    body->CreateFixture(&fixyureDef);
    this->setPhysicsBody(body);
    
}
void Player::update(b2Vec2 direction){
    
     this->m_pBody->SetLinearVelocity(direction);

}
void Player::drawStuf(){
    

    
}