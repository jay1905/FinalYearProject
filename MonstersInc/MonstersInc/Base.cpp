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


Base::Base(b2World* world){
    
    
    
    
    castle = CCSpriteBatchNode::create("castle.png", 100);
    
    this->initialize(castle, world, b2Vec2 (500,500), 0, b2Vec2 (404,134),"base");

   this->m_pBody->SetTransform(b2Vec2(30, 12), -1.56);

    
}
void Base::update(b2Vec2 direction){
    
    this->m_pBody->SetLinearVelocity(direction);
    
}
void Base::drawStuf(){
    
    
    
}