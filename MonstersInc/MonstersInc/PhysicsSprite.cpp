//
//  PhysicsSprite.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 22/10/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "PhysicsSprite.h"

using namespace cocos2d;
//using namespace CocosDenshion; //simple audio engine
#define PTM_RATIO 32


PhysicsSprite::PhysicsSprite()
: m_pBody(NULL)
{
    name = "object";
    dieing=false;
    health=100;
 
}

void PhysicsSprite::setPhysicsBody(b2Body * body)
{
    m_pBody = body;
}

// this method will only get called if the sprite is batched.
// return YES if the physics values (angles, position ) changed
bool PhysicsSprite::isDirty(void)
{
    return true;
}

// returns the transform matrix according the Chipmunk Body values
CCAffineTransform PhysicsSprite::nodeToParentTransform(void)
{
    b2Vec2 pos  = m_pBody->GetPosition();
    
    float x = pos.x * PTM_RATIO;
    float y = pos.y * PTM_RATIO;
    
    if ( isIgnoreAnchorPointForPosition() ) {
        x += m_tAnchorPointInPoints.x;
        y += m_tAnchorPointInPoints.y;
    }
    
    // Make matrix
    float radians = m_pBody->GetAngle();
    float c = cosf(radians);
    float s = sinf(radians);
    
    if( ! CCPoint::CCPointEqualToPoint(m_tAnchorPointInPoints, CCPointZero) ){
        x += c*-m_tAnchorPointInPoints.x + -s*-m_tAnchorPointInPoints.y;
        y += s*-m_tAnchorPointInPoints.x + c*-m_tAnchorPointInPoints.y;
    }
    
    // Rot, Translate Matrix
    m_tTransform = CCAffineTransformMake( c,  s,
                                         -s,    c,
                                         x,    y );
    
    return m_tTransform;
}
b2Body PhysicsSprite::getBody(){
    
    
    return *m_pBody;
}
void PhysicsSprite::die(){
    
    if(dieing==true){
        
        health-=1;
        
    
    }
    
    
}
void PhysicsSprite::slow(float x){
    
    speed*=x;
    
    
}