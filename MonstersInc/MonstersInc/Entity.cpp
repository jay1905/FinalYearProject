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
    pathCount=0;
    
    isdefending=false;
    
}
void Entity::setPosition(b2Vec2 pos){
    
    
    
}
void Entity::setPath(std::vector<b2Vec2*> p){
    
    for (int i = 0; i<p.size(); i++) {
        path.push_back(p[i]);
    }
    
    
}
void Entity::walkPath(){
    
    if(pathCount< path.size()){
        
        moveTo(*path[pathCount]);
        if(arrived(m_pBody->GetPosition(),*path[pathCount])){
            
            
            pathCount++;
            
        }
        
    }
    else{
        
        this->body->SetLinearVelocity(b2Vec2(0,0));

        
    }
    
    
}
bool Entity::arrived(b2Vec2 pos, b2Vec2 destination){
    
    if(pos.x>destination.x-1&&pos.x<destination.x+1){
        
        if(pos.y>destination.y-1&&pos.y<destination.y+1){
            return true;
        }
        
    }
    return false;
               
               
}
void Entity::moveTo(b2Vec2 playerPos){
    
   
    b2Vec2 dir = b2Vec2(m_pBody->GetPosition().x-playerPos.x, m_pBody->GetPosition().y-playerPos.y);
    dir.Normalize();
    
    this->body->SetLinearVelocity(b2Vec2(-dir.x*speed, -dir.y*speed));
      
}
void Entity::defend(b2Vec2 pos){
    
    defendPos=pos;
    isdefending=true;
    
}
void Entity::update(){
    
    if(isdefending==true){
        
        if(body->GetPosition().x>defendPos.x&&body->GetPosition().x>defendPos.x+20){
            
            if(body->GetPosition().y>defendPos.y&&body->GetPosition().y>defendPos.y+20){
                
                //stop moving
                
            }
            
        }
    }
}