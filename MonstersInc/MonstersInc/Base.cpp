//
//  Base.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 06/11/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Base.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


Base::Base(cocos2d::CCSpriteBatchNode *hello,b2World* world){
    
    
    this->initWithTexture(hello->getTexture(), CCRectMake(0, 0, 404, 134));
    //this->autorelease();
    bodyDef.type=b2_staticBody;
    bodyDef.position.Set(15, 15);
    body=world->CreateBody(&bodyDef);
    body->SetTransform(b2Vec2(30, 12), -1.56);
    name="base";
    float x=404/32;
    float y = 134/32;
    dynamicBox.SetAsBox(x/1.8, y/1.8);
    fixyureDef.shape=&dynamicBox;
    fixyureDef.density=1.0f;
    fixyureDef.friction=2.0f;
    body->CreateFixture(&fixyureDef);
    body->SetUserData(this);
    this->setPhysicsBody(body);
    
   


    
}
void Base::update(b2Vec2 direction){
    
    this->m_pBody->SetLinearVelocity(direction);
    
}
void Base::drawStuf(){
    
    
    
}