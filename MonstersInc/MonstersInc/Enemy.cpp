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

Enemy::Enemy( b2World *world,b2Vec2 pos,float spd){
    
    size= b2Vec2(59,64);
    cocos2d::CCAnimation * anim = CCAnimation::animation();
    anim->addSpriteFrameWithFileName("GreenZombie1.png");
    anim->addSpriteFrameWithFileName("GreenZombie2.png");
    anim->addSpriteFrameWithFileName("GreenZombie3.png");
    anim->addSpriteFrameWithFileName("GreenZombie4.png");
    anim->setDelayPerUnit(.2f);
    CCAnimate *theAnim = cocos2d::CCAnimate::actionWithAnimation(anim);
    CCAction *jumpAct = CCRepeatForever::create(theAnim);
    cocos2d::CCSpriteBatchNode *pSprite= cocos2d::CCSpriteBatchNode::create("GreenZombie1.png");
  
    this->initWithFile("GreenZombie1.png", CCRectMake(0, 0, size.x, size.y));
    this->initialize(pSprite, world, pos, spd, size, "Enemy");
    this->CCSprite::m_pActionManager->addAction(jumpAct, this, false);


}
Enemy::Enemy(){
    
      
    
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