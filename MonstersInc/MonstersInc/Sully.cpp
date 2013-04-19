//
//  Sully.cpp
//  MonstersInc
//
//  Created by Jaime Aughney on 15/04/2013.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Sully.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Sully::Sully( b2World *world,b2Vec2 pos,float spd)
:Enemy()
{
     size=b2Vec2(56,53);
    cocos2d::CCAnimation * anim = CCAnimation::animation();
    anim->addSpriteFrameWithFileName("skully1.png");
    anim->addSpriteFrameWithFileName("skully2.png");
    anim->addSpriteFrameWithFileName("skully3.png");
    anim->addSpriteFrameWithFileName("skully4.png");
    anim->addSpriteFrameWithFileName("skully5.png");
    anim->addSpriteFrameWithFileName("skully6.png");
    anim->addSpriteFrameWithFileName("skully7.png");
    anim->addSpriteFrameWithFileName("skully8.png");
  
    
    anim->setDelayPerUnit(.1f);
    CCAnimate *theAnim = cocos2d::CCAnimate::actionWithAnimation(anim);
    CCAction *jumpAct = CCRepeatForever::create(theAnim);
    cocos2d::CCSpriteBatchNode *pSprite= cocos2d::CCSpriteBatchNode::create("skully1.png");
    
    this->initWithFile("skully1.png", CCRectMake(0, 0, size.x, size.y));
    this->initialize(pSprite, world, pos, spd, size, "Enemy");
    this->CCSprite::m_pActionManager->addAction(jumpAct, this, false);
    
    
}
