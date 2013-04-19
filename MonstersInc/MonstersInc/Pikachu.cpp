//
//  Pikachu.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 15/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Pikachu.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Pikachu::Pikachu( b2World *world,b2Vec2 pos,float spd)
:Enemy()
{
    size=b2Vec2(19,18);
    cocos2d::CCAnimation * anim = CCAnimation::animation();
    anim->addSpriteFrameWithFileName("pikachu1.png");
    anim->addSpriteFrameWithFileName("pikachu2.png");
    anim->addSpriteFrameWithFileName("pikachu3.png");
  
    anim->setDelayPerUnit(.2f);
    CCAnimate *theAnim = cocos2d::CCAnimate::actionWithAnimation(anim);
    CCAction *jumpAct = CCRepeatForever::create(theAnim);
    cocos2d::CCSpriteBatchNode *pSprite= cocos2d::CCSpriteBatchNode::create("pikachu1.png");
    
    this->initWithFile("pikachu1.png", CCRectMake(0, 0, size.x, size.y));
    this->initialize(pSprite, world, pos, spd, size, "Enemy");
    this->CCSprite::m_pActionManager->addAction(jumpAct, this, false);
    
    
}
