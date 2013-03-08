//
//  Human.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 07/01/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Human.h"
#define SQUARE_WIDTH 19.0f
#define SQUARE_HEIGHT 23.0f

using namespace cocos2d;
static CCPoint convertCoordinate(CCPoint point){
    return CCDirector::sharedDirector()->convertToGL(point);
}
static bool isPointInSquare(CCPoint point, b2Vec2 pos){
    pos.x-=SQUARE_WIDTH/2;
    pos.y+=SQUARE_HEIGHT/2;
    if(point.x>pos.x&&point.x<pos.x+(SQUARE_WIDTH)){
        
        
        if(point.y<pos.y&&point.y>pos.y-(SQUARE_HEIGHT)){
            
            return true;
        }
        
    }
    return false;
}
Human::Human(b2World* world, b2Vec2 pos, float speed, b2Vec2 size, cocos2d::CCLayer * layer){
    
   
    
    CCSpriteBatchNode * ash= CCSpriteBatchNode::create("ash1.png", 100);
    initialize(ash, world, pos, speed, size, "human");
    mainLayer=layer;
    height=size.y;
    width =size.x;
    position=pos;
    isSelected=false;
    direction=b2Vec2_zero;
   
}


void Human::update(){
        
    this->m_pBody->SetLinearVelocity(direction);
    position=this->m_pBody->GetPosition();
    position*=32;
    if(position.x>destination.x-20&&position.x<destination.x+20){
            
        if(position.y>destination.y-20&&position.y<destination.y+20){
        
            direction= b2Vec2_zero;
        
        }
        
    }
    
}
void Human::move( CCPoint point){
    
    destination=point;
    direction=b2Vec2(point.x-position.x,point.y-position.y);
    direction.Normalize();
    direction=b2Vec2(direction.x*speed, direction.y*speed);
    
    
}
void Human::build(){
    
    
}
void Human::defend(){
    
}
void Human::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
        
    CCTouch *touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->locationInView();
    point = convertCoordinate(point);
    if (isSelected) {
        move(point);
        isSelected=false;
    }
    else{
        if(isPointInSquare(point,position)){
       
            isSelected=true;
        
        }
    }
   
}
CCArray* Human::allTouchesFromSet(CCSet *touches)
{
    CCArray *arr = new CCArray;
    CCSetIterator it;
	for( it = touches->begin(); it != touches->end(); it++) 
    {
        arr->addObject((CCTouch *)*it);
    }
    return arr;
}