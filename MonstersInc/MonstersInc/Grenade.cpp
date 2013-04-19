//
//  Grenade.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 11/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include <iostream>
#include "Grenade.h"

using namespace cocos2d;

Grenade::Grenade(){
    
    
    grenade = CCSpriteBatchNode::create("grenade.png", 100);
    shrapnelSprite = CCSpriteBatchNode::create("shrapnel.png", 100);
    
    //shrapnelDirection=new CCArray();
    time=0;
    timeToLive=1.50;
    numShrapnel=360;
}
void Grenade::initializeGrenade(b2World* w,b2Vec2 pos)
{
    this->initialize(grenade, world, pos, 0, b2Vec2(256, 768), "Grenade");
    world=w;
    position=CCPoint(pos.x, pos.y);
}
void Grenade::initializeShrapnel(b2World* w,b2Vec2 pos){
    
    this->initialize(shrapnelSprite, world, pos, 0, b2Vec2(10, 10), "shrapnel");
    world=world;
    position=CCPoint(pos.x, pos.y);
    
}
void Grenade::move(b2Vec2  velocity){
    
    m_pBody->SetLinearVelocity(velocity);
    
}
void Grenade::update(){
    
    
 	if(time>timeToLive){
 		
 		for (int i=0;i<numShrapnel;i++){
            
            
 			Grenade *g = new Grenade();
 			g->initializeShrapnel(world,b2Vec2(position.x, position.y));
 			g->move(shrapnelDirection[i]);
 			shrapnel.push_back(g);
            
 			
            
 		}
 	}
    
 	time+=0.1;
}
